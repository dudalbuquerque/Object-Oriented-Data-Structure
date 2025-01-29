#include <stdbool.h>
#include <stdio.h>

int soma(int x, int y){
    return x + y;
}

int quadrado(int v){
    return v*v;
}

int soma_quadrado(int x, int y){
    return quadrado(x) + quadrado(y);
}

int fatorial(int x){
    if(x<= 2)return x;
    return x*fatorial(x-1);  
}

int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    

    printf("%d + %d = %d\n", a, b, soma(a, b));

    printf("%d² + %d² = %d\n",a, b, soma_quadrado(a, b));

    printf("%d! = %d\n", a, fatorial(a));

    return 0;
}