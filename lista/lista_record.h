#include "../string_utils.h"
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

typedef struct record {
    char sito[50];
    char mail[50];
    char password[50];
    struct record *next;
} RECORD; 


RECORD *init(char *s, char *a, char *k, RECORD *next);
int count(RECORD *head);
void print(RECORD *head);
int find(RECORD *head, RECORD ***V, char *s, char *a);
int free_find(RECORD ***V);
int push(RECORD **head, char *s, char *a, char *k);
int insert(RECORD **head, char *s, char *a, char *k);
int delete(RECORD **head, char *s, char *a, char *k);
int update(RECORD **head, char *s, char *a, char *new_k);
