#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x, y, rest;

    printf("Digite um numero inteiro: ");
    scanf("%i", &x);

    printf("Digite outro numero inteiro: ");
    scanf("%i", &y);

    printf("O MDC DE %i E %i eh: ", x, y);
    while(rest != 0){
        rest = x % y;
        x = y;
        y = rest;
    }

    printf("%i", x);

    return 0;
}
