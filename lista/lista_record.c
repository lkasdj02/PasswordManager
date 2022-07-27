#include "lista_record.h"
 
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
    printf("sito: %s \t mail: %s \t password: %s \t indirizzo heap: %p.\n", current->sito, current->mail, current->password, current);
    current = current->next;
  }
}

int find(RECORD *head, RECORD ***V, char *s, char *a) {
  
  // dichiarazione variabili
  int count = 0; 
  RECORD *current = head;

  if (strcmp(s, VOID_STRING) == 0 && strcmp(a, VOID_STRING) == 0) {
    return count;
  } else if (strcmp(s, VOID_STRING)>0 && strcmp(a, VOID_STRING) == 0) { // selezionare tutti gli elementi con lo stesso nome di dominio.

    while(current != NULL) { 
      if (strcmp(current->sito, s) == 0) {
        count+=1; 
        // riallocare la memoria di V
        *V = (RECORD **)realloc(*V, sizeof(RECORD *) * count); 
        // aggiungere a V[count - 1] l'indirizzo appena trovato.
        *(*V + (count - 1)) = current;
      }
      current = current->next;
    }
    return count;

  } else if (strcmp(s, VOID_STRING)>0 && strcmp(a, VOID_STRING)>0) {

    printf("sito immesso: %s, e-mail immessa: %s.\n", s, a); 

    while(current != NULL) { 
      if (strcmp(s, current->sito) == 0 && strcmp(a, current->mail) == 0) {
        count+=1; 

        *V = (RECORD **)realloc(*V, sizeof(RECORD *) * count); 
        // aggiungere a V[count - 1] l'indirizzo appena trovato.
        *(*V + (count - 1)) = current;       
      }
      current = current->next;
    }
    return count;
  }
}

int free_find(RECORD ***V) {
  free((*V)); // deallocare la zona di memoria puntata dal puntatore ai puntatori.
  return 1;
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

int update(RECORD **head, char *s, char *a, char *new_k) {
  // find record/s. 
  // se 1 o piu' record sono stati trovati allora fare l'update. 
  // altrimenti ritornare int = 0 al chiamante.
  
  RECORD **found_elements = NULL;
  int n_found_elements = find(*head, &found_elements, s, a); 
  if (n_found_elements == 0)
    return 0;
  else {
    // usare i puntatori in found_elements per aggiornare.
    for (int i = 0; i < n_found_elements; i+=1) {
      //printf("sito: %s\t account: %s\n", found_elements[i]->sito, found_elements[i]->mail);
      copy(found_elements[i]->password, new_k);
    }

    free_find(&found_elements);
    return n_found_elements;
  }
}

int insert(RECORD **head,char *s, char *a, char *k) { // inserimento in una posizione specifica
  // do something
  return 0;
}

int delete(RECORD **head, char *s, char *a, char *k) {
  // do something
  return 0;
}



