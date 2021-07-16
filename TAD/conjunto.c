#include "conjunto_privado.h"
#include <stdio.h>
#include <stdlib.h>

conjunto_t *conjunto_cria(void){
	conjunto_t *p = (conjunto_t*) malloc( sizeof(conjunto_t) );
	if(!p) return NULL;
	p->capacidade = 10;
	p->numero = 0;
	p->vetor = (elem_t*)malloc(sizeof(elem_t)*(p->capacidade));
	return p;
}

//#################################################################

void conjunto_destroi(conjunto_t **a){
	if(!a) return;	//return;
	free((*a)->vetor);
	free(*a);
	*a = NULL;
}

//#################################################################

int conjunto_numero_elementos(conjunto_t *a){
	if(!a) return 0;
	int tam = a->numero;
	
	return tam;
}


//#################################################################

void conjunto_inicializa_vazio(conjunto_t *a){
    if(!a) return;
	a->numero=0;
}

//#################################################################

void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	if(a==NULL) return;
	if(b==NULL) return;
	if(c==NULL) return; 
	int tam_a = a->numero; 
	int tam_b = b->numero;

	c->numero = 0;

	for (int i=0; i<tam_a; i++){
		conjunto_insere_elemento(a->vetor[i], c);
	}

	for (int i=0; i<tam_b; i++){
		conjunto_insere_elemento(b->vetor[i], c);
	}
}

//#################################################################

void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	if(a==NULL) return;
	if(b==NULL) return;
	if(c==NULL) return;
	int tam_a = a->numero; 
	int tam_b = b->numero;

	c->numero = 0;


	for (int i=0; i<tam_a; i++){
		for (int j=0; j<tam_b; j++){
			if (a->vetor[i]==b->vetor[j]){
				conjunto_insere_elemento(a->vetor[i], c);
			}
		}		
	}
}

//#################################################################

void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
	if(a==NULL) return;
	if(b==NULL) return;
	if(c==NULL) return;
	int tam_a = a->numero;
	int tam_b = b->numero;

	int k=0;
	c->numero = 0;
	
	for (int i=0; i<tam_a; i++){
		k=0;
		for (int j=0; j<tam_b; j++){
			if (a->vetor[i]==b->vetor[j]) k=1;			
		}
		if (k==0){
			conjunto_insere_elemento(a->vetor[i], c);
		}
	}
}

//#################################################################

int conjunto_membro(elem_t x, conjunto_t *a){
	if (!a) return 0;

	int tam = a->numero;

	for (int i=0; i<tam; i++){
		if (a->vetor[i] == x) return 1;
	}

	return 0;
}

//#################################################################

int conjunto_insere_elemento(elem_t x, conjunto_t *a){
	if (!a) return 0;

	int tam = a->numero;
	for (int i=0; i<tam; i++){
		if (a->vetor[i] == x) return 1;
	}

	a->numero = a->numero + 1;
	if ( (a->capacidade) <= (a->numero) ){ 
		a->capacidade = a->capacidade + 1;
		a->vetor = (elem_t*)realloc(a->vetor, sizeof(elem_t)*(tam+1) ); // caso ja tenha espaco
	}
	a->vetor[tam] = x;

	return 1;
}

//#################################################################

void conjunto_remove_elemento(elem_t x, conjunto_t *a){
	if (!a) return;
	int tam = a->numero;
	int psc = tam;

	for (int i=0; i<tam; i++){
		if (a->vetor[i]==x) psc = i;
	}
	if (psc == tam) return;		//caso x nao esteja no vetor

	if (tam<2){
		a->numero = a->numero - 1;
		return;
	}

	for (int i=0; i<tam; i++){
		if (i>psc) a->vetor[i-1] = a->vetor[i];
	}
	
	a->numero = a->numero - 1;
}

//#################################################################

void conjunto_atribui(conjunto_t *a, conjunto_t *b){
	if (!a || !b) return;
	int tam_a = a->numero;
	//int tam_b = b->numero;

	b->vetor = (elem_t*) realloc(b->vetor, (sizeof(elem_t)*tam_a) );
	b->numero = a->numero;
	//if(b->numero>b->capacidade) b->capacidade = a->capacidade;
	
	for (int i=0; i<tam_a; i++){
		b->vetor[i] = a->vetor[i];
	}
}

//#################################################################

int conjunto_igual(conjunto_t *a, conjunto_t *b){
	if (!a || !b) return 0;
	if (a->numero != b->numero) return 0;
	int tam = a->numero;
	int k=0;

	for (int i=0; i<tam; i++){
		k=0;
		for (int j=0; j<tam; j++){
			if (a->vetor[i] == b->vetor[j]) k=1;
		}
		if (k==0) return 0;
	}

	return 1;	
}

//#################################################################

elem_t conjunto_minimo(conjunto_t *a){
	if (!a) return ELEM_MAX;
	int menor = a->vetor[0];
	int tam = a->numero;

	for (int i=0; i<tam; i++){
		if (a->vetor[i]<menor) menor = a->vetor[i];
	}
	return menor;
}

//#################################################################

elem_t conjunto_maximo(conjunto_t *a){
	if (!a) return ELEM_MIN;
	int maior = a->vetor[0];
	int tam = a->numero;

	for (int i=0; i<tam; i++){
		if (a->vetor[i]>maior) maior = a->vetor[i];
	}
	return maior;
}

//#################################################################

void conjunto_imprime(conjunto_t *a){
	if(!a) return;
	int tam = a->numero;
	int i=0;

	do{
		printf("%d ", a->vetor[i]);
		i++;
	}while(i<(tam-1));

	printf("%d\n", a->vetor[i]);
}

//#################################################################

int main(){

	return 0;

}