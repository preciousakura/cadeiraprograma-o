#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

double area(double radius){
    return (4 * PI) * (radius * radius);
}

double volume(double radius){
    return (4 * PI * (radius * radius * radius)) / 3;
}

int main(int argc, char const *argv[])
{
    double radius;
    printf("Digite um numero inteiro positivo que sera usado como raio de uma esfera: ");
    scanf("%lf", &radius);

    printf("Área: %f\n", area(radius));
    printf("Volume: %f\n", volume(radius));

    return 0;
}

