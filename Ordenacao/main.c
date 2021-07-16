#include "funcao.h"
#include <ctype.h>
#include <stdlib.h>


//Implemente suas funcoes aqui



int ordena(int *v, unsigned int t)
{
	//buble sort
	if (v==NULL) return 0;
	if (t==0) return 0;

	int k=2;
	for (int i=0; i < t; i++)
	{
		if (k==0) return 1;
		k=0;
		for (int j=1; j < t; j++)
		{
			if ( v[j-1] > v[j] )
			{
				int aux = v[j-1];
				v[j-1] = v[j];
				v[j] = aux;
				k=1;
			}
		}
	}

	return 1;
}