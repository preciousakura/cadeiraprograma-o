#include <stdio.h>
int main(){
	int ano;
	scanf("%d", &ano);
	if((ano%4==0) & (ano%100!=0) & (ano>=1752)) {
		printf("eh bissexto");
	}else if((ano%100==0)&(ano%400==0)& (ano>=1752)){
		printf("eh bissexto");
	}else{
		printf("nao eh bissexto");
	}
	return 0;
}