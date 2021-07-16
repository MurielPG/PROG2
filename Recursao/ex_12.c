#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conf_pal(char palavra[], int tam, int i){
	if (!palavra) return 0;
	if (palavra[i] != palavra[tam-1]) return 0;
	if (i-tam==0 || tam-i<0) return 1; 	//se ate chegar no meio nao retornou 0 quer dizer q e palindromo!
										
	i++;
	tam--;

	return conf_pal(palavra, tam, i); 
}




int main(){
	char palavra[] = "TENET";
	int tam = sizeof palavra / sizeof palavra[0] - 1;
	int i=0;
	printf("%d", conf_pal(palavra, tam, i) );
	return 0;
}