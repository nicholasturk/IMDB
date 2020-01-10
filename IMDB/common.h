/*
Nicholas Sturk
1058650
nsturk@uoguelph.ca
November 3rd 2019
*/


char  *get_column(char *string, int number);
char *strrev(char *str);

struct nameinfo{
	int items;
	struct name_basics *arr;
	struct tree *nconst;
	struct tree *name;
};

struct titleinfo{
	int items;
	struct title_basics *arr;
	struct tree *tconst;
	struct tree *title;
};

struct principalinfo{
	int items;
	struct title_principals *arr;
	struct tree *tconst;
	struct tree *nconst;
};







