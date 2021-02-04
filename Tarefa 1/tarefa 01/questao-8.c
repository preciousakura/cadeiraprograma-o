#include <stdio.h>
int main(){
	int n, ant, prox;
	ant = 0;
	prox = 1;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++){
		printf("%d ", prox);
		prox = ant	+ prox;
		ant = prox - ant;
		
	}
	return 0;
}
