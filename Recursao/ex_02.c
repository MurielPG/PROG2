#include <stdio.h>
#include <stdlib.h>


int imp_val(int n1, int n2){
	n1++;
	if(n2<=n1) return 0;
	//printf("%d", (n1));
	return imp_val(n1, n2);
}

int main(){
	imp_val(1,3);
	return 0;
}