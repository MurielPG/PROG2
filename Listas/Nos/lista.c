#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de nó duplamente encadeado
struct no
{
	tipo info;		//Informação (dado) armazenada no nó
	struct no *ant; //Ponteiro para o nó anterior
	struct no *prx; //Ponteiro para o próximo nó
};

//Estrutura de lista duplamente encadeada com nós
struct lista
{
	no_t *cabeca; //Ponteiro para a cabeca da lista (primeiro)
	no_t *cauda;  //Ponteiro para a cauda da lista (último)
	int tamanho;  //Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções
// typedef struct no no_t;
// typedef struct lista lista_t;

#include <stdlib.h>
#include <stdio.h>

lista_t *lista_cria()
{
	lista_t *ptr = (lista_t *)malloc(sizeof(lista_t));
	if (ptr == NULL) return NULL;
	ptr->tamanho = 0;
	ptr->cabeca = NULL;
	ptr->cauda = NULL;
	return ptr;
}

//##########################################################

void lista_destroi(lista_t **l)
{
	if (l == NULL || (*l) == NULL)
		return;
	if (!(*l)->cabeca){
		free(*l);
		(*l) = NULL;
		return;
	}

	no_t* aux = (*l)->cabeca;
	while (aux)
	{
	    no_t* seguinte = aux->prx;
	    free(aux);
	    aux = seguinte;
	}

	free(*l);
	(*l) = NULL;
}

//##########################################################

int lista_inicializada(lista_t *l)
{
	if (l == NULL)
		return 0;
	return 1;
}

//##########################################################

int lista_tamanho(lista_t *l)
{
	if (l == NULL)
		return -1;
	return l->tamanho;
}

//##########################################################

int lista_info_cabeca(lista_t *l, int *dado)
{
	if (l == NULL)
		return -1;
	if (dado == NULL)
		return -1;
	if (l->tamanho < 1)
		return 0;
	*dado = l->cabeca->info;

	return 1;
}

//##########################################################

int lista_info_cauda(lista_t *l, int *dado)
{
	if (l == NULL)
		return -1;
	if (dado == NULL)
		return -1;
	if (l->tamanho < 1)
		return 0;
	*dado = l->cauda->info;

	return 1;
}

//##########################################################

int lista_info_posicao(lista_t *l, int *dado, int pos)
{
	if (!l || !dado)
		return -1;
	if (l->tamanho == 0)
		return 0;
	if (pos < 0 || pos >= l->tamanho)
		return 0;

	no_t *p;
	p = l->cabeca;

	for (int i = 0; i <= pos; i++)
	{
		if (i == pos)
		{
			*dado = p->info;
			return 1;
		}
		p = p->prx;
	}
	return -1;
}

//##########################################################

int lista_insere_cabeca(lista_t *l, tipo dado)
{
	if (!l)
		return -1;
	no_t *ptr = (no_t *)malloc(sizeof(no_t));
	if (!ptr)
		return -1;

	if (l->tamanho == 0)
	{
		l->cabeca = ptr;
		ptr->info = dado;
		l->cauda = ptr; // cauda ou ptr
		ptr->ant = NULL;
		ptr->prx = NULL;
	}else{
		ptr->info = dado;
		ptr->prx = l->cabeca;
		l->cabeca->ant = ptr;
		ptr->ant = NULL;
		l->cabeca = ptr;
	}
	l->tamanho++;

	return 1;
}

//##########################################################

int lista_insere_cauda(lista_t *l, tipo dado)
{
	if (!l)
		return -1;

	no_t *ptr = (no_t *)malloc(sizeof(no_t));
	if (!ptr)
		return -1;

	if (l->tamanho == 0)
	{
		l->cauda = ptr;
		ptr->info = dado;
		l->cabeca = ptr; 
		ptr->ant = NULL;
		ptr->prx = NULL;
	}else{
		ptr->info = dado;
		ptr->ant = l->cauda;
		l->cauda->prx = ptr;
		ptr->prx = NULL;
		l->cauda = ptr;
	}
	l->tamanho++;

	return 1;
}

//##########################################################

int lista_insere_posicao(lista_t *l, tipo dado, int pos)
{
	if (!l)
		return -1;
	if (pos < 0 || pos > l->tamanho)
		return 0;

	no_t *ptr = l->cabeca;

	if (pos==0)
		return lista_insere_cabeca(l, dado);

	if (pos==l->tamanho)
		return lista_insere_cauda(l, dado);

	for (int i = 1; i < pos; i++)
	{
		ptr = ptr->prx;
	} //ptr aponta para o anterior a posicao

	no_t *aux = (no_t *)malloc(sizeof(no_t));
	if (!aux)
		return -1;

	aux->info = dado;
	aux->ant = ptr;
	aux->prx = ptr->prx;
	ptr->prx->ant = aux;
	ptr->prx = aux;
	l->tamanho++;

	return 1;
}

//##########################################################

int lista_remove_cabeca(lista_t *l, tipo *dado)
{
	if (!l || !dado)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->cabeca->info;

	if (l->tamanho==1){
		free(l->cabeca);
		l->cabeca = NULL;
		l->cauda = NULL;
		l->tamanho--;
		return 1;
	}

	no_t *ptr;
	ptr = l->cabeca->prx;
	ptr->ant = NULL;

	free(l->cabeca);
	l->cabeca = ptr;
	l->tamanho--;
	return 1;
}

//##########################################################

int lista_remove_cauda(lista_t *l, tipo *dado)
{
	if (!l || !dado)
		return -1;
	if (l->tamanho == 0)
		return 0;

	if (l->tamanho == 1)
		return lista_remove_cabeca(l, dado);
	
	*dado = l->cauda->info;
	no_t *ptr;
	ptr = l->cauda->ant;

	free(l->cauda);
	l->cauda = ptr;
	ptr->prx = NULL;

	l->tamanho--;

	return 1;
}

//##########################################################

int lista_remove_posicao(lista_t *l, tipo *dado, int pos)
{
	if (!l || !dado)
		return -1;
	if (l->tamanho == 0)
		return 0;

	if (l->tamanho == 1 || pos == 0)
	{
		lista_remove_cabeca(l, dado);
		return 1;
	}
	if (l->tamanho == 2 || pos == (l->tamanho - 1))
	{
		lista_remove_cauda(l, dado);
		return 1;
	}

	no_t *ptr;
	ptr = l->cabeca;

	for (int i = 0; i < (pos - 1); i++)
		ptr = ptr->prx;

	*dado = ptr->prx->info;
	no_t *aux = ptr->prx;
	ptr->prx = ptr->prx->prx;
	ptr->prx->ant = ptr;

	free(aux);
	l->tamanho--;
	return 1;
}

//##########################################################

int lista_remove_primeira(lista_t *l, tipo dado)
{
	if (!l)
		return -1;
	no_t *ptr;
	ptr = l->cabeca;
	tipo recebe;

	for (int i = 0; i < l->tamanho; i++)
	{
		if (ptr->info == dado)
		{
			lista_remove_posicao(l, &recebe, i);
			return i;
		}
		ptr = ptr->prx;
	}
	return -2;
}

//##########################################################

int lista_remove_todas(lista_t *l, tipo dado)
{
	if (!l)
		return -1;
	if (l->tamanho==0) return 0;
	no_t *ptr = l->cabeca;

	int cont = 0;
	tipo recebe;

	for (int i=0; 	i<l->tamanho; 	i++)
	{
		if (ptr->info == dado)
		{
			ptr = ptr->prx;
			lista_remove_posicao(l, &recebe, i);
			cont++;
			i--;
		}else{
		ptr = ptr->prx;
		}
	}

	return cont;
}

//##########################################################

int lista_busca_info(lista_t *l, tipo dado)
{
	if (!l)
		return -1;
	if (l->tamanho == 0)
		return -1;
	if (l->cabeca->info == dado)
		return 0;

	no_t *ptr;
	ptr = l->cabeca;

	for (int i = 0; i < l->tamanho; i++)
	{
		if (ptr->info == dado)
			return i;
		ptr = ptr->prx;
	}

	return -1;
}

//##########################################################

int lista_frequencia_info(lista_t *l, tipo dado)
{
	if (!l)
		return -1;
	if (l->tamanho == 0)
		return 0;

	no_t *ptr = l->cabeca;
	int count = 0;

	while (ptr){
		if (ptr->info == dado)
			count++;
		ptr = ptr->prx;
	}

	return count;
}

//##########################################################

int lista_ordenada(lista_t *l)
{
	if (!l)
		return -1;
	if (l->tamanho < 2)
		return 1;

	no_t *ptr;
	ptr = l->cabeca;

	for (int i = 0; i < (l->tamanho - 1); i++)
	{
		if (ptr->info > ptr->prx->info)
			return 0;
		ptr = ptr->prx;
	}

	return 1;
}

//##########################################################

int lista_insere_ordenado(lista_t *l, tipo dado)
{
	if (!l)
		return -1;

	if (l->tamanho == 0 || dado < l->cabeca->info)
	{
		lista_insere_cabeca(l, dado);
		return 1;
	}

	if (dado > l->cauda->info)
	{
		lista_insere_cauda(l, dado);
		return 1;
	}

	no_t *ptr;

	ptr = l->cabeca;
	for (int i = 0; i < l->tamanho; i++)
	{
		if (dado < ptr->info)
		{
			lista_insere_posicao(l, dado, i);
			return 1;
		}
		ptr = ptr->prx;
	}

	return -1;
}

//##########################################################

int lista_compara(lista_t *l1, lista_t *l2)
{
	if (!l1 && !l2)
		return 1;
	if (!l1 || !l2)
		return 0;
	if (l1->tamanho != l2->tamanho)
		return 0;

	no_t *ptr1 = l1->cabeca;
	no_t *ptr2 = l2->cabeca;

	for (int i = 0; i < l1->tamanho; i++)
	{
		if (ptr1->info != ptr2->info)
			return 0;
		ptr1 = ptr1->prx;
		ptr2 = ptr2->prx;
	}
	return 1;
}

//##########################################################

int lista_reverte(lista_t *l)
{
	if (!l)
		return -1;

	no_t *ptr;
	no_t *aux;
	no_t *seguinte = l->cabeca;

	for(int i=0; 	i<l->tamanho; 	i++)
	{
		ptr = seguinte;
		seguinte = seguinte->prx;
		aux = ptr->prx;
		ptr->prx = ptr->ant;
		ptr->ant = aux;
	}

	aux = l->cabeca;
	l->cabeca = l->cauda;
	l->cauda = aux;

	return 1;
}

//##########################################################

lista_t *lista_cria_copia(lista_t *l)
{
	if (!l)
		return NULL;
	lista_t *p = lista_cria();

	no_t *ptr = l->cabeca;

	for (int i = 0; i < l->tamanho; i++)
	{
		lista_insere_posicao(p, ptr->info, i);
		ptr = ptr->prx;
	}

	return p;
}

//##########################################################

int main()
{
	lista_t *p = lista_cria();

	//p->tamanho = 6;

	for(int i=4; i>0; i--)
		lista_insere_cabeca(p, i);


	lista_t *aux = lista_cria_copia(p);
    
    lista_destroi(&p);

	return 0;
}