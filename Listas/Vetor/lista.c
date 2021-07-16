#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas fornecidas. Você pode 
 * implementar funções auxiliares além das fornecidas, para isso,
 * coloque o cabeçário da função no arquivo .h e sua implementação 
 * aqui, no arquivo .c. Não altere assinaturas de funções, caso 
 * contrário seu código receberá nota 0,0 (zero).
 */

//Estrutura de lista
struct lista {
	tipo 		*dados;		//Vetor que armazena os dados
	int 		capacidade; //Capacidade de armazenamento da lista
 	int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções
typedef struct lista lista_t;

#include <stdlib.h>
#include <stdio.h>


lista_t* lista_cria (int capacidade){
	if (capacidade<0) return NULL;
	lista_t *p = (lista_t*) malloc( sizeof(lista_t) );
	p->dados = (tipo*) malloc( sizeof(tipo)*capacidade );
	if(!p) return NULL;
	p->capacidade = capacidade;
	p->tamanho = 0;

	return p;
}

//########################################################

void lista_destroi (lista_t **l){
	if(!l) return;
	if(!(*l)) return;
	if((*l)->dados != NULL)
		free((*l)->dados);
	free(*l);
	*l = NULL;
}

//########################################################

int lista_inicializada (lista_t *l){
	if(!l || !(l->dados)) return 0;
	return 1;
}

//########################################################

int lista_tamanho (lista_t *l){
	if(!l) return -1;
	return l->tamanho;
}

//########################################################

int lista_capacidade (lista_t *l){
	if(!l) return -1;
	return l->capacidade;
}

//########################################################

int lista_cheia (lista_t *l){
	if(!l) return -1;
	if(l->capacidade <= l->tamanho)
		return 1;
	return 0;
}

//########################################################

int lista_info_cabeca (lista_t *l, int *dado){
	if(!l || !dado) return -1;
	if(l->tamanho==0) return 0;
	*dado = l->dados[0];
	if(!dado) return -1;
	return 1;
}

//########################################################

int lista_info_cauda (lista_t *l, int *dado){
	if(!l || !dado) return -1;
	if(l->tamanho==0) return 0;
	*dado = l->dados[l->tamanho-1];
	if(!dado) return -1;
	return 1;
}

//########################################################

int lista_info_posicao (lista_t *l, int *dado, int pos){
	if(!l || !dado) return -1;
	if(l->tamanho==0) return 0;
	if(pos<0 || pos>=l->tamanho) return 0;
	*dado = l->dados[pos];
	if(!dado) return -1;
	return 1;
}

//########################################################

int lista_insere_cabeca (lista_t *l, tipo dado){
	if(!l || l->capacidade<=l->tamanho) return -1;
	l->tamanho++;
	if(!l->dados) return -1;

	for (int i=l->tamanho; 	i>0; 	i--)
		l->dados[i] = l->dados[i-1];
	l->dados[0] = dado;

	return 1;
}

//########################################################

int lista_insere_cauda (lista_t *l, tipo dado){
	if(!l || l->capacidade<=l->tamanho) return -1;
	l->tamanho++;
	if(!l->dados) return -1;

	l->dados[l->tamanho-1] = dado;
	return 1;
}

//########################################################

int lista_insere_posicao (lista_t *l, tipo dado, int pos){
	if(!l || l->capacidade<=l->tamanho) return -1;
	if(pos>l->tamanho || pos<0) return 0;
	l->tamanho++;
	if(!l->dados) return -1;

	for (int i=(l->tamanho); 		i>pos; 		i--)
		l->dados[i] = l->dados[i-1];
	l->dados[pos] = dado;

	return 1;
}

//########################################################

int lista_remove_cabeca (lista_t *l, tipo *dado){
	if(!l || !l->dados || !dado) return -1;
	if(l->tamanho==0) return 0;
	*dado = l->dados[0];

	for(int i=1; 	i<l->tamanho; 	i++)				
		l->dados[i-1] = l->dados[i];
	l->tamanho--;
	return 1;
}

//########################################################

int lista_remove_cauda (lista_t *l, tipo *dado){
	if(!l || !l->dados || !dado) return -1;
	if(l->tamanho == 0) return 0;
	*dado = l->dados[ l->tamanho-1 ];
	l->tamanho--;
	return 1;	//ultima posicao para NULL?
}

//########################################################

int lista_remove_posicao (lista_t *l, tipo *dado, int pos){
	if(!l || !l->dados || !dado) return -1;
	if(l->tamanho==0) return 0;
	if(pos<0 || pos>=l->tamanho) return 0;
	*dado = l->dados[pos];

	for(int i=pos;	 i<(l->tamanho-1); 	i++){
		l->dados[i] = l->dados[i+1];
	}
	l->tamanho--;
	return 1;
}

//########################################################

int lista_remove_primeira (lista_t *l, tipo dado){
	if(!l) return -1;

	for (int i=0; 	i<l->tamanho;	 i++){
		if (l->dados[i] == dado){

			for (int j=i; 		j<(l->tamanho-1);	j++)
				l->dados[j] = l->dados[j+1];

			l->tamanho--;
			return i;
		}
	}
	return -2;
}

//########################################################

int lista_remove_todas (lista_t *l, tipo dado){
	if(!l) return -1;
	int n_remocoes=0;

	for (int i=0; 	i<l->tamanho;	i++){
		if(l->dados[i] == dado){
			for (int j=i; 	j<(l->tamanho+1);	j++)
				l->dados[j] = l->dados[j+1];
			l->tamanho--;
			n_remocoes++;
		}
	}
	return n_remocoes;
}

//########################################################

int lista_busca_info (lista_t *l, tipo dado){
	if(!l || l->tamanho==0) return -1;

	for (int i=0;	i<l->tamanho;	i++){
		if (l->dados[i] == dado) return i;
	}

	return -1;
}

//########################################################

int lista_frequencia_info (lista_t *l, tipo dado){
	if(!l || l->tamanho==0) return -1;
	int freq = 0;

	for (int i=0;	i<l->tamanho;	i++){
		if (l->dados[i] == dado) freq++;
	}

	return freq;
}

//########################################################

int lista_ordenada (lista_t *l){
	if(!l || !l->dados) return -1;
	if(l->tamanho <= 1) return 1;

	for (int i=1;	i<l->tamanho;	i++){
		if (l->dados[i-1] > l->dados[i]) return 0;
	}

	return 1;
}

//########################################################

int lista_insere_ordenado (lista_t *l, tipo dado){
	if(!l) return -1;
	if(l->tamanho >= l->capacidade) return -1;

	if (l->tamanho==0){
		l->tamanho++;
		l->dados[0] = dado;
		return 1;
	}

	for (int i=0;	i<l->tamanho;	i++){

		if (dado < l->dados[i] && i==0){
			l->tamanho++;
			for (int i=(l->tamanho-1);		i>0;		i--){
				l->dados[i] = l->dados[i-1];
			}
			l->dados[0] = dado;
			return 1;
		}

		if (dado > l->dados[i] && i==(l->tamanho-1)){	//ultimo valor do vetor
			l->tamanho++;
			l->dados[i+1] = dado;
			
			return 1;
		}

		if (dado < l->dados[i]){
			l->tamanho++;

			for (int j=(l->tamanho-1);	j>i;	j--)
				l->dados[j] = l->dados[j-1];			//organiza

			l->dados[i] = dado;
			return 1;
		}
	}
	return -1;
}

//########################################################

int lista_compara(lista_t *l1, lista_t *l2){
	if(!l1 && !l2) return 1;
	if(!l1 || !l2) return 0;
	if(l1->tamanho!=l2->tamanho) return 0;
	if(l1->tamanho==0 && l2->tamanho==0) return 1;
	int k=0;

	for (int i=0;	i<l1->tamanho;	i++){
		k=0;
		for (int j=0;	j<l1->tamanho;	j++){
			if (l1->dados[i]==l2->dados[j])
				k=1;
		}
		if(k==0) return 0;
	}
	return 1;
}

//########################################################

int lista_reverte(lista_t *l){
	if(!l) return -1;
	if(l->tamanho<=1) return 1;
	tipo x;
	int tam = l->tamanho/2;

	for (int i=0; 	i<tam;		i++){
		x = l->dados[i];
		l->dados[i] = l->dados[l->tamanho-i-1];
		l->dados[l->tamanho-i-1] = x;
	}
	return 1;
}

//########################################################

lista_t* lista_cria_copia(lista_t *l){
	if(!l) return NULL;

	lista_t *p = lista_cria(l->capacidade);
	if(!p) return NULL;

	p->tamanho = l->tamanho;

	for (int i=0;	i<l->tamanho; 	i++)
		p->dados[i] = l->dados[i];	

	return p;
}

//########################################################




int main()
{

	// //int dado = 3;
	// lista_t* p = lista_cria (5);
	// p->tamanho = 0;

	// // p->dados[0] = 1;
	// // p->dados[1] = 2;
	// // p->dados[2] = 7;
	// // p->dados[3] = 9;
	// lista_insere_ordenado (p, 2);


	// printf("%d ", p->dados[0]);
	// printf("%d ", p->dados[1]);
	// printf("%d ", p->dados[2]);
	// printf("%d ", p->dados[3]);
	// printf("%d ", p->dados[4]);
	// //printf("\n%d ", dado);



	return 0;
}