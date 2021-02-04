#include <stdio.h>
#include <stdlib.h>

/*4. O superfatorial de um numero N e definida pelo produto dos N primeiros fatoriais de N. Assim, o
superfatorial de 4 e:
sf(4) = 1! × 2! × 3! × 4! = 288
Faca uma func˜ao recursiva que receba um numero inteiro positivo N e retorne o superfatorial desse
numero.
*/

int fatorial(int num){
    int cont,fat;
    cont = num;
    if (num == 1){
        return 1;
    }
    else{
        while (cont  > 1){
            fat = num * fatorial(num - 1);
            cont = cont -1 ;
    }
    return fat;
    }
}



int main()
{   int num,sp,cont;
    printf("Digite um numero:\n");
    scanf("%d",&num);
    cont = num;
    sp = 1;
    while (cont > 0){
       sp = fatorial(cont)*sp;
       cont = cont - 1;
    }
    printf("%d",sp);
    return 0;
}
