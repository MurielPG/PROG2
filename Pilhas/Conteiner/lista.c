#include "lista.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


pilha_t*	pilha_cria(int capacidade)
{
	pilha_t* p = (pilha_t*)malloc(sizeof(pilha_t));
	if (!p) return NULL;
	p->tamanho = 0;
	p->capacidade = capacidade;
	p->topo = (no_t*)malloc(sizeof(no_t));
	p->topo->dados = (char*)malloc(sizeof(char)*(p->capacidade));
	p->tamanho++;
	return p;
}

//################################################################

int			pilha_empilha(pilha_t *p, char elemento, int pos)
{
	if (!p) return -1;
	no_t *aux = p->topo;
	for (int i=0;	i<pos;	i++)
		aux = aux->prx;

	if (aux->altura == p->capacidade) return 0;
	aux->dados[aux->altura] = elemento;
	aux->altura++;
	return 1;
}

//################################################################

int 		pilha_desempilha(pilha_t *p, char *elemento, int pos)
{
	if (!p || !elemento) return -1;
	no_t *aux = p->topo;
	for (int i=0;	i<pos;	i++)
		aux = aux->prx;

	if (aux->altura==0) return 0;

	*elemento = aux->dados[aux->altura];
	aux->altura--;
	return 1;
}

//################################################################

no_t*		cria_no(pilha_t *p)
{
	no_t* no = (no_t*)malloc(sizeof(no_t));
	no->dados = (char*)malloc(sizeof(char)*(p->capacidade));
	no->altura = 0;

	no_t *aux = p->topo;	//ordena
	for (int i=0;	i<(p->tamanho-1);	i++)
		aux = aux->prx;
	
	aux->prx = no;
	p->tamanho++;

	return no;
}

//################################################################

int 		escolhe_pilha(pilha_t *p, char cont)	//CONTainer
{
	if (!p) return -1;
	if (p->tamanho==0) return 0;
	no_t *aux = p->topo;

	for (int i=0; 	i<p->tamanho;	i++)			//itero em cada no
	{
		if (aux->altura == 0){
			aux->dados[aux->altura] = cont;
			aux->altura++;
			return 1;
		}
		if (cont <= aux->dados[aux->altura-1]		//vejo se container eh valido
			&& aux->altura < p->capacidade)	//vejo se cabe um container
			return pilha_empilha(p, cont, i);	//adiciono o container
		
		aux = aux->prx;
	}
	no_t *no = cria_no(p);
	no->dados[no->altura] = cont;
	no->altura++;

	return 1;
}

//################################################################

void		pilha_destroi(pilha_t **p)
{
	if (!p) return;
	no_t* seguinte = (*p)->topo;
	no_t* aux = seguinte;

	while (aux)
	{
		seguinte = seguinte->prx;
		free(aux->dados);
		free(aux);
		aux = seguinte;
	}
	free(*p);
	*p=NULL;
}

//################################################################

// int main()
// {
// 	int altura;
// 	char containers[400];

// 	scanf("%d", &altura);

// 	while(altura != 0)
// 	{
// 		scanf("%s", containers);
// 		int tam = strlen(containers);
// 		pilha_t* p = pilha_cria(altura);

// 		for (int i=0;	i<tam;	i++)
// 			escolhe_pilha(p, containers[i]);

// 		printf("%d", p->tamanho);
// 		scanf("%d", &altura);
// 		if(altura!=0)
// 			printf("\n");
		
// 		pilha_destroi(&p);

// 	}
// }
