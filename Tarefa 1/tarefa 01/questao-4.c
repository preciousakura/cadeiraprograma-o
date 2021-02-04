#include <stdio.h>
int main(){
	char nome[20];
	int hora, num_child;
	float valor_por_hora;
	scanf("%s %d %d %f", &nome, &hora, &num_child, &valor_por_hora);
	float salario = -1;
	salario = valor_por_hora*hora;
	printf("Nome: %s\nSalario: R$%.0f,00\n", nome,salario);
	if(num_child > 3){
		salario = ((num_child*3))*(salario)/100;
		printf("Acrescimo pelos filhos: R$%.0f,00", salario);
	}
	
	
	return 0;
}