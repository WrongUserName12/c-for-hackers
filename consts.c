#include <stdio.h>

int main(){
    int i = 10; //variable 
    const int j = 20;

    int *danger = (int *)(&j); //cast-away the constness 
    *danger = 50;
    *danger = 100;

    printf("const j = %d", j);
}