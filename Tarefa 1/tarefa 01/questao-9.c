#include <stdio.h>
int main(){
	int cont = 0;
	int num = 1;
	while(cont!=1000){
		if((num%2!=0)&&(num%3!=0)&&(num%7!=0)){
			printf("%d\n", num);
			cont+=1;
		}
		num += 1;
	}
	return 0;
}
