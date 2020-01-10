/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


struct titleinfo *get_title(char *path);
struct tree *build_ptindex(struct titleinfo *title_file);
struct tree *build_tindex(struct titleinfo *title_file);
struct title_basics *find_primary_title(struct titleinfo *title_file, char *key);
struct title_basics *find_tconst(struct titleinfo *title_file, char *key);

struct title_basics{
	char *tconst;
	char *primaryTitle;
};


