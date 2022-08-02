#include "new_file_manager.h"
#include <stdio.h>
//#include "string_utils.h"
//#include "lista/lista_record.h"

int main() {

  FILE *stream = NULL;
  RECORD **found_elements = NULL;
  RECORD *head = init("github.com", "leonardo.basso02@gmail.com", "bale2002.", NULL);
  RECORD *p1   = init("github.com", "leonardo.basso02@outlook.com", "IpadBluh2022.", NULL);
  head->next = p1;

  push(&head, "github.com", "leonardo.basso02@libero.it", "tuamammazoccola");
  print(head);
  //printf("il numero di record all'interno dell'intera lista di record: %d.\n", count(head));
  
  //int number_elements = find(head, &found_elements, " ", "leonardo.basso02@gmail.com");
  //printf("il numero di record trovati all'interno dell'intera lista di record: %d.\n", number_elements);
  //free_find(&found_elements);

  write(stream, &head, "esempio.dat");
  int res = free_list(&head);
  (res == 1) ? printf("deallocazione completata\n") : printf("deallocazione NON completata\n");

  printf("\n");
  printf("AFTER DEALLOCAZIONE\n");

  printf("\n");
  RECORD *head2 = NULL;
  int n = read(stream, &head2, "esempio.dat");
  print(head2);
  res = free_list(&head2);
}
