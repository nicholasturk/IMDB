/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/

#include "common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_column(char *string, int number){

	int i = 0, start = 0, end = 0, length = 0, tabCount = 0;
	char *temp;

	while(tabCount < number){
		if(string[i] == '\0'){
			break;
		}

		if((string[i]) == '\t' || string[i] == '\n'){
			tabCount ++;
			if(tabCount == (number - 1)){
				start = i;
			} else if(tabCount == (number)){
				end = i;
			}
		}
		i++;
	}

	if(start != 0){
		start++;
	} 

	length = end - start;
	
	temp = malloc(sizeof(char) * length + 1);
	strncpy(temp, string + start, length);
	temp[strlen(temp)] = '\0';
	
	return temp;
}

char *strrev(char *string)
{
	int i, j;
	char ch;
    if (!string || ! *string)
        return string;

    i = strlen(string) - 1;
    j = 0;

    while (i > j)
    {
        ch = string[i];
        string[i] = string[j];
        string[j] = ch;
        i--;
        j++;
    }
    return string;
}

