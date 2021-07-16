#include <stdio.h>
#include <string.h>


int str_reverse(char *str){
	int i, tam = strlen(str);
	char nova_string[tam];
	
	
	int cont = tam/2;

	for(i=1; i<=cont; i++){
		nova_string[i-1] = str[tam-i];
		nova_string[tam-i] = str[i-1];

		str[i-1] = nova_string[i-1];
		str[tam-i] = nova_string[tam-i];
	
	}

	printf("%s\n", str);
	

	return 1;
}


int main() {
    
        char frase[] = "rosquero";	//???caso sejam diferentes???		

    
        str_reverse(frase);
        
        
        return 0;
}