#include <stdio.h>
#include <stdlib.h>

int imp(int inf, int sup, int pulo){
	if (sup*pulo < 0) return 0; //testa se um dos dois sao negativos, erro
	if (inf > sup) return 0;
	//printf("%d ", inf);
	inf = inf + pulo;
	return imp(inf, sup, pulo);
}


int main(){
	imp(3, 10, 2);
	return 0;
}