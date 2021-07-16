#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fs, *ft, *fp;
	fs = open("a.txt", "r");
	ft = open("b.txt", "r");
	fp = open("c.txt", "r");
	fclose(fp, fs, ft);		

	return 0;
}