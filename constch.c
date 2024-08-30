#include <stdio.h>

int main() {
    const int x = 10;  // x is a const variable
    int *ptr = &x;  // cast away the const-ness

    *ptr = 20;  // modify the value of x through ptr

    printf("x = %d\n", x);  // The value of x is now modified

    return 0;
}
