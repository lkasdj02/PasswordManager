// le tre direttive successive sono gia parte del file string_utils.h.
#include "../string_utils.h"
//#include <stdlib.h> 
//#include <string.h> 
//#include <stdio.h>

typedef struct record {
    char sito[50];
    char mail[50];
    char password[50];
    struct record *next;
} RECORD; 


RECORD *init(char *s, char *a, char *k, RECORD *next);
// PRE: head corrisponde ad un puntatore ad un nodo della lista.
// POST: la funzione ritorna il numero di RECORD presenti all'interno della lista di RECORD.
int count(RECORD *head);
// PRE: head corrisponde ad un puntatore ad un nodo della lista.
// POST: Stampa una lista di record.
void print(RECORD *head);
// PRE: *head: puntatore a RECORD
// ***V: puntatore (riferimento) ad un puntatore ad un puntatore a RECORD.
// *s: puntatore a char.
// *a: puntatore a char.
// POST: la funzione ritorna 1 in caso siano stati trovati record corrispondenti
// ai parametri s o a, 0 altrimenti.
int find(RECORD *head, RECORD ***V, char *s, char *a);
int free_find(RECORD ***V);
// PRE: **head: puntatore a puntatore a record.
// char *s, char *a, char *k: puntatori ad array di caratteri.
// POST: la funzione ritorna 1 se l'inserimento va a buon fine.
int push(RECORD **head, char *s, char *a, char *k);
int insert(RECORD **head, char *s, char *a, char *k);
// PRE: *head: puntatore a RECORD
// *s: puntatore a char.
// *a: puntatore a char.
// POST: la funzione ritorna 1 in caso siano stati trovati record corrispondenti
// ai parametri s o a, 0 altrimenti; in questo caso vengono eliminati
// la funzione ritorna 0 altrimenti.
int delete_one(RECORD **head, char *s, char *a);
// NON ANCORA IMPLEMENTATA
int delete_group(RECORD **head, char *s, char *a, char *k); 
// PRE: *head: puntatore a RECORD
// *s: puntatore a char.
// *a: puntatore a char.
// *new_k: puntatore a char (nuova password da immetterere).
// POST: la funzione ritorna 1 in caso siano stati trovati record corrispondenti
// ai parametri s o a, 0 altrimenti; in questo caso vengono aggiornati 
// la funzione ritorna 0 altrimenti.
int update(RECORD **head, char *s, char *a, char *new_k);
// PRE: **head: puntatore a puntatore a RECORD.
// POST: la funzione dealloca la memoria allocata per la lista di RECORD.
int free_list(RECORD **head);
