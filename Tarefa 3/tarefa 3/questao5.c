#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*O hiperfatorial de um numero N, escrito H(n), e definido por:
Faca uma funcao recursiva que receba um numero inteiro positivo N e retorne o hiperfatorial desse
numero.
*/
int hfatorial(int num){
    int cont,fat;
    cont = num;
    if (num == 1){
        return 1;
    }
    else{
        while (cont  > 1){
            fat = pow(num,num)* hfatorial(num - 1);
            cont = cont -1 ;
    }
    return fat;
    }
}

int main()
{   int num,hiperfatorial;
    printf("Digite um numero: \n");
    scanf("%d",&num);

    hiperfatorial = hfatorial(num);

    printf("%d",hiperfatorial);
    return 0;
}
