#include <stdio.h>
#include <stdlib.h>

int fat_qua(int num){
	if(num<=0){
		return 1;
	} return (num*fat_qua(num-1));			
}

int main(){
	int n = 0;
	scanf("%d", &n);
	printf("%d",fat_qua(2*n)/fat_qua(n));
	return 0;
}