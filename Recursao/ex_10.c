#include <stdio.h>
#include <stdlib.h>

int multiplica(int num1, int num2){
	if (num1 == 0 || num2 == 0) return 0;
	num2--;
	return num1 + multiplica(num1, num2);
}

int main(){
	printf("%d\n", multiplica(5, 3) );
	return 0;
}