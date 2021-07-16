#include <stdio.h>
#include <stdlib.h>


int encontra_fibo(int n){
	if(n<2) return n;
	return (encontra_fibo(n-1) + encontra_fibo(n-2));
}

int main(){
	for (int i=0; i<20; i++){
		int posicao = i;
		printf("%d\n", encontra_fibo(posicao) );
	}
	return 0;
}