#include <stdio.h> 
#include <stdlib.h>

/* I N T E R S E C C A O */
int main() 
{ 
	int avetor[] = {1,2,8,4,5};
	int bvetor[] = {1,2,3,4,5};
	int tam_a = sizeof avetor / sizeof avetor[0];
	int tam_b = sizeof bvetor / sizeof bvetor[0];
	int k=0;

	for (int i=0; i<tam_a; i++){
		k=0;
		for (int j=0; j<tam_b; j++){
			if (avetor[i] == bvetor[j]) k=1;
		}
		if (k==0) return 0;
	}

	return 1;

}
