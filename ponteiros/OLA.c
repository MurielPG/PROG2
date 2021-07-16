#include <stdio.h>
#include <string.h>

int confere_numero(char num[])
{
	int tam = strlen(num);
	if( (tam<5) && ((num[0]=='o'&&num[1]=='n') || (num[1]=='n'&&num[2]=='e') || (num[2]=='e'&&num[0]=='o'))) return 1;
    if( (tam<5) && ((num[0]=='t'&&num[1]=='w') || (num[1]=='w'&&num[2]=='o') || (num[2]=='o'&&num[0]=='t'))) return 2;
    if(				(num[0]=='t'&&num[4]=='e') || (num[1]=='h'&&num[2]=='r') || (num[2]=='r'&&num[0]=='t')) return 3;
    return 0;
}


int main()
{
	char num[6] = "\0";

	while(fgets(num, 6, stdin))
	{
		int conferido = confere_numero(num);
		if(conferido>0)printf("%i", conferido);
	}
	return 0;
}