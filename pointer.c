#include <stdio.h>

int increment(int i){ //the data is duplicated into i for processing
    i = i + 1; //11
    return i;
}

void decrement(int *i){ // no new data is created instead just the pointer is stored
    *i = *i - 1;
}

int main() {
    int a = 10 b = 15; 
    int *p = &a; //initialization synatx
    int *c = p; // *(&p)

    a = increment(a); // 2 variables are used

    printf("After increment: %d\n", a); // 10
    printf("Value of a: %d\n", a); // 11

    decrement(&a); //or &a only one variable is used

    printf("After decrement: %d\n", a);
    printf("Value of a: %d\n", a); // 11

    // printf("Value of p = %p \n", p);
    // printf("Address of p = %p \n", &p);

    // printf("Value of a = %d \n", a);
    // printf("Address of a = %p \n", &a);

    // printf("Value of p = %p \n", p);
    // printf("Address of p = %p \n", &p); //this is useless

    // printf("Pointed value of p = %d \n", *p);

    // p = &a; //i change the address stored in p
    // *p = 20; //change the value in address stored in p 

    // printf("Value of p = %p \n", p);
    // printf("Address of p = %p \n", &p);

    // printf("Value of a = %d \n", a);

    // printf("Challenge: %d", *(&a));

    // printf("%d", *c);

}