/* Fazer um programa em linguagem C que defina uma função para receber um vetor de
numéricos qualquer e classificá-lo, utilizando o método de ordenação Selection Sort. O
tamanho do vetor deve ser passado como parâmetro na função. */

#include <stdio.h>
void selection_Sort(int *vetor[], int tam){
	int currentMinimum = 0;
	int aux = 0;
	int pos = 0;
	
	
	for(int i=0;i<tam;i++){
		currentMinimum = vetor[i];
		pos = i;
		
		for(int j=i;j<tam;j++){
			if(vetor[j] < currentMinimum){
				currentMinimum = vetor[j];
				pos = j;
			}
		}
		aux = vetor[i];
		vetor[i] = currentMinimum;
		vetor[pos] = aux;
	}
}

int main(){
	int tam;
	scanf("%d", &tam);
	
	int vetor[tam];
	for(int i=0;i<tam;i++){
		scanf("%d", &vetor[i]);
	}
	selection_Sort(vetor, tam);
	for(int i=0;i<tam;i++){
		printf("%d ", vetor[i]);
	}
	return 0;
}