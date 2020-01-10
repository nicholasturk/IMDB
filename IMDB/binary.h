/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


struct tree *add_node(struct tree *root, char *key, void *data);
struct tree *find_node(struct tree *root, char *key);
struct tree *new_node(char *key, void *data);
void print_tree(struct tree *node);

struct tree{
	char *key;
	void *data;
	struct tree *left;
	struct tree *right;
};

