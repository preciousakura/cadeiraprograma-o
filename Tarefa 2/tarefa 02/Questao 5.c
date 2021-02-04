#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pot(double x, int k){
    double total = x;
    for (int i = 1; i < k; i++){
       total *= x;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    double x;
    int k;

    printf("Digite um numero: ");
    scanf("%lf", &x);
    printf("Digite outro numero inteiro positivo: ");
    scanf("%i", &k);

    printf("A potencia de %f^%i é: \n", x, k);
    printf("Math.pow = %f \n", pow(x, k));
    printf("pot = %f\n", pot(x, k));

    return 0;
}
