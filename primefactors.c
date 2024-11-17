#include <stdio.h>
#include "prime.h"

void factorize(int n) {
    int prime = 2; 
    printf("%d = ", n); 
    int first = 1; 

    while (n > 1) {
        if (n % prime == 0) {
            if (!first) {
                printf(" * "); 
            }
            printf("%d", prime);
            n /= prime;
            first = 0;
        } 
        
        else {
            do {
                prime++; 
            } while (!np(prime)); 
        }
    }
    printf("\n");
}