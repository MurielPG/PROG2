#include <stdio.h>
#include <stdlib.h>


int div_com(int x, int y){
	
	if (x==0) return y;
	if (y==0) return x;
	if (x==y) return x;
	

	return div_com(y, x%y);
}




int main(){
	printf("%d", div_com(4, 7));

	return 0;
}