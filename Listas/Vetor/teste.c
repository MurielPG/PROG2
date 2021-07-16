#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	dados[] = {1,2,3,4,5,6};
	int tamanho = 6;

	int x;
	int tam = tamanho/2;
	tamanho--;

	for (int i=0; 	i<tam;		i++){
		x = dados[i];
		dados[i] = dados[tamanho-i];
		dados[tamanho-i] = x;
	}







/*
*		print valores
*/
	printf("\n\n");
	for(int i=0; i<(tamanho+1); i++)
		printf("%d ", dados[i]);
}