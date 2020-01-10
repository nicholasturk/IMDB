/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


struct principalinfo *get_principals(char *path);
struct tree *build_principal_tconst(struct principalinfo *principal_file);
struct tree *build_principal_nconst(struct principalinfo *principal_file);
struct tree *find_principal_tconst(struct principalinfo *principal_file, char *key);
struct tree *find_principal_nconst(struct principalinfo *principal_file, char *key);

struct title_principals{
	char *tconst;
	char *nconst;
	char *characters;
};


