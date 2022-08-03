#include "new_file_manager.h"
#include <stdio.h>
//#include "string_utils.h"
//#include "lista/lista_record.h"

int main() {

  FILE *stream = NULL;
  RECORD **found_elements = NULL;
  RECORD *head = NULL;
  push(&head, "github.com", "leonardo.basso02@gmail.com", "bale2002.");
  push(&head, "google.com", "leonardo.basso02@gmail.com", "bale2002.");
  push(&head, "github.com", "leonardo.basso02@outlook.com", "IpadBluh2022.");
  push(&head, "github.com", "leonardo.basso02@libero.it", "tuamammazoccola");
  print(head);
  
  //delete_one(&head, "github.com", "leonardo.basso02@gmail.com");
  //delete_one(&head, "github.com", "leonardo.basso02@outlook.com");
  delete_one(&head, "github.com", "leonardo.basso02@libero.it");

  update(&head, "github.com", "leonardo.basso02@outlook.com", "nuova_password_aggiornata");
  
  printf("il numero di record all'interno dell'intera lista di record: %d.\n", count(head));
  
  int number_elements = find(head, &found_elements, " ", "leonardo.basso02@gmail.com");
  printf("il numero di record CERCATI trovati all'interno dell'intera lista di record: %d.\n", number_elements);
  int free_res = free_find(&found_elements);
  (free_res == 1) ? printf("deallocazione completata\n") : printf("deallocazione NON completata\n");

  write(stream, &head, "esempio.dat");
  int res = free_list(&head);
  (res == 1) ? printf("deallocazione completata\n") : printf("deallocazione NON completata\n");

  printf("\n");
  printf("AFTER DEALLOCAZIONE (DESERIALIZZAZIONE)\n");

  printf("\n");
  RECORD *head2 = NULL;
  int n = read(stream, &head2, "esempio.dat");
  print(head2);
  res = free_list(&head2);
}
