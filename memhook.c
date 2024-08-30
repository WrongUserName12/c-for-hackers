#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>

// Function to write data to another process' memory
void write_data_to_address(pid_t pid, void *remote_addr, const void *data, size_t size) {
    struct iovec local[1];
    struct iovec remote[1];

    local[0].iov_base = (void*) data;
    local[0].iov_len = size;
    remote[0].iov_base = remote_addr;
    remote[0].iov_len = size;

    ssize_t bytes_written = process_vm_writev(pid, local, 1, remote, 1, 0);
    if (bytes_written == -1) {
        perror("process_vm_writev");
        exit(1);
    } else if (bytes_written != size) {
        fprintf(stderr, "Partial write: %ld of %zu bytes\n", bytes_written, size);
        exit(1);
    }
}

// Function to get the base address of the writable segment from /proc/<pid>/maps
void* get_base_address(pid_t pid) {
    char filename[64];
    FILE *f;
    void* base_address = NULL;
    char line[256];

    snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
    f = fopen(filename, "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, "rw-p") && strstr(line, "/var/labsstorage/home/sibidharan/c-for-hackers/helloworld")) {
            sscanf(line, "%p-%*p", &base_address);
            break;
        }
    }

    fclose(f);
    return base_address;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <offset>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    size_t offset = strtoull(argv[2], NULL, 0);  // Target offset in the remote process
    char *new_string = "Sibid";

    // Get the base address of the writable segment
    void *base_address = get_base_address(pid);
    if (base_address == NULL) {
        fprintf(stderr, "Could not find base address\n");
        return 1;
    }

    // Calculate the real address
    void *real_address = (void*)((char*)base_address + offset);

    // Write new string to the target process' memory
    write_data_to_address(pid, real_address, new_string, strlen(new_string) + 1);

    printf("Successfully wrote '%s' to address %p in process %d\n", new_string, real_address, pid);
    return 0;
}
