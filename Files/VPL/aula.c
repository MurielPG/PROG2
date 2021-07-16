#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *abre_arquivo(const char *arquivo){	//recebe o nome do arquivo
	if(!arquivo) return NULL;
	FILE *arq = fopen(arquivo, "r");
	if(!arq) return NULL;
	return arq;
}
//################################################

int fecha_arquivo(FILE *arq){
	if (!arq) return 1;
	fclose(arq);
	return 0;
}

//################################################

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
	if(!qtd_numeros) return NULL;
	
	FILE *arq = abre_arquivo(arquivo);
	
	if(!arq){
		*qtd_numeros = 0;
		return NULL;
	}
	
	int i=0;


	double *valores=NULL; //=  (double*) malloc( sizeof(double) );
	
	do{

		i++;
		valores = (double *) realloc( valores, sizeof(double)*i); //i nao pdoe ser 0, segmentation fault
		fscanf(arq , "%lf", &valores[i-1]);
	

	}while(!feof(arq));

	
	*qtd_numeros = (i-1);

	fclose(arq);	
	
	return valores;
}

//################################################

double maior(double* valores, unsigned int qtd_numeros){
	if(!valores) return HUGE_VAL;
	int i=qtd_numeros-1;				//i ultimo index
	double maior = valores[i];	

	do{
		i--;
		if(valores[i]>maior)
			maior = valores[i];		
	}while(i!=0);

	return maior;
}

//################################################

double menor(double* valores, unsigned int qtd_numeros){
	if(!valores) return HUGE_VAL;
	int i=qtd_numeros-1;				//i ultimo index
	double menor = valores[i];

	do{
		i--;
		if(valores[i]<menor)
			menor = valores[i];		
	}while(i!=0);

	return menor;
}

//################################################

double media(double* valores, unsigned int qtd_numeros){
	if(!valores) return HUGE_VAL;
	double media = 0;
	int i=0;

	do{
		i++;
		media += valores[i-1];
	}while((i)!=qtd_numeros);

	media = media / qtd_numeros;

	return media;
}

//################################################

double desvio(double* valores, unsigned int qtd_numeros){
	if(!valores) return HUGE_VAL;
	double _media = media(valores, qtd_numeros);
	double soma = 0;
	int i=0;

	do{
		i++;
		soma = soma + pow((valores[i-1]-_media), 2)/(qtd_numeros-1);
	}while(i!=qtd_numeros);

	double desv_pad = sqrt(soma);

	return desv_pad;
}

//################################################

double amplitude(double* valores, unsigned int qtd_numeros){
	if(!valores) return HUGE_VAL;
	double _menor = menor(valores, qtd_numeros);
	double _maior = maior(valores, qtd_numeros);

	double amp = _maior - _menor;

	return amp;
}

//################################################

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
	if(!valores) return HUGE_VAL;
	if( posicao>=qtd_numeros ) return HUGE_VAL;

	double posicionado = valores[posicao];

	return posicionado;
}

//################################################

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
	if(!qtd_repeticao) return HUGE_VAL;

	if(!valores){
		*qtd_repeticao = 0;
		return HUGE_VAL;
	}
	
	int rep = 0, num_rep=0;
	double  val_rptd = valores[0];

	for (int i=0; i<qtd_numeros; i++){
		for (int j=0; j<qtd_numeros; j++){

			if( valores[i]==valores[j]){	
				rep++;										//testa quantas vezes o valor se repete
			}
		}

		if(rep>num_rep) {						//compara com o maior numero de repeticoes
			num_rep = rep;						
			val_rptd = valores[i];
		}
		rep=0;									//rep 0 para um novo loop
	}
	*qtd_repeticao = (unsigned int) num_rep;

	return val_rptd;
}

//################################################



int main(){
	char arquivo[] = "arquivo.txt";

	//FILE *arq_receb = abre_arquivo(arquivo);

	//fecha_arquivo(arq_receb);

	unsigned int num;
	unsigned int pos = 2;
	unsigned int qtd_rep;

	double *_lidos = le_valores(arquivo, &num);
	for(int i=0; i<20; i++){
		printf("%lf\n", _lidos[i]);}

	// double maior_val = maior(_lidos, num);
	// printf("MAIOR: %lf\n", maior_val);

	// double menor_val = menor(_lidos, num);
	// printf("MENOR%lf", menor_val);

	// double media_val = media(_lidos, num);
	// printf("MEDIA:%lf\n", media_val);

	// double desv_val = desvio(_lidos, num);
	// printf("%lf\n", desv_val);

	// double amp_val =  amplitude(_lidos, num);
	// printf("%lf", amp_val);

	// double pos_val = valor(_lidos, num, pos);
	// printf("%lf", pos_val);

	// double rep_val = repetido(_lidos, num, &qtd_rep);
	// printf("\n\n>%lf", rep_val);




	free(_lidos);


	return 0;
}