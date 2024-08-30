#include <stdio.h>
#include <unistd.h>
#include "bool.h"
#include "weekday.h"
//int, char, float - primitive
//bool - 0 - false, 1 - true
bool is_holiday(weekday today);

int main() {
    if(is_holiday(SUN)){
        printf("Holiday \n");
    } else {
        printf("Not Holiday \n");
    }

}

bool is_holiday(today) weekday today=1; {
    switch(today) {
        case SUN:
            return true;
            break;
        case SAT:
            return true;
            break;
        default:
            return false;
    }
}