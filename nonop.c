#include <stdio.h>
#include <unistd.h>


int is_holiday(int t){
    switch(t) {
        case 0: //SUNDAY
            return 1;
            break;
        case 6: // SATURDAY
            return 1; 
            break;
        default:
            return 0;
    }
}

int main() {
    if(is_holiday(2)){
        printf("Holiday \n");
    } else {
        printf("Not Holiday \n");
    }

}