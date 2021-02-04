#include <stdio.h>
#include <stdlib.h>
/*
7. Os numeros tetranacci iniciam com quatro termos pre-determinados e a partir daı todos os demais
numeros s˜ao obtidos pela soma dos quatro numeros anteriores. Os primeiros numeros tetranacci
s˜ao: 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208... Faca uma func˜ao recursiva que receba um numero
N e retorne o N-esimo termo da sequencia de tetranacci.
*/

int tetranacci(int n){
    int a1,a2,a3,a4,af,cont;
    cont = n - 4;

    if ( n == 1 || n == 2 || n == 3 )

        return 0;

    else

        if( n==4 )

            return 1;

    else


        af  = tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);


        return af;
}

int main()
{   int n,termo;
    printf("Digite um numero: \n");
    scanf("%d",&n);

    termo = tetranacci(n);

    printf("%d",termo);

    return 0;
}
