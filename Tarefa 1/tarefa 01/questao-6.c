#include <stdio.h>
int main(){
	int dia_a, mes_a, ano_a, dia_n, mes_n, ano_n, idade;
	scanf("%d %d %d %d %d %d",&dia_a,&mes_a,&ano_a, &dia_n, &mes_n, &ano_n);
	idade = ano_a - ano_n;
	if((mes_n>=mes_a) & (dia_a<dia_n)) {
		idade = idade - 1;
	}
	
	if(idade<16){
		printf("nao eh eleitor");
	}else if((idade>=16 & idade<18) || (idade>65)){
		printf("eleitor facultativo");
	}else{
		printf("eleitor obrigatorio");
	}
	
	return 0;
}