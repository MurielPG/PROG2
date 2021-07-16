#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int 			cestas;
	int 			arremessos;	
	float			percentual;
} arremessos_t;



typedef struct {
	char 			nome[128];   // Nome
	int  			idade;       // Idade
	char 			time[16]; 	 // Sigla do time
	char 			posicao[8];	 // Sigla da posição	
	int  			jogos; 		 // Número de jogos
	int  			minutos;     // Número de minutos jogados
	int 			pontos;      // Total de pontos feitos
	
	arremessos_t 	a2;			 // Estatísticas de arremessos de 2 pontos	
	arremessos_t 	a3;			 // Estatísticas de arremessos de 3 pontos	
	arremessos_t 	aT;			 // Estatística combinada de arremessos de 2 e 3 pontos	
	arremessos_t 	aL;			 // Estatísticas de arremessos livres (lances livres)
} jogador_t;




int le_cabecario (char *nome){

	if(nome==NULL) return -1;

	FILE *arq = fopen(nome, "rb");

	if(!arq) return 0;

	int num;

	fread(&num, sizeof(int), 1, arq);
	fclose(arq);

	return num;
}

//#######################################################################

jogador_t* le_jogadores (char *nome, int *njogadores){

	if( nome==NULL || njogadores==NULL ) return NULL;

	FILE *arq = fopen(nome, "rb");
	if(!arq) return NULL;
	fread(njogadores, sizeof(int), 1, arq);	

	jogador_t *jog =(jogador_t*) malloc(sizeof(jogador_t) * (*njogadores) );
							   
	fread(jog, sizeof(jogador_t), *njogadores, arq);


	fclose(arq);

	return jog;
}

//#######################################################################

int statj_mais_arremessos (jogador_t *jogadores, int njogadores, char tipo){

if( jogadores==NULL ) return -1;

	if( tipo != '2' && tipo != '3' && tipo != 'T' && tipo != 'L' ) return -2;
		
	int maior_arremesso = jogadores[0].a2.arremessos;
	int indice_jogador;


	for (int i=0; i<njogadores; i++){

		if(jogadores[i].a2.arremessos > maior_arremesso	&& tipo=='2'){
			maior_arremesso = jogadores[i].a2.arremessos;
			indice_jogador = i;
		}

		if(jogadores[i].a3.arremessos > maior_arremesso	&& tipo=='3'){
			maior_arremesso = jogadores[i].a3.arremessos;
			indice_jogador = i;
		}

		if(jogadores[i].aT.arremessos > maior_arremesso	&& tipo=='T'){
			maior_arremesso = jogadores[i].aT.arremessos;
			indice_jogador = i;
		}

		if(jogadores[i].aL.arremessos > maior_arremesso	&& tipo=='L'){
			maior_arremesso = jogadores[i].aL.arremessos;
			indice_jogador = i;
		}
	}

	return indice_jogador;

}

//#######################################################################

int statj_mais_cestas (jogador_t *jogadores, int njogadores, char tipo){

	if( jogadores==NULL ) return -1;

	if( tipo != '2' && tipo != '3' && tipo != 'T' && tipo != 'L' ) return -2;
		
	int maior_cesta = jogadores[0].a2.cestas;
	int indice_jogador;


	for (int i=0; i<njogadores; i++){

		if(jogadores[i].a2.cestas > maior_cesta	&& tipo=='2'){
			maior_cesta = jogadores[i].a2.cestas;
			indice_jogador = i;
		}

		if(jogadores[i].a3.cestas > maior_cesta	&& tipo=='3'){
			maior_cesta = jogadores[i].a3.cestas;
			indice_jogador = i;
		}

		if(jogadores[i].aT.cestas > maior_cesta	&& tipo=='T'){
			maior_cesta = jogadores[i].aT.cestas;
			indice_jogador = i;
		}

		if(jogadores[i].aL.cestas > maior_cesta	&& tipo=='L'){
			maior_cesta = jogadores[i].aL.cestas;
			indice_jogador = i;
		}
	}

	return indice_jogador;
}

//#######################################################################

int statj_melhor_percentual (jogador_t *jogadores, int njogadores, char tipo){
	
	if( jogadores==NULL ) return -1;

	if( tipo != '2' && tipo != '3' && tipo != 'T' && tipo != 'L' ) return -2;
		
	float maior_percentual = 0.0;
	int indice_jogador;

	for (int i=0; i<njogadores; i++){

		if(jogadores[i].a2.percentual > maior_percentual	&& tipo=='2'){
			maior_percentual = jogadores[i].a2.percentual;
			indice_jogador = i;
		}

		if(jogadores[i].a3.percentual > maior_percentual	&& tipo=='3'){
			maior_percentual = jogadores[i].a3.percentual;
			indice_jogador = i;
		}

		if(jogadores[i].aT.percentual > maior_percentual	&& tipo=='T'){
			maior_percentual = jogadores[i].aT.percentual;
			indice_jogador = i;
		}

		if(jogadores[i].aL.percentual > maior_percentual	&& tipo=='L'){
			maior_percentual = jogadores[i].aL.percentual;
			indice_jogador = i;
		}
	}
	
	return indice_jogador;
}

//#######################################################################

int statj_jogos (jogador_t *jogadores, int njogadores, char tipo){

	if( jogadores==NULL ) return -1;
	if(tipo != '-' && tipo != '+') return -2;

	int mais_jogos = jogadores[0].jogos;
	int menos_jogos = jogadores[0].jogos;
	int indice_jogador;


	if(tipo=='+')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].jogos > mais_jogos){
				mais_jogos = jogadores[i].jogos;
				indice_jogador = i;
			}
	};

	if(tipo=='-')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].jogos < menos_jogos){
				menos_jogos = jogadores[i].jogos;
				indice_jogador = i;
			}
	};

	//printf("%i \n%i\n%s\n", indice_jogador, menos_jogos, jogadores[indice_jogador].nome);

	return indice_jogador;
}

