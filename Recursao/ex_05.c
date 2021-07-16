#include <stdio.h>
#include <stdlib.h>


float expo(float base, float ex){
	if (ex == 0 ) return 1;
	if (base == 0 ) return 0;
	ex--;
	return base*expo(base, ex);
}


int main(){
	printf("%.2f", expo(5, 2) );
	return 0;
}