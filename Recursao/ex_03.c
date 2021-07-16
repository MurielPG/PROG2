#include <stdio.h>
#include <stdlib.h>


int soma(int valor){
	if (valor < 1) return 0;
	if (valor == 1) return valor;
	return valor + soma(valor-1);
}

int main(){
	printf("%d", soma(4) );
	return 0;
}