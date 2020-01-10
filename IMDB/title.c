/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


#include "title.h"
#include "binary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define MAX_BUFFER 1000

struct titleinfo *get_title(char *path) {

	struct titleinfo *titles = malloc(sizeof(struct titleinfo));
    char buffer[MAX_BUFFER];
    char extension[] = "/title.basics.tsv";
    char *directory = malloc(strlen(path) + strlen(extension) + 1);
    char *column_content_const = NULL;
    char *column_content_name = NULL;
    char *column_content_type = NULL;
    char *column_content_adult = NULL;
    char *checker_type;
    char *checker_adult;

    int count = 0, i = 0, j = 0;

    strcpy(directory, path);
    strcat(directory, extension);

    FILE *fp = fopen(directory, "r");

    fseek(fp, 0, SEEK_SET);

    fgets(buffer, MAX_BUFFER, fp);

    while (fgets(buffer, MAX_BUFFER, fp)) {
        column_content_type = get_column(buffer, 2);
        checker_type = strstr(column_content_type, "movie");
        column_content_adult = get_column(buffer, 5);
        checker_adult = strstr(column_content_adult, "0");
        if (checker_type && checker_adult) {
            count++;
        }
        for (i = 0; i < MAX_BUFFER; ++i) {
            buffer[i] = '\0';
        }
    }

    fseek(fp, 0, SEEK_SET);
    struct title_basics *ptr = malloc(sizeof(struct title_basics) * count);
    fgets(buffer, MAX_BUFFER, fp);

    i = 0;

    titles->items = count;
	titles->arr = ptr;
	titles->tconst = NULL;
	titles->title = NULL;

    while (fgets(buffer, MAX_BUFFER, fp) && i < count) {
        column_content_type = get_column(buffer, 2);
        column_content_adult = get_column(buffer, 5);
        column_content_name = get_column(buffer, 3);
        column_content_const = get_column(buffer, 1);
        checker_type = strstr(buffer, "movie");
        checker_adult = strstr(buffer, "0");
        if (checker_type && checker_adult) {
            ptr[i].tconst = column_content_const;
            ptr[i].primaryTitle = column_content_name;
            i++;
        }
        for (j = 0; j < MAX_BUFFER; ++j) {
            buffer[j] = '\0';
        }
    }

    fclose(fp);

    return titles;
}

struct tree *build_ptindex(struct titleinfo *title_file){

	int i;
	struct tree *title_tree = NULL;

	for(i = 0; i < (title_file->items); i++){
		title_tree = add_node(title_tree, title_file->arr[i].primaryTitle, &(title_file->arr[i]));
	}
	return title_tree;
}

struct tree *build_tindex(struct titleinfo *title_file){

	int i;
	struct tree *tconst_tree = NULL;

	for(i = 0; i < (title_file->items); i++){
		tconst_tree = add_node(tconst_tree, strrev(title_file->arr[i].tconst), &(title_file->arr[i]));
	}

	return tconst_tree;
}

struct title_basics *find_primary_title(struct titleinfo *title_file, char *key){
	
	struct tree *root = find_node(title_file->title, key);

	return root->data;
}

struct title_basics *find_tconst(struct titleinfo *title_file, char *key){
	
	struct tree *root = find_node(title_file->tconst, key);

	return root->data;
}



























