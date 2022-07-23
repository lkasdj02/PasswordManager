#include "lista_record.h"
#include <string.h> 
#include <stdio.h>

RECORD *init(char *s, char *a, char *k, RECORD *next) {
  RECORD *new_record = (RECORD *)malloc(sizeof(RECORD));
  strcpy(new_record->sito, s);
  strcpy(new_record->mail, a);
  strcpy(new_record->password, k);
  new_record->next = next;
  return new_record;
}

int count(RECORD *head) {
  int count = 0;
  RECORD *current = head;
  if (head == NULL)
    return 0;

  while(current != NULL) { 
    count+=1; 
    current = current->next;
  }
  return count;
}

void print(RECORD *head) {
  RECORD *current = head;
  while(current != NULL) {
    printf("sito: %s \t mail: %s \t password: %s \t\n", current->sito, current->mail, current->password);
    current = current->next;
  }
}

RECORD *find(char *s, char *a) {
  return NULL;
}

int push(RECORD **head, char *s, char *a, char *k) {
  // creazione di un nuovo record all'interno della memoria HEAP.
  RECORD *new_node = init(s, a, k, NULL);
  RECORD *current = *head;

  if (*head == NULL)
    *head = new_node;
  else {
    while(current->next != NULL)
      current = current->next;
    current->next = new_node;
    // printf("sito: %s \t mail: %s \t password: %s \t\n", (current->next)->sito, (current->next)->mail, (current->next)->password);
  }
  return 1;
}

int insert(char *s, char *a, char *k) { // inserimento in una posizione specifica
  // do something
  return 0;
}

int delete(char *s, char *a, char *k) {
  // do something
  return 0;
}

int update(char *s, char *a, char *new_k) {
  // do something
  return 0;
}

