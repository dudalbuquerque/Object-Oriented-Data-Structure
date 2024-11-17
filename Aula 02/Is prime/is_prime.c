#include "prime.h"
#include <stdbool.h>

bool np(int a){
    int b = 2;
    while(b*b <= a){
        if (a%b==0){
            return false;
        }
        b++;
    }
    return true;
}