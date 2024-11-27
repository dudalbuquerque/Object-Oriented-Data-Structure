#include <stdio.h>
#include <stdbool.h>

int main(){
    //Operador & = "endereço de "
    //Operdor * = dereferencing

    int i = 1024;
    printf("valor de i = %d\n", i);
    printf("tamanho de i = %ld\n", sizeof(i));
    printf("endereço de i = %ld\n", &i);  //operador & = "endereço de "


    int *p; //declara var ponteiro para int
    p = &i;

    printf("valor de p = %ld\n",p);
    printf("tamanho de p = %ld\n", sizeof(p));
    printf("endereço de p = %ld\n", &p);  //operador & = "endereço de "

    int j = *p;
    printf("valor de j = %ld\n",j);
    printf("tamanho de j = %ld\n", sizeof(j));
    printf("endereço de j = %ld\n", &j);  //operador & = "endereço de "



    return 0;
}
