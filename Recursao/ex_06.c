#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma_vetor(int vetor[], int tam){
	//if (!vetor) return 0;
	if (tam<2) return vetor[0];
	tam--;
	vetor[0] += vetor[tam];
	return soma_vetor(vetor, tam);
}



int main(){
	int vetor[] = {1,2,3};
	int tam = sizeof vetor/sizeof vetor[0];

	//printf("%d", soma_vetor(vetor, tam) );


	return 0;
}