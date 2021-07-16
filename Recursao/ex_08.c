#include <stdio.h>
#include <stdlib.h>

void p_v(float vetor[], int tam){
	tam--;
	//printf("%.2f\n", vetor[tam]);
	if(tam==0) return;
	return p_v(vetor, tam);
}

int main(){
	float vetor[] = {1,2,3,4,5,6};
	int tam = sizeof vetor / sizeof vetor[0];
	p_v(vetor, tam);
	return 0;
}