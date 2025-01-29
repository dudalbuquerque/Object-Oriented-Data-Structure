#include <stdio.h>
#include <stdlib.h>


int *rand_array(int n){
    int delta = 1000/n;
    int *arr = (int*)calloc(n, sizeof(int));
    arr[0] = rand()%delta;
    for (int i=1; i < n; i++){
        arr[i] = arr[i-1] + (rand() % delta);
    }
    return arr;
}
void print_array(int *arr, int n){
    printf("Array: ");
    for (int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
void revert_array(int *arr, int n){
    for(int i = 0, j = n -1; i <j; i++, j--){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    for (int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }

}

int main(){
    int N;
    while (1>N || N >100){
        printf ("Enter arry size 1 <= N <= 100: ");
        scanf("%d", &N);
    }

    int *arr = rand_array(N);

    printf("Ordem direta: ");
    print_array(arr, N);

    printf("\n");

    printf("Ordem inversa: ");
    revert_array(arr, N);

    free(arr);

    return 0;
}