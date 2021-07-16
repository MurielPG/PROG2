#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int altura;
	char containers[400];

	scanf("%d", &altura);

	while(altura != 0)
	{
		scanf("%s", containers);
		int tam = strlen(containers);
		pilha_t* p = pilha_cria(altura);

		for (int i=0;	i<tam;	i++)
			escolhe_pilha(p, containers[i]);

		printf("%d", p->tamanho);
		scanf("%d", &altura);
		if(altura!=0)
			printf("\n");
		
		pilha_destroi(&p);

	}
}