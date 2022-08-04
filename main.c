#include "new_file_manager.h"
#include "visuals.h"
#include <string.h>
//#include "string_utils.h"
//#include "string_utils.h"
//#include "lista/lista_record.h"


char command[MAX_LENGTH];
char **puntatore_parole;
char *comandi[] = {
  "exit",
  "clear",
  "show",
  "insert",
  "update",
  "delete",
};
char prompt[10] = "$-> "; 

// array per ospitare i parametri da passare i valori da passare
// alle varie funzioni della lista di RECORD.
char nome_sito[50] = " ";
char nome_account[50] = " ";
char nome_password[50] = " ";


int main() {
  int running = 1; // flag che controlla l'andamento del programma.
  int number_of_words = 0; // numero di parole ottenute dalla funzione split.
  RECORD *head = NULL; // primo elemento della lista di RECORD
  
  // visual setup iniziale.
  clear_screen();  
  draw_menu();

  // loop con guardia la variabile running dichiarata precedentemente. 
  while(running != 0) { // while fino a quando non arriva il comando EXIT.
    // command input
    draw_prompt(prompt);
    fgets(command, MAX_LENGTH, stdin);
    number_of_words = split(command, SPACE, &puntatore_parole); 

    // printf("numero parole: %d\n", number_of_words);
    if (number_of_words > 0 && number_of_words <= 4) { // se il numero di parole rientra nei canoni specificati dai comandi
      for (int i = 0; i < number_of_words; i += 1) { // obbligatorio.
        to_lowercase(puntatore_parole[i]);
        printf("stringa immessa: %s \t lunghezza stringa: %d\n", puntatore_parole[i], len(puntatore_parole[i])); // debug
      } 
      
      if (equals(puntatore_parole[0], comandi[0])) // EXIT
        running = 0; 
      else if (equals(puntatore_parole[0], comandi[1])) // CLEAR
        clear_screen();
      else { // ACTIONS
        if (equals(puntatore_parole[0], comandi[2])) { // SHOW
          printf("inserito show\n");
        }
        else if (equals(puntatore_parole[0], comandi[3])) { // INSERT
          printf("inserito insert\n");
        }
        else if (equals(puntatore_parole[0], comandi[4])) { // UPDATE
          printf("inserito update\n");
        }
        else if (equals(puntatore_parole[0], comandi[5])) { // DELETE
          printf("inserito delete\n");
        } else {
          printf("inserire un COMANDO corretto.\n"); 
        }
      }
    } else {
      printf("inserire un valore corretto"); 
    }
  }
  // quando il programma finisce queste risorse devono essere deallocate.
  free_split(&puntatore_parole, number_of_words);
}
