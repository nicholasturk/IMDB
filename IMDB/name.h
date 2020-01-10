/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


struct nameinfo *get_name(char *path);
struct tree *build_pnindex(struct nameinfo *name_file);
struct tree *build_ncindex(struct nameinfo *name_file);
struct name_basics *find_name(struct nameinfo *name_file, char *key);
struct name_basics *find_nconst(struct nameinfo *name_file, char *key);

struct name_basics{
	char *nconst;
	char *primaryName;
};




