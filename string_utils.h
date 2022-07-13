#include <stdio.h>

int len(char *s);
int replace(char *s, int pos, char replacement);
void clear_string(char *s, int len);
int split(char *s, char split, char ***puntatore);
int free_split(char ***p, int words);
