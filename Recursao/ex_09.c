#include <stdio.h>
#include <stdlib.h>



int inverte_vetor(int *vetor, int tam, int i){
	if(!vetor) return 0;
	if( (i-tam)==0 || tam-i<0) return 0;
	int x;
	tam--;
	x = vetor[tam];
	vetor[tam] = vetor[i];
	vetor[i] = x;
	i++;
	return inverte_vetor(vetor, tam, i);
}


int main(){
	int vetor[] = {1,2,3,4,5,6,0,8};
	int tam = sizeof vetor / sizeof vetor[0];
	int i=0;
	inverte_vetor(vetor, tam, i);
	
	for (int i=0; i<tam; i++){
		printf("%d ", vetor[i]);
	}

	return 0;
}