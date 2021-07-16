#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// typedef struct no{
// 	int valor;			//valor conteiner
// 	struct no *prx;			//conteiner seguinte
// }no_t;

// typedef struct pilha{
// 	no_t *cabeca;		//primeiro conteiner/conjunto
// }pilha_t;


//#################################################

pilha_t* cria_pilha(int valor)
{
	pilha_t *p = (pilha_t*)malloc(sizeof(pilha_t));
	no_t    *no = (no_t*)malloc(sizeof(no_t));

	p->cabeca = no;
	no->valor = valor;
	no->prx = NULL;

	return p;
}

//#################################################

void pilha_destroi(pilha_t **vp, int tam)
{
	for (int i=0; i<tam;	i++)
	{
		no_t* aux = vp[i]->cabeca;
		while (aux)
		{
			no_t* ant = aux;
			aux = aux->prx;
			free(ant);
		}
	}
	free(*vp);
	*vp = NULL;

	return;
}

//#################################################

void decide_funcao(pilha_t **vp, char *str1, char *str2, int mover, int base, int tam)
{
	char mova[] = "mova", sobre[] = "sobre";
	if (!strncmp(str1, mova, 3)){
		if (!strncmp(str2, sobre, 3))		
			mova_sobre(vp,  mover,  base, tam);			//mova sobre
		else
			mova_topo(vp,  mover,  base, tam);			//mova topo
	}else{								
		if(!strncmp(str2, sobre, 3))		
			empilhe_sobre(vp,  mover,  base, tam);		//empilhe sobre
		else
			empilhe_topo(vp,  mover,  base, tam);		//empilhe topo
	}
}

//#################################################

int encontra_index(pilha_t **vp, int valor, int tam)
{
	no_t* aux;
	for (int i=0;	i<tam;	i++)
	{
		aux = vp[i]->cabeca;
		while (aux){
			if (aux->valor == valor)
				return i;
			aux = aux->prx;
		}
	}
	return 0;
}

//#################################################

void mova_sobre(pilha_t **vp, int mover, int base, int tam)
{
	int i = encontra_index(vp, base, tam);
	int j = encontra_index(vp, mover, tam);
	//if (i==j) return;

	no_t* fixo = posiciona_no_anterior(vp, i, base);
	no_t* move = posiciona_no_anterior(vp, j, mover);

	if (fixo->prx != NULL){
		fixo = fixo->prx;
		retorna_origem(vp, fixo);
	}
	if (move->prx != NULL){
		no_t* aux = move;
		move = move->prx;
		retorna_origem(vp, move);
		aux->prx = NULL;
	}else
		vp[move->valor]->cabeca = NULL;

	fixo->prx = move;

	return;
}

//#################################################

void mova_topo(pilha_t **vp, int mover, int base, int tam)
{
	int i = encontra_index(vp, base, tam);
	int j = encontra_index(vp, mover, tam);
	//if (i==j) return;

	no_t* fixo = posiciona_no_anterior(vp, i, base);
	no_t* move = posiciona_no_anterior(vp, j, mover);
	

	while (fixo->prx != NULL)
		fixo = fixo->prx;

	if (move->prx != NULL && move->valor != j){						//se nao for cabeca
		no_t* aux = move;
		move = move->prx;
		retorna_origem(vp, move);
		aux->prx = NULL;				//ponto anterior ao container movido
	}
	else
		vp[move->valor]->cabeca = NULL;		//considera cabeca
	
	fixo->prx = move;

	return;
}

//#################################################

no_t* posiciona_no_anterior(pilha_t **vp, int i, int dado)
{
	if (vp[i]->cabeca->valor == dado)
		return vp[i]->cabeca;

	no_t* aux = vp[i]->cabeca;
	no_t* ant = aux;

	while (aux->valor != dado)
	{
		ant = aux;
		aux = aux->prx;
	}
	return ant;
}

//#################################################

void retorna_origem(pilha_t **vp, no_t* no)	//no anterior ao que eu quero retornar
{											//esse no NAO sera retornado
	
	no_t* aux = no;
	no = no->prx;
	aux->prx = NULL;				
	if (no==NULL)return;
	
	while(no)
	{
		aux = no;
		no = no->prx;
		aux->prx = NULL;
		vp[aux->valor]->cabeca = aux;
	}
	//vp[no->valor]->cabeca = no;
}

//#################################################

void empilhe_sobre(pilha_t **vp, int mover, int base, int tam)
{
	int i = encontra_index(vp, base, tam);
	int j = encontra_index(vp, mover, tam);

	//if (i==j) return; //caso so dois estejam na mesma pilha

	no_t* fixo = posiciona_no_anterior(vp, i, base);
	no_t* move = posiciona_no_anterior(vp, j, mover);
	if(fixo->prx != NULL){		//se n for cabeca
		fixo = fixo->prx;
		retorna_origem(vp, fixo);
	}

	no_t* aux = move;
	if (move->prx != NULL)
		move = move->prx;
	if (move->valor == j)			
		vp[j]->cabeca = NULL;
	else
		aux->prx = NULL;

	fixo->prx = move;
}

//#################################################

void empilhe_topo(pilha_t **vp, int mover, int base, int tam)
{
	int i = encontra_index(vp, base, tam);
	int j = encontra_index(vp, mover, tam);

	if (i==j) return;

	no_t* fixo = posiciona_no_anterior(vp, i, base);
	no_t* move = posiciona_no_anterior(vp, j, mover);
	no_t* aux = move;

	if(move == vp[j]->cabeca){
		vp[j]->cabeca = NULL;
	}else{
		move = move->prx;
		aux->prx = NULL;
	}

	while(fixo->prx)
		fixo = fixo->prx;			//ultimo no da pilha

	fixo->prx = move;

	return;
}

//#################################################

void imprime_resultado(pilha_t **vp, int tam)
{
	no_t* aux;
	for (int i=0;	i<tam;	i++)
	{
		printf("%d:", i);	
		aux = vp[i]->cabeca;
		while(aux){
			printf(" %d", aux->valor);
			aux = aux->prx;
		}
		printf("\n");
	}
}

//#################################################
// int main()
// {
// 	char str1[10],str2[10], sair[] = "sair";

// 	int move, base,tamanho;

// 	scanf("%d", &tamanho);
// 	pilha_t *vp[tamanho];
// 	for (int i=0;	i<tamanho;	i++)
// 		vp[i] = cria_pilha(i);

// 	do{
// 		scanf("%s %d %s %d", str1, &move, str2, &base);

// 		decide_funcao(vp, str1, str2, move, base, tamanho);
// 	}while (strncmp(str1, sair, 4));

// 	imprime_resultado(vp, tamanho);
// 	pilha_destroi(vp,tamanho);



// 	return 0;
// }

//#########################33

int main()
{
	char str[100], str1[10],str2[10], sair[] = "sair";

	int move, base,tamanho;

	scanf("%d", &tamanho);
	pilha_t *vp[tamanho];
	for (int i=0;	i<tamanho;	i++)
		vp[i] = cria_pilha(i);

	do{
		fgets(str, 100, stdin);
		if (!strncmp(str1, sair, 4)) break;
		sscanf(str, "%s %d %s %d", str1, &move, str2, &base);

		decide_funcao(vp, str1, str2, move, base, tamanho);
		imprime_resultado(vp, tamanho);
		
	}while (strncmp(str1, sair, 4));

	printf("\n\n--------------------------------------------------\n\n");
	imprime_resultado(vp, tamanho);
	pilha_destroi(vp,tamanho);



	return 0;
}
