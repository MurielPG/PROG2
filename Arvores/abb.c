#include "abb_privado.h"

#include <stdlib.h>
#include <stdio.h>

/* Coloque abaixo as suas implementações */

abb_t*		abb_cria		()
{
	abb_t *arv = (abb_t*)malloc(sizeof(abb_t));
	if (arv==NULL) return NULL;
	arv->raiz = NULL;
	return arv;
}

//################################################

void		abb_destroi		(abb_t **arv)
{
	if (*arv == NULL) return;

	abb_destroi_rec((*arv)->raiz);
	free(*arv);
	*arv = NULL;

	return;
}

//################################################

int 		abb_insere		(abb_t *arv, elem_t chave)
{
	return 0;
}

//################################################

int 		abb_remove		(abb_t *arv, elem_t chave)
{
	return 0;
}

//################################################

int 		abb_busca  		(abb_t *arv, elem_t chave)
{
	// if (arv->raiz == NULL) return;
	// if (arv->raiz->chave == chave) return 1
	// abb_busca(arv->raiz->esq);
	// abb_busca(arv->raiz->dir);

	return 0;
}


