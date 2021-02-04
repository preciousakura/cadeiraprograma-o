#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int novo = 0;
    while (n > 0) {
        novo = 10 * novo + n % 10;
        n = n/10;
    }
    printf("%d",novo);
}
