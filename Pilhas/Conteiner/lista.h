#ifndef _pilhah_
#define _pilhah_

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	char 		*dados;		//vetor contendo os conteiners
	struct no 	*prx;		//proxima pilha de conteiner
	int 		altura;		//altura atual da pilha
} no_t;

typedef struct pilha{
	int 	tamanho;		//total de pilhas	
	no_t	*topo;			//topo da pilha
	int 	capacidade; 	//altura maxima da pilha
} pilha_t;

	
/*	Cria e inicializa a lista, retorna endereco
*	lista criada eh vazia
*	recebe como parametro o tamanho maximo 
*	que os containers podem ser agrupados
*	funcao retorna NULL se n conseguir alocar
*/
pilha_t*	pilha_cria(int capacidade);

/*	adiciona um valor em local especifico
*	param: pilha, elemento a ser alocado, e a posicao
* 	do no (pilha de containers)
*	retorna 1 se conseguir adicionar, 0 se nao tiver espaco
*/
int			pilha_empilha(pilha_t *p, char elemento, int pos);

/*	retira um valor de pilha em local especifico;
*	param: pilha, elemento para copiar o elemento removido
*	posicao do no (pilha de containers)
*	se nao tiver containers retorna 0, ou 1 se conseguir
*/
int 		pilha_desempilha(pilha_t *p, char *elemento, int pos);

/*	cria um no para alocar novos valores de containers
*	recebe como paramentro a lista
*	vai adicionar o no na primeira posicao (TOPO)
*	retorna o ponteiro para o no
*/
no_t*		cria_no(pilha_t *p);

/*	vai escolher a primiera posicao disponivel para adicionar 
*	o container. Itera entre os nos, caso nao ache nenhum
*	disponivel vai criar um novo no no topo da lista e
*	adicionar o elemento.
*	retorna 1 caso consiga, 
*/
int 		escolhe_pilha(pilha_t *p, char cont);

/*	destroi a pilha recebida como parametro
*/	

void		pilha_destroi(pilha_t **p)


#endif