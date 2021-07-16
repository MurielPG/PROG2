#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_compare(const char *stra, const char *strb) {
    int tam_a = strlen(stra);
    int tam_b = strlen(strb);
    if(tam_a>tam_b) return +1;
    if(tam_a<tam_b) return -1;


    for(int i=0; i<tam_a; i++){
        if((*stra + i) < (*strb + i))return -1;
        if((*stra + i) > (*strb + i))return +1;
    }
    return 0;
    
}


int main(){
	char frase[]="abacaxi";
    char frase2[]="abacaxi";
	
	printf("%d" ,str_compare(frase, frase2) );

	
    return 0;
}