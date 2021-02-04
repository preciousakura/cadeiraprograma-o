#include <stdio.h>
#include <stdlib.h>

int binario(int num){
	if(num<2){
		return num;
	} return 10*binario(num/2) + num%2;
}

int main(){
	int n = 0;
	scanf("%d", &n);
	printf("%d",binario(n));
	return 0;
}