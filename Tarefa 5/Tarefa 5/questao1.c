/* Fazer um programa em linguagem C que defina uma função para receber um vetor de
numéricos qualquer e classificá-lo, utilizando o método de ordenação Bubble Sort. O tamanho
do vetor deve ser passado como parâmetro na função. */

#include <stdio.h>
void bubble_Sort(int *vetor, int tam){
	int aux = 0;
	for(int j = 0; j<tam; j++){
		for(int i = 0; i<tam-j; i++){
			if(vetor[i]>vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}
}

int main(){
	int tam;
	scanf("%d", &tam);
	
	int vetor[tam];
	for(int i=0;i<tam;i++){
		scanf("%d", &vetor[i]);
	}
	bubble_Sort(vetor, tam);
	for(int i=0;i<tam;i++){
		printf("%d ", vetor[i]);
	}
	return 0;
}