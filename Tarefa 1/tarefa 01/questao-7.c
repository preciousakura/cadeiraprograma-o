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
	for(int i = 2; i<=n; i++){
		if(primoEh(i)==0){
			printf("%d\n",i);
		}
	}
	return 0;
}