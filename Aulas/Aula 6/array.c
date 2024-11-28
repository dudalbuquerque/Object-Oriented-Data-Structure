#include <stdio.h>

main(){
    int arr[5];;

    for(int i=0; i<5; i++){
        arr[i] = (2*i)+1;;
    }
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);;
    }


    return 0;
}

void hckhfgkl(){
    int *arr;

    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));

    for(int i=0;i<n; i++){
        arr[i] = (2*i)+1;
    } 
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);;
    }

    free(arr); //liberar memória
}

void fixed_size_matrix(){
    int arr[5][4];

    for(int i=0; i<5;i++){
        for(int j=0; j<4; j++){
            arr[i][j] = i+j;
        }
    }

    for(int i=0; i<5;i++){
        for(int j=0; j<4; j++){
            printf(arr[i][j] + " ");
        }
        printf("\n");
    }
    return 0;
}

int main(){
    int arr[5];
    int ncols;

    printf("Enter nb of columns:");
    scanf("%d", &ncols);
    for(int i=0; i<5;i++){
        arr[i] = malloc(ncols * sizeof(int));
    }

    for(int i=0; i<5;i++){
        printf(arr[i]);
    }
    return 0;
}