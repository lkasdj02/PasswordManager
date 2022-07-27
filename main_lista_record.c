#include "./lista/lista_record.h"

int main(int argc, char *argv[]) {
  
  // INIT TEST
  RECORD *head = init(argv[1], argv[2], argv[3], NULL);
  RECORD *n1   = init(argv[1], argv[2], argv[3], NULL);
  RECORD *n2   = init(argv[1], argv[2], argv[3], NULL);
  head->next = n1;
  n1->next   = n2;
  n2->next   = NULL;

  RECORD **array = (RECORD **)malloc(sizeof(RECORD *));

  // PRINT TEST
  print(head);
  
  // COUNT TEST.
  int c = count(head); 
  printf("numero di elementi nella lista: %d.\n", c);
  printf("\n");
  array = (RECORD **)realloc(array, sizeof(RECORD *) * c);
  RECORD *current = head;
  for (int i = 0; i < c; i += 1) {
    array[i] = current;
    printf("indirizzo current:  %p, \t indirizzo %d esimo array: %p.\n", current, i, array[i]);
    current = current->next;
  }
  
  // PUSH TEST
  char nuovo_account[50] = "github.com";
  char nuovo_mail[50] = "leonardo.basso02@libero.it";
  char nuovo_password[50] = "lkasdj02";
  
  char nuovo_account2[50] = "gmail.com";
  char nuovo_mail2[50] = "leonardo.basso02@outlook.it";
  char nuovo_password2[50] = "abracadabra";

  int res = 0;
  res += push(&head, nuovo_account, nuovo_mail, nuovo_password);
  res += push(&head, nuovo_account2, nuovo_mail2, nuovo_password2);

  (res == 1) ?
    printf("numero di elementi inseriti nella lista: %d.\n", res) :
    printf("numero di elementi inseriti nella lista: %d.\n", res);
  
  printf("\n");
  print(head);
  printf("\n");
  // FIND TEST
  char account_da_trovare[50] = "github.com";
  char mail_da_trovare[50] = " ";

  res = find(head, &array, account_da_trovare, mail_da_trovare);
  printf("numero di elementi trovati nella lista: %d.\n", res);
  for (int i = 0; i < res; i += 1) 
    printf("sito elemento: %s \t indirizzo %d esimo array: %p.\n", array[i]->sito, i, array[i]);
}
