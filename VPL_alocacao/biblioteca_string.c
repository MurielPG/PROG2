

#include <stdio.h>

//FUNCAO TAMANHO STRING
//#LEMBRAR# CORRIGIR NOME DAS FUNCOES PARA MOODLE
//LIMPAR MEMORIA
#include <stdlib.h>

int str_length(const char *str){
	int i=0;

	if(str == NULL) return (-1);

	while( *(str+i) != '\0') i++;

	//nao consegue calcular tamanho de string nao declarada

	return i;
}

//############################################################

char* str_duplicate(const char *str){
	int i=0;
	char *ponteiro;

	if(str==NULL) return NULL;
	

	ponteiro = (char*) malloc( sizeof(char)* (str_length(str)+1) );

	do{
		ponteiro[i] = str[i];
		i++;
	}while(*(str+i) != '\0');		//usar for

	return ponteiro;
}	//LIBERAR MEMORIA DO PONTEIRO!!!!

//############################################################

int str_compare(const char *stra, const char *strb) {
    int tam_a = str_length(stra);

    for(int i=0; i<=tam_a; i++){
        if(*(stra + i) < *(strb + i))return -1;
        if(*(stra + i) > *(strb + i))return +1;
        
    }
    return 0;
    
}

//#############################################################

int str_reverse(char *str){
	int i, tam = str_length(str);
	char nova_string[tam];

	if(str == NULL) return 0;

	for(i=1; i<=tam; i++){
		nova_string[i-1] = str[tam-i];	//passa os carac pra uma
	}	

	for(i=0; i<tam; i++){				//retorna pra mesma
		str[i] = nova_string[i];
	}
	

	return 1;
}	
	//e se nao conseguir reverter a string?

//############################################################

int str_upper(char *str){
	if(str == NULL) return (-1);
	int i, tam = str_length(str), contador = 0;


	for(i=0; i <=tam; i++) {
        if(*(str+i) >= 97 && *(str+i) <= 122) { //97 = "a" e 122 = "z"
            *(str+i) = *(str+i) - 32;
        contador++;
        }  
    }

    return contador;
	//e se tiver um caracter fora do range?

}


//############################################################

int str_lower (char *str){
	if(str == NULL) return (-1);
	int i, tam = str_length(str), contador = 0;

	for(i=0; i <=tam; i++) {
        if(*(str+i) >= 65 && *(str+i) <= 90) { //65 = 'A' e 90 = "Z"
            *(str+i) = *(str+i) + 32;
        contador++;
        }  
    }

    return contador;
}

//############################################################

int str_copy (char *dst, const char *src){
	
	if( dst==NULL || src==NULL ) return -1;
	if( str_length(dst) < (str_length(src) ) ) return 0;
	
	int tam = str_length(src);

	for(int i=0; i<=tam; i++){
		dst[i]=src[i];
	}

	return 1;
}

//############################################################

char* str_concatenate(const char *stra, const char *strb){
	char *concatenadas;
	int i=0;
	int tam_a = str_length(stra);
	int tam_b = str_length(strb);
	int total = tam_a + tam_b;

	if(stra == NULL || strb == NULL){	
		if(stra==NULL && strb == NULL) return NULL;
			
		

		if(strb==NULL){
			concatenadas = (char*) malloc( sizeof(char)* (str_length(stra)+1) );	//se a segunda e NULL, copia a primeira
			
			for(i=0; i<=tam_a; i++){
								
				concatenadas[i]=stra[i];		//i logo depois do (DO)
			}

			return concatenadas;
		}

		else{
			concatenadas = (char*) malloc( sizeof(char)* (str_length(strb)+1) );	//primeira NULL copia a segunda
			
			for(i=0; i<=tam_b; i++){
				concatenadas[i]=strb[i];
			}
			return	concatenadas;
	}
}
	
	concatenadas = (char*) malloc( sizeof(char)*(total+1) );	//alocar memoria para o \0

	//char tem 1 byte, nao precisa declarar

	for(i=0; i<tam_a; i++){
		concatenadas[i] = stra[i];
	}


	for(int j=0; j<=tam_b; j++){
		concatenadas[i] = strb[j];
		i++;		
	}
	

	
	return concatenadas;		//limpar memoria!!!!!!!!!!

}


//############################################################

int str_find_first(const char *str, const char c){
	if(str==NULL) return -1;

 	int	tam = str_length(str);

 	for(int i=0; i<tam; i++){
 		if(str[i] == c) return i;
 	} 

 	return -1;
}

//############################################################

int str_find_last(const char *str, const char c){
	if(str==NULL) return -1;
	

 	int	i = str_length(str);
 	i--;

 	do{
 		
 		if(str[i] == c) return i; 	
 		i--;	
 	}while(i>=0);

 	return -1;
}


//############################################################
int str_count_words(const char *str){
	if(str==NULL) return -1;
	int cont_palavra = 0;
	int i = 0, j = 0;

 	while(str[i] != '\0'){

 		while(str[i] != ' ' && str[i] != '\0'){
 			j = 1;
 			i++;
 		}

 		if(j==1){
 			cont_palavra++;
 			j = 0;
 			continue;
 		}
 		i++;

 	}

 	return cont_palavra;
}




//############################################################


int main(){
	char frase[] = "PRIMEIRO_";
	char frase2[] = "SEGUNDO";
	char copiada[] = "STR";	//ver str_lenght
	char ocorrencia = 'd';
	printf("%d", str_length(copiada));
	
	char *recebida = str_duplicate(frase);	
	printf("%s", recebida);
	free(recebida);

	int comp = str_compare(frase, frase2);
	
	
	int rev = str_reverse(frase);	//OK

	int a = str_upper(frase);	//OK	
	printf("%d", a);

	int b = str_lower(frase);	//OK
	printf("%d", b);

	printf("%d", str_copy(copiada, frase) ); //OK

	char *_string = str_concatenate(frase, frase2);		//OK
	printf("%s", _string);
	
	printf("%d", str_find_first(frase, ocorrencia) );

	printf("%d", str_find_last(frase, ocorrencia) );

	printf("%d", str_count_words(frase));

	free(recebida);
	free(_string);
	return 0;

}