//#######################################################################

int statj_idade (jogador_t *jogadores, int njogadores, char tipo){
	if( jogadores==NULL ) return -1;
	if(tipo != '-' && tipo != '+') return -2;

	int mais_idade = jogadores[0].idade;
	int menos_idade = jogadores[0].idade;
	int indice_jogador;

	if(tipo=='+')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].idade > mais_idade){
				mais_idade = jogadores[i].idade;
				indice_jogador = i;
			}
		};

	if(tipo=='-')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].idade < menos_idade){
				menos_idade = jogadores[i].idade;
				indice_jogador = i;
			}
	};

	//printf("%i \n%i\n%s\n", indice_jogador, mais_idade, jogadores[indice_jogador].nome);

	return indice_jogador;
}

//#######################################################################

int statj_minutos (jogador_t *jogadores, int njogadores, char tipo){
	if( jogadores==NULL ) return -1;
	if(tipo != '-' && tipo != '+') return -2;

	int mais_minutos = jogadores[0].minutos;
	int menos_minutos = jogadores[0].minutos;
	int indice_jogador;

	if(tipo=='+')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].minutos > mais_minutos){
				mais_minutos = jogadores[i].minutos;
				indice_jogador = i;
			}
		};

	if(tipo=='-')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].minutos < menos_minutos){
				menos_minutos = jogadores[i].minutos;
				indice_jogador = i;
			}
	};

	return indice_jogador;
}

//#######################################################################

int statj_pontos (jogador_t *jogadores, int njogadores, char tipo){

	if( jogadores==NULL ) return -1;
	if(tipo != '-' && tipo != '+') return -2;

	int mais_pontos = jogadores[0].pontos;
	int menos_pontos = jogadores[0].pontos;
	int indice_jogador;

	if(tipo=='+')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].pontos > mais_pontos){
				mais_pontos = jogadores[i].pontos;
				indice_jogador = i;
			}
		};

	if(tipo=='-')
		for (int i=0; i<njogadores; i++){
			if(jogadores[i].pontos < menos_pontos){
				menos_pontos = jogadores[i].pontos;
				indice_jogador = i;
			}
	};

	return indice_jogador;
}

//#######################################################################
//					Estatísticas de Times
//#######################################################################

int statt_soma_pontos (jogador_t *jogadores, int njogadores, char* time){

	if( jogadores==NULL || time==NULL ) return -1;
	int soma=0;
//	printf("%d\n", njogadores);

	for (int i=0; i<njogadores; i++){
		
		if( !strcmp( time, jogadores[i].time ) ){
			soma += jogadores[i].pontos;
		}
	}
	if(soma == 0) return 0;

	return soma;
}

//#######################################################################

float statt_media_pontos (jogador_t *jogadores, int njogadores, char* time){
	if(jogadores==NULL || time==NULL) return -1;
	int soma=0, contador=0;
	float media;

	for (int i=0; i<njogadores; i++){
		if( !strcmp( time, jogadores[i].time ) ){
			soma += jogadores[i].pontos;
			contador++;			//se contador for 0???
		}
	}

	if(contador == 0)return 0; //time sem jogador????
	
	media = (float)soma / (float)contador;

	return media;
}

//#######################################################################

float statt_media_idade (jogador_t *jogadores, int njogadores, char* time){
	
	if(jogadores==NULL || time==NULL) return -1;
		int soma=0, contador=0;
		float media;

		for (int i=0; i<njogadores; i++){
			if( !strcmp( time, jogadores[i].time ) ){
				soma += jogadores[i].idade;
				contador++;			
			}
		}

	if(contador == 0)return 0;
	
	media = (float)soma / (float)contador;

	return media;
}

//#######################################################################

int statt_posicao (jogador_t *jogadores, int njogadores, char *time, char* posicao){

	if(jogadores==NULL || time==NULL || posicao==NULL) return -1;
	int jg_na_posicao=0;

	for (int i=0; i<njogadores; i++){
		if( !strcmp( time, jogadores[i].time ) ){
			if ( !strcmp(posicao, jogadores[i].posicao ) )
				jg_na_posicao++;
		}
	}

//	printf("%d", jg_na_posicao);
	return jg_na_posicao;


}

//#######################################################################




int main(){
	char nome_arq[] = "jogadores.dat";
	char tipo_cesta[] = "CHO";
	char posicionamento[] = "C";


	int numero_jogadores = le_cabecario(nome_arq);

	 jogador_t* jdores = le_jogadores(nome_arq, &numero_jogadores);

	// statj_mais_cestas(jdores , numero_jogadores, tipo_cesta);

	// statj_mais_arremessos(jdores , numero_jogadores, tipo_cesta);

	//statj_melhor_percentual (jdores, numero_jogadores, tipo_cesta);

	//statj_jogos (jdores, numero_jogadores, tipo_cesta);

	//statj_idade (jdores, numero_jogadores, tipo_cesta);

	//statj_minutos (jdores, numero_jogadores, tipo_cesta);

	//statj_pontos (jdores, numero_jogadores, tipo_cesta);

	//statt_soma_pontos (jdores, numero_jogadores, tipo_cesta);

	//statt_media_pontos (jdores, numero_jogadores, tipo_cesta);

	//statt_media_idade (jdores, numero_jogadores, tipo_cesta);

	//statt_posicao (jdores, numero_jogadores, tipo_cesta, posicionamento);


	return 0;
}