#include <stdio.h>
#include <string.h>

void replace(char *subject, char search, char replace){
    for(int i=0;;i++){
        // if(*(subject+i) == search){
        //     *(subject+i) = replace;
        // }
        // if(*(subject+i) == '\0'){
        //     break;
        // }

        if(subject[i] == search){
            subject[i] = replace;
        }
        if(subject[i] == '\0'){
            break;
        }
    }
}

int main(){
    //All arrays are pointers, all pointers are arrays

    // char a[5];
    // scanf("%s", a);

    // int b;
    // scanf("%d", &b);

    char subject[] = "Hello World"; 
    printf("Addr of index 1: %p\n", &subject[0]);
    printf("Value of %p \n", subject);

    // for(int i=0; i<strlen(subject); i++){
    //     printf("Value of subject[%d] = %c \n", i, subject[i]);
    //     printf("Address of subject[%d] = %p\n", i, &subject[i]);
    // }
    // printf("-------------------------------------------\n");
    // for(int i=0; i<strlen(subject); i++){
    //     printf("Value of subject[%d] = %c \n", i, *(subject + i));
    //     printf("Address of subject[%d] = %p\n", i, subject + i);
    // }

    replace(subject, 'o', 'i');

    printf("After replacing: %s\n", subject);
}