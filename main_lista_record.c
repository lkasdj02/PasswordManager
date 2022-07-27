#include "./lista/lista_record.h"
#define INIT_TEST "TESTING INIT FUNCTION"
#define PUSH_TEST "TESTING PUSH FUNCTION"
#define COUNT_TEST "TESTING COUNT FUNCTION"
#define FIND_TEST "TESTING FIND FUNCTION"
#define UPDATE_TEST "TESTING UPDATE FUNCTION"

void test_output(char *s);
void color_line(char *s);

int main(int argc, char *argv[]) {
  
  // INIT TEST
  test_output(INIT_TEST);
  RECORD *head = init(argv[1], argv[2], argv[3], NULL);
  RECORD *n1   = init(argv[1], argv[2], argv[3], NULL);
  RECORD *n2   = init(argv[1], argv[2], argv[3], NULL);
  head->next = n1;
  n1->next   = n2;
  n2->next   = NULL;
  RECORD **array = NULL;
  // RECORD **array = (RECORD **)malloc(sizeof(RECORD *));

  // PRINT TEST
  print(head);
  printf("\n");

  // COUNT TEST.
  int c = count(head); 
  test_output(COUNT_TEST);
  printf("numero di elementi nella lista: %d.\n", c);
  printf("\n");
/*
  array = (RECORD **)realloc(array, sizeof(RECORD *) * c);
  RECORD *current = head;
  for (int i = 0; i < c; i += 1) {
    array[i] = current;
    printf("indirizzo current:  %p, \t indirizzo %d esimo array: %p.\n", current, i, array[i]);
    current = current->next;
  }
  */
  
  // PUSH TEST
  test_output(PUSH_TEST);
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
  test_output(FIND_TEST);
  char account_da_trovare[50] = "github.com";
  char mail_da_trovare[50] = "leonardo.basso02@gmail.com";

  res = find(head, &array, account_da_trovare, mail_da_trovare);
  printf("numero di elementi trovati nella lista: %d.\n", res);
  if (count > 0) {
    for (int i = 0; i < res; i += 1) {
      printf("elemento trovato: ");
      printf("sito: ");
      color_line(array[i]->sito);
      printf("\t");
      printf("mail: ");
      color_line(array[i]->mail);
      printf("\t");
      printf("indirizzo %d esimo array: %p.\n", i, array[i]);
    }
    int f = free_find(&array);
    (f == 1) ? printf("memoria deallocata con successo.\n") : printf("memoria NON deallocata con successo.\n");
  }
  printf("\n");

  // UPDATE TEST
  test_output(UPDATE_TEST);
  char updated_password[50] = "puff_daddy_motherfucker";

  res = update(&head, account_da_trovare, mail_da_trovare, updated_password);
  (res == 1) ?
      printf("trovato un elemento.\n") :
      printf("trovati %d tanti elementi.\n", res);

  char updated[50] = "Updated list\n";
  color_line(updated);
  print(head);
  printf("\n");
}


void test_output(char *s) {
  printf("\033[1;33m");
  printf("%s\n", s);
  printf("\033[0m");
}

void color_line(char *s) {
  printf("\033[1;33m");
  printf("%s", s);
  printf("\033[0m");
}
