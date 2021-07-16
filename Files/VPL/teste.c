#include <stdio.h>
#include <stdlib.h>


void recebe_printa(double *vetor, int tamanho){
	int i=0;

	do{
		printf(" %lf\n", vetor[i]);
		i++;
	}while(i<tamanho);
}





int main(){

	FILE *arquivo = fopen("arquivo.txt", "r");

	double *vetores=NULL; //=  (double*) malloc( sizeof(double) );


	int i=0;

	do{
		i++;
		vetores = (double*) realloc( vetores, sizeof(double) *i);
		fscanf(arquivo, "%lf", &vetores[i-1]);
		
		
	}while(!feof(arquivo));

	recebe_printa(vetores, i);

	return 0;
}
