#ifndef _pilhah_
#define _pilhah_

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	int valor;			//valor conteiner
	struct no *prx;			//conteiner seguinte
}no_t;

typedef struct pilha{
	no_t *cabeca;		//primeiro conteiner/conjunto
}pilha_t;

	

pilha_t* cria_pilha(int valor);

void pilha_destroi(pilha_t **vp, int tam);

void decide_funcao(pilha_t **vp, char *str1, char *str2, int mover, int base, int tam);

int encontra_index(pilha_t **vp, int valor, int tam);

void mova_sobre(pilha_t **vp, int mover, int base, int tam);

int encontra_posicao(pilha_t **vp, int valor, int tam);

void mova_topo(pilha_t **vp, int mover, int base, int tam);

no_t* posiciona_no_anterior(pilha_t **vp, int i, int dado);
/*	essa funcao recebe o no anterior ao qual eh necessario a remocao
	a partir dele, seta os ponteiros para nulo, e copia o endereco para
	a cabeca no vetor de mesmo index do valor que esse no armazena
*/
void retorna_origem(pilha_t **vp, no_t* no);

void empilhe_sobre(pilha_t **vp, int mover, int base, int tam);

void empilhe_topo(pilha_t **vp, int mover, int base, int tam);

void imprime_resultado(pilha_t **vp, int tam);








#endif
