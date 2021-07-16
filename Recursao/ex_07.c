#include <stdio.h>
#include <stdlib.h>
	
void p_v(int vetor[], int tam, int i){		
	//printf("%d\n", vetor[i]);
	i++;
	if(i<tam) return p_v(vetor, tam, i);
}

int main(){
	int vetor[] = {1,2,9,10};
	int i = 0;
	int tam = sizeof vetor / sizeof vetor[0];
	p_v(vetor, tam, i);
	return 0;
}