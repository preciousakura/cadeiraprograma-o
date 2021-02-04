#include <stdio.h>
int main(){
	int maior,a,b,c,pit;
	maior = -1;
	
	scanf("%d %d %d", &a, &b, &c);
	if(a>c & a>b){
		maior = a;
		pit = (b*b + c*c);
	}
	if(b>c & b>a){
		maior = b;
		pit = (a*a + c*c);
	}
	if(c>a & c>b){
		maior = c;
		pit = (a*a + b*b);
	}
	
	if (maior*maior == pit){
		printf("eh triangulo retangulo");
	}
	else {
		printf("nao eh")
	}
	return 0;
}