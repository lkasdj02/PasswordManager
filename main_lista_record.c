#include <stdio.h>
#include "./lista/lista_record.h"

int main(int argc, char *argv[]) {
  
  // INIT TEST
  RECORD *head = init(argv[1], argv[2], argv[3], NULL);
  RECORD *n1   = init(argv[1], argv[2], argv[3], NULL);
  RECORD *n2   = init(argv[1], argv[2], argv[3], NULL);
  head->next = n1;
  n1->next   = n2;
  n2->next   = NULL;
  // PRINT TEST
  print(head);
  
  // COUNT TEST.
  int c = count(head); 
  printf("numero di elementi nella lista: %d.\n", c);
  printf("\n");

  // PUSH TEST
  char nuovo_account[50] = "hqporner.com";
  char nuovo_mail[50] = "leonardo.basso02@libero.it";
  char nuovo_password[50] = "lkasdj02";

  int res = push(&head, nuovo_account, nuovo_mail, nuovo_password);
  (res == 1) ?
    printf("numero di elementi inseriti nella lista: %d.\n", res) :
    printf("numero di elementi inseriti nella lista: %d.\n", res);
  
  printf("\n");
  print(head);
}
