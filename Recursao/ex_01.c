#include <stdio.h>
#include <stdlib.h>

int fat(int valor){
	if(valor <= 1) return 1;
	return valor*fat(valor-1);
}

int main(){
	printf("%d", fat(1) );
	return 0;
}