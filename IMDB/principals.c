/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


#include "principals.h"
#include "binary.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

struct principalinfo *get_principals(char *path) {

    struct principalinfo *principals = malloc(sizeof(struct principalinfo));

    char buffer[MAX_BUFFER];
    char extension[] = "/title.principals.tsv";
    char *directory = malloc(strlen(path) + strlen(extension) + 1);
    char *column_content_tconst = NULL;
    char *column_content_nconst = NULL;
    char *column_content_characters = NULL;
    char *column_content_category = NULL;
    char *checker;

    int count = 0, i = 0, j = 0;

    strcpy(directory, path);
    strcat(directory, extension);

    FILE *fp;
    fp = fopen(directory, "r");

    fseek(fp, 0, SEEK_SET);

    fgets(buffer, MAX_BUFFER, fp);

    while (fgets(buffer, MAX_BUFFER, fp)) {
        column_content_category = get_column(buffer, 4);
        checker = strstr(column_content_category, "actor");
        if (checker) {
            count++;
        }
        for (i = 0; i < MAX_BUFFER; ++i) {
            buffer[i] = '\0';
        }
    }

    fseek(fp, 0, SEEK_SET);
    struct title_principals *ptr = malloc(sizeof(struct title_principals) * count);
    fgets(buffer, MAX_BUFFER, fp);

    i = 0;

    principals->items = count;
    principals->arr = ptr;
    principals->tconst = NULL;
    principals->nconst = NULL;

    while (fgets(buffer, MAX_BUFFER, fp) && i < count) {
        column_content_tconst = get_column(buffer, 1);
        column_content_nconst = get_column(buffer, 3);
        column_content_characters = get_column(buffer, 6);
        column_content_category = get_column(buffer, 4);
        checker = strstr(column_content_category, "actor");
        if (checker) {
            ptr[i].tconst = column_content_tconst;
            ptr[i].nconst = column_content_nconst;
            ptr[i].characters = column_content_characters;
            i++;
        }
        for (j = 0; j < MAX_BUFFER; ++j) {
            buffer[j] = '\0';
        }
    }

    fclose(fp);

    return principals;
}

struct tree *build_principal_tconst(struct principalinfo *principal_file){

    int i;
    struct tree *title_tree = NULL;

    for(i = 0; i < (principal_file->items); i++){
        title_tree = add_node(title_tree, strrev(principal_file->arr[i].tconst), 
                     &(principal_file->arr[i]));
    }
    return title_tree;
}

struct tree *build_principal_nconst(struct principalinfo *principal_file){

    int i;
    struct tree *tconst_tree = NULL;

    for(i = 0; i < (principal_file->items); i++){
        tconst_tree = add_node(tconst_tree, strrev(principal_file->arr[i].nconst), 
                               &(principal_file->arr[i]));
    }
    return tconst_tree;
}

struct tree *find_principal_tconst(struct principalinfo *principal_file, char *key){
    
    struct tree *root = find_node(principal_file->tconst, key);

    return root;
}

struct tree *find_principal_nconst(struct principalinfo *principal_file, char *key){
    
    struct tree *root = find_node(principal_file->nconst, key);

    return root;
}



























