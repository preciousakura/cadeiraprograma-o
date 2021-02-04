#include <stdio.h>
int primoEh(int valor){
	int primo;
	primo = 0;
	for(int j = 2; j<valor; j++){
		if(valor%j==0){
			primo++;
		}
	}
	if(primo<1){
		return 0;
	}return 1;
}
int main(){
	int n;
	scanf("%d", &n);
	while(primoEh(n)!=0){
		n-=1;
	}
	printf("%d", n);
	return 0;
}
