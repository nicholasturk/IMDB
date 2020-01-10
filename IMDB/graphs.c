/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

	char buffer[256];
	FILE *fp = fopen("input-graphs.txt", r);

	fgets(buffer, 256, fp);

	printf("%s\n", buffer);

}

