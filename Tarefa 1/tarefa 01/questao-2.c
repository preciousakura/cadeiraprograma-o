#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	if(b!=0){
		printf("%d %d", a/b, a%b);
	}
	return 0;
}