/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


#include "binary.h"
#include "common.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct tree *add_node(struct tree *root, char *key, void *data){

	if(root == NULL){
		root = new_node(key, data);
		return root;

	} else if (key[0] > root->key[0]){

		root->right = add_node(root->right, key, data);

	} else if(key[0] < root->key[0]){

		root->left = add_node(root->left, key, data);

	} else{

		int k = 0;
		while(key[k] == root->key[k]){
			k++;
		}

		if(key[k] > root->key[k]){
		root->right = add_node(root->right, key, data);

		} else if(key[k] < root->key[k]){

		root->left = add_node(root->left, key, data);

		}

	}

	return root;
}

struct tree *new_node(char *key, void *data){

	struct tree *new_node = malloc(sizeof(struct tree));
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;

	return new_node;
}

void print_tree(struct tree *node)
{
  if(node){
  	printf("%s\n", node->key);
  	print_tree(node->right);
  	print_tree(node->left);
  }   
}

struct tree *find_node(struct tree *root, char *key){

	int k = 0;

	while(key[k] == root->key[k]){
		k++;
	}

	if(root == NULL || strcmp(root->key, key) == 0){

		return root;

	} else if(key[k] > root->key[k]){

		return find_node(root->right, key);

	} else if(key[k] < root->key[k]){

		return find_node(root->left, key);

	} else{

		int k = 0;

		while(key[k] == root->key[k]){

			k++;
		}

		if(key[k] > root->key[k]){

		return find_node(root->right, key);

		} else if(key[k] < root->key[k]){

		return find_node(root->left, key);

		}
	}
	return root;
}




























