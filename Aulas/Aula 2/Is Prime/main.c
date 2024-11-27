#include <stdio.h>
#include <stdbool.h>
#include "prime.h"

int main(){
    int a;
    scanf("%d", &a);
    bool result = np(a);
    if (result){
        printf("%d is prime", a);
    }
    else{
        printf("%d is not prime", a);
    }
    return 0;
}