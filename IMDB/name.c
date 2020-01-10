/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "name.h"
#include "common.h"
#include "binary.h"
#define MAX_BUFFER 1024

struct nameinfo *get_name(char *path){

	struct nameinfo *names = malloc(sizeof(struct nameinfo));

	char buffer[MAX_BUFFER];
	char extension[] = "/name.basics.tsv";
	char *directory = malloc(strlen(path) + strlen(extension) + 1);
	char *column_content_const = NULL;
	char *column_content_name = NULL;
	char *column_content_profession = NULL;
	char *checker;
	char *checker_m;
	char *checker_f;

	int count = 0, i = 0, j = 0;

	strcpy(directory, path);
	strcat(directory, extension);

	FILE *fp = fopen(directory, "r");

	fgets(buffer,MAX_BUFFER,fp);

	while(fgets(buffer, MAX_BUFFER, fp)){
		column_content_profession = get_column(buffer, 5);
		checker = strstr(column_content_profession, "actor");
		if(checker){
			count++;
		}
		checker = strstr(column_content_profession, "actress");
		if(checker){
			count++;
		}
		for (i = 0; i < MAX_BUFFER; ++i){
			buffer[i] = '\0';
		}
	}

	fseek(fp, 0, SEEK_SET);
	struct name_basics *ptr = malloc(sizeof(struct name_basics) * count);
	fgets(buffer, MAX_BUFFER, fp);

	i = 0;

	names->items = count;
	names->arr = ptr;
	names->nconst = NULL;
	names->name = NULL;

	while(fgets(buffer, MAX_BUFFER, fp) && i < count){
		column_content_const = get_column(buffer, 1);
		column_content_name = get_column(buffer, 2);
		checker_m = strstr(buffer, "actor");
		checker_f = strstr(buffer, "actress");
		if(checker_m || checker_f){
			ptr[i].nconst = column_content_const;
			ptr[i].primaryName = column_content_name;
			i++;
		}
		for (j = 0; j < MAX_BUFFER; ++j){
			buffer[j] = '\0';
		}
	}

	fclose(fp);

	return names;
}

struct tree *build_pnindex(struct nameinfo *name_file){

	int i;
	struct tree *primaryName_tree = NULL;

	for(i = 0; i < (name_file->items); i++){
		primaryName_tree = add_node(primaryName_tree, name_file->arr[i].primaryName, 
						            &(name_file->arr[i]));
	}
	return primaryName_tree;
}

struct tree *build_ncindex(struct nameinfo *name_file){

	int i;
	struct tree *nconst_tree = NULL;

	for(i = 0; i < (name_file->items); i++){
		nconst_tree = add_node(nconst_tree, strrev(name_file->arr[i].nconst), 
					           &(name_file->arr[i]));
	}
	return nconst_tree;
}

struct name_basics *find_name(struct nameinfo *name_file, char *key){
	
	struct tree *root = find_node(name_file->name, key);

	return root->data;
}

struct name_basics *find_nconst(struct nameinfo *name_file, char *key){
	
	struct tree *root = find_node(name_file->nconst, key);

	return root->data;
}

















