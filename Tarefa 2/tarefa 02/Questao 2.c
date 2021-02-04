#include <stdio.h>
#include <stdlib.h>

int isPrime(int n){
    for (int i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void printAllPrimesBefore(int n){
    for (int i = 2; i < n; i++){
        if(isPrime(i)){
            printf("%i, ", i);
        }
    }
}

void printFirstNPrimers(int n){
    int j = 2, counter = 0;
    while(counter < n){
        if(isPrime(j)){
            printf("%i, ", j);
            counter++;
        }
        j++;
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%i", &n);

    isPrime(n) ? printf("Esse numero é primo ") : printf("Esse numero nao é primo ");
    printf("\n");

    printf("Todos os números primos menores que %i:\n", n);
    printAllPrimesBefore(n);
    printf("\n");

    printf("Os primeiros %i numeros primos sao:\n", n);
    printFirstNPrimers(n);

    return 0;
}
