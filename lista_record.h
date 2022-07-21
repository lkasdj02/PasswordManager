#include <stdlib.h>

typedef struct record {
    char sito[50];
    char mail[50];
    char password[50];
} RECORD; 


RECORD *init(char *s, char *a, char *k);
int count(RECORD *head);
void print(RECORD *head);
RECORD *find(char *s, char *a);
int push(char *s, char *a, char *k);
int insert(char *s, char *a, char *k);
int delete(char *s, char *a, char *k);
int update(char *s, char *a, char *new_k);
