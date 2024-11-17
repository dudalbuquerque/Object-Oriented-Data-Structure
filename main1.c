#include <stdio.h>
#include <stdbool.h>
#include "prime.h"

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n); 

    if (n <= 1) {
        printf("Invalid number for factorization (must be greater than 1).\n");
    }else if (np(n)){
        printf("Is prime!");
    }else {
        factorize(n);
    }

    return 0;
}
