#include <stdio.h>
#include <stdlib.h>

int  **mult_matrix(int **A, int **B, int M, int N, int P){
    int **C = calloc(N, sizeof(int*));
    for (int i = 0; i < M; i++) {   
        C[i] = calloc(P, sizeof(int));         
        for (int j = 0; j < P; j++) {        
            for (int k = 0; k < N; k++) {   
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;

}


int **create_matrix(int line, int column){
    int **Matrix = malloc(line * sizeof(int*));
    for(int i = 0; i < line; i++){
        Matrix[i] = malloc(column * sizeof(int));
        for(int j = 0; j < column; j++){
            Matrix[i][j] = rand() % 201 + (-100);
        }
    }
    return Matrix;
}

void print_matrix(int **Matrix, int line, int column){
    for(int i = 0; i < line; i++){
        for(int j = 0; j < column; j++){
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int M, N, P;
    for(int i=1; i<=3; i++){
        int n = 0;
        while(n < 2 || n > 10){
            printf("Enter a number whole between 2 and 10: ");
            scanf("%d", &n);
        }
        if(i==1){
            M = n;
        }else if(i==2){
            N = n;
        }else{
            P = n;
        }
    }
    

    int **A;
    int **B;
    int **C;
    A = create_matrix(M, N);
    B = create_matrix(N, P);

    print_matrix(A, M, N);
    printf("\n");
    print_matrix(B, N, P);
    printf("\n");
    C = mult_matrix(A, B, M, N, P);
    print_matrix(C, M, P);

    return 0;
}