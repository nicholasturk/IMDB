/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary.h"
#include "common.h"
#include "name.h"
#include "title.h"
#include "principals.h"


int main(int argc, char *argv[]){

	char *hello; 
	hello = malloc(10);
	free(hello);

	struct nameinfo *namefile = get_name(argv[1]);
	struct titleinfo *titlefile = get_title(argv[1]);
	struct principalinfo *principalfile = get_principals(argv[1]);

	printf("Building name tree: \n");
	namefile->name = build_pnindex(namefile);
	printf("\nBuilding name index tree: \n");
	namefile->nconst = build_ncindex(namefile);

	printf("\nBuilding primarytitle tree: \n");
	titlefile->title = build_ptindex(titlefile);
	printf("\nBuilding title tconst tree: \n");
	titlefile->tconst = build_tindex(titlefile);

	printf("\nBuilding principal tconst tree: \n");
	principalfile->tconst = build_principal_tconst(principalfile);
	printf("\nBuilding principal nconst tree: \n");
	principalfile->nconst = build_principal_nconst(principalfile);

	while(0 == 0){

		char choice[256];
		char temp[256];
		char *command = choice;
		struct name_basics *name = NULL;
		struct title_basics *title = NULL;
		struct tree *principals = NULL;
		int i = 0;

		printf(">> ");
		gets(choice);
		while(command[i] == ' '){
			i++;
		}

		int length = strlen(choice) - i;
		char *buffer = malloc(strlen(choice) - i);
		strncpy(buffer, command + i, length);
		buffer[strlen(buffer)] = '\0';

		if(strcmp(buffer, "name") == 0){

			printf("> name ");
			gets(choice);

			name = find_name(namefile, choice);
			principals = find_principal_nconst(principalfile, name->nconst);
			title = find_tconst(titlefile, ((struct title_principals*)principals->data)->tconst);
			printf("%s %s\n", title->primaryTitle, ((struct title_principals*)principals->data)->characters);
			strcpy(temp, principals->key);

			while(principals->left){
				if(strcmp(principals->left->key, temp) == 0){
					title = find_tconst(titlefile, ((struct title_principals*)principals->left->data)->tconst);
					printf("%s %s\n", title->primaryTitle, ((struct title_principals*)principals->left->data)->characters);
					principals = principals->left;
				} else{
					principals = principals->left;
				}
			}

		} else if(strcmp(choice, "title") == 0){

			/*printf("> title ");
			fgets(choice, 256, stdin);

			title = find_primary_title(titlefile, choice);
			principals = find_principal_tconst(principalfile, title->tconst);
			name = find_nconst(namefile, principals->nconst);

			printf("%s\n", name->primaryName);*/


		}
	}

	return 0;
}
