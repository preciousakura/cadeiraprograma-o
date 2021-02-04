#include <stdio.h>
#include <stdlib.h>

int fat_dup(int num){
	if(num<0){
		return 1;
	}
	else{
		if(num<=0){
			return 1*fat_dup(num-2);
		}
		
		else{
			return num*fat_dup(num-2);
		}
	}
			
}

int main(){
	int n = 0;
	scanf("%d", &n);
	printf("%d",fat_dup(n));
	return 0;
}