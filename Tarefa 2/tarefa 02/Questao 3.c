#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y){
    int rest;
    while(rest != 0){
        rest = x % y;
        x = y;
        y = rest;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    int x, y, z, result;
    printf("Digite um numero inteiro: ");
    scanf("%i", &x);

    printf("Digite outro numero inteiro: ");
    scanf("%i", &y);

    printf("Digite outro numero inteiro: ");
    scanf("%i", &z);
    
    result = mdc(x, y);
    printf("Resultado: ");
    printf("%i", mdc(result, z));

    return 0;
}
