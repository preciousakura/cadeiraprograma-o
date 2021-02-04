#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void geraVetor(double *vetor_um, double *vetor_dois, double *vetor_tres, double *vetor_quatro, int tam) { // gera o vetor aleatório
		int sorteado;
		for(int j = 0; j<tam; j++){
			sorteado = rand()%(tam*100);
			vetor_um[j] = sorteado;
			vetor_dois[j] = sorteado;
			vetor_tres[j] = sorteado;
			vetor_quatro[j] = sorteado;
		}
}

void combsort(double vetor[], int tam) { // algoritmo no comb sort
   int i, j, gap, swapped = 1;
   double aux;
   gap = tam;
   while (gap > 1 || swapped == 1) {
      gap = gap / 1.3;
      if (gap < 1) {
         gap = 1;
      }
      swapped = 0;
      for (i = 0, j = gap; j < tam; i++, j++) {
         if (vetor[i] > vetor[j]) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            swapped = 1;
         }
      }
   }
}

void insertionSort(double a[], int tam)  { // algoritmo do inserion sort  
    int i, key, j;  
    for (i = 1; i < tam; i++) 
    {  
        key = a[i];  
        j = i - 1;  
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  
}  


void bubble_Sort(double vetor[], int tam) { // algortimo do bubble sort
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

void selection_Sort(double vetor[], int tam){ // algoritmo do selection sort
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
	clock_t tempo_inicio, tempo_final;
    double tempo_total_selection_Sort = 0.0, tempo_total_combsort = 0.0, tempo_total_insertionSort = 0.0, tempo_total_bubble_Sort  = 0.0;
	
	int n,k;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	printf("Numero de vezes: ");
	scanf("%d", &k);
	
	double vetor_um[n];
	double vetor_dois[n];
	double vetor_tres[n];
	double vetor_quatro[n];

	srand( (unsigned)time(NULL) );
	
	for(int i = 0; i<k; i++){
		geraVetor(vetor_um, vetor_dois, vetor_tres, vetor_quatro, n);
		
		tempo_inicio = clock(); 
		combsort(vetor_dois, n);
		tempo_final = clock();
		
		tempo_total_combsort += (double)(tempo_final - tempo_inicio) / CLOCKS_PER_SEC;
		
		tempo_inicio = clock(); 
		insertionSort(vetor_um, n);
		tempo_final = clock();
		
		tempo_total_insertionSort += (double)(tempo_final - tempo_inicio) / CLOCKS_PER_SEC;
		
		tempo_inicio = clock(); 
		bubble_Sort(vetor_tres, n);
		tempo_final = clock();

		tempo_total_bubble_Sort += (double)(tempo_final - tempo_inicio) / CLOCKS_PER_SEC;
		
		tempo_inicio = clock(); 
		selection_Sort(vetor_quatro, n);
		tempo_final = clock();
		
		tempo_total_selection_Sort += (double)(tempo_final - tempo_inicio) / CLOCKS_PER_SEC;
		
	}
	
	
    printf("O tempo que o Comb Sort ordena %d vezes um vetor de %d posicoes eh %Lf segundos.\n",k,n,tempo_total_combsort);
	printf("O tempo que o Insertion Sort ordena %d vezes um vetor de %d posicoes eh %Lf segundos.\n",k,n,tempo_total_insertionSort);
	printf("O tempo que o Bubble Sort ordena %d vezes um vetor de %d posicoes eh %Lf segundos.\n",k,n,tempo_total_bubble_Sort);
	printf("O tempo que o Selection Sort ordena %d vezes um vetor de %d posicoes eh %Lf segundos.\n\n",k,n,tempo_total_selection_Sort);
	
	if((tempo_total_combsort<tempo_total_insertionSort) && (tempo_total_combsort<tempo_total_bubble_Sort) && (tempo_total_combsort<tempo_total_selection_Sort)){
		printf("O algoritmo mais eficiente eh o Comb Sort");
	}else if((tempo_total_insertionSort<tempo_total_combsort) && (tempo_total_insertionSort<tempo_total_bubble_Sort) && (tempo_total_insertionSort<tempo_total_selection_Sort)){
		printf("O algoritmo mais eficiente eh o Insertion Sort");
	}else if((tempo_total_bubble_Sort<tempo_total_combsort) && (tempo_total_insertionSort>tempo_total_bubble_Sort) && (tempo_total_bubble_Sort<tempo_total_selection_Sort)){
		printf("O algoritmo mais eficiente eh o Bubble Sort");
	}else if((tempo_total_selection_Sort<tempo_total_combsort) && (tempo_total_selection_Sort>tempo_total_bubble_Sort) && (tempo_total_selection_Sort<tempo_total_insertionSort)){
		printf("O algoritmo mais eficiente eh o Selection Sort");
	}
	
	
	return 0;
}