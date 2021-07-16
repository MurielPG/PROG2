#include <stdio.h>
#include <string.h>

//	gcc latex.c -o ex
// 	./ex < input_latex.txt

int alterar_aspas(char frase[], int seg_aspas)
{
	int tam = strlen(frase);
	char nova_frase[100] = "\0", acentos[] = "``", simples[] = "''";
	int i=0, j=0, aspas=0;
	aspas = seg_aspas;						//seg_aspas serve para caso tenha mais de uma aspas em cada frase, e caso comece e termine em frases diferentes
	do
	{
		tam--;
		if(frase[j] == '\"' && aspas == 0)	//aspas = 0, significa que eh o primeiro acento
		{
			strcat(nova_frase, acentos);
			j++;
			i = i + 2;
			aspas = 1;						//ja nao eh mais o primeiro acento
			seg_aspas = 1;
		}
		
		if(frase[j] == '\"' && aspas == 1)
		{
			strcat(nova_frase, simples);
			j++;
			i = i + 2;						//pula as duas casas dos acentos/aspas
			aspas = 0;						//caso tenha mais aspas ao longo da string
			seg_aspas = 0;
		}

		else{
		nova_frase[i] = frase[j];			//so copia os caracter pra nova string
		i++;
		j++;
		}

	}while(tam>0);							//tamanho da string como condicao
	
	printf("%s", nova_frase);
	return seg_aspas;
}


int main(){
	char frase[100]="\0", aspas = 0;
	
	while(fgets(frase, 100, stdin))			//while le string e chama funcao
	{
		aspas = alterar_aspas(frase, aspas);
	}

return 0;
}