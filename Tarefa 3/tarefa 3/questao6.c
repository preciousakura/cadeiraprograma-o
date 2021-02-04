#include <stdio.h>
#include <stdlib.h>

/*6. Um fatorial exponencial e um inteiro positivo N elevado a potencia de N-1, que por sua vez e elevado
a potencia de N-2 e assim em diante. Ou seja, Faca uma funç˜ao recursiva que receba um numero
inteiro positivo N e retorne o fatorial exponencial desse numero.
*/
int expfatorial(int num){
    int cont,fat;
    cont = num;
    if (num == 1){
        return 1;
    }
    else{
        while (cont  > 1){
            fat = pow(num , expfatorial(num - 1));
            cont = cont -1 ;
    }
    return fat;
    }
}


int main()
{   int num,fat_exp;
    printf("Digite um numero:\n");
    scanf("%d",&num);

    fat_exp = expfatorial(num);

    printf("%d",fat_exp);
    return 0;
}
