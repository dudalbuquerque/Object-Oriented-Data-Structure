#include <stdio.h>
#include <stdbool.h>

int main(){
    bool b = true; //define true 1
    printf("bool b = %d   |  size = %ld bit\n", b, sizeof(b)); 

    char c = 'c';
    printf("char c = %c   |  size = %ld bit\n", c, sizeof(c));

    int i = 1024;
    int maior_inteiro = 0b01111111111111111111111111111111;
    printf("int i = %d   |  size = %ld bit\n", i, sizeof(i));
    //maior_inteiro++;
    printf("int maior = %d\n", maior_inteiro);


    long l = 12345;
    printf("long l = %ld\n", l);

    unsigned int ui = 123;//guarda sem sinal


    float f = 3.1415f; 
    printf("float f = %f\n", f);

    return 0;
}