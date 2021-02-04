/* Fazer um programa em linguagem C que defina uma função para receber um vetor de
numéricos qualquer e classificá-lo, utilizando o método de ordenação Selection Sort. O
tamanho do vetor deve ser passado como parâmetro na função. */

#include <stdio.h>
void pontoSimetrico(float *x, float *y, float *a, float *b, float *c, float *sx, float *sy){
	float coeficiente_angular = -1/(-*a/ *b);
	float ponto_medio_x = ((-*c/ *b) + (coeficiente_angular* *x) - *y)/(coeficiente_angular + (*a/ *b));
	float ponto_medio_y = (coeficiente_angular * (ponto_medio_x - *x)) + *y;
	*sx = (ponto_medio_x*2) - *x;
	*sy = (ponto_medio_y*2) - *y;
}

int main(){
	float x,y,a,b,c;
	
	printf("Coordenada X: ");
	scanf("%f", &x);
	printf("Coordenada Y: ");
	scanf("%f", &y);
	printf("Coeficiente A: ");
	scanf("%f", &a);
	printf("Coeficiente B: ");
	scanf("%f", &b);
	printf("Coeficiente C: ");
	scanf("%f", &c);
	
	float sx = 0;
	float sy = 0;
	
	float *si_x = &sx;
	float *si_y = &sy;
	float *pX = &x;
	float *pY = &y;
	float *pA = &a;
	float *pB = &b;
	float *pC = &c;
	
	pontoSimetrico(pX,pY,pA,pB,pC,si_x,si_y);
	printf("Ponto B: (%.0f, %.0f)", *si_x, *si_y);

	return 0;
}