#include "new_file_manager.h"
#include "visuals.h"
#include <stdio.h>
#include <string.h>
//#include "string_utils.h"
//#include "string_utils.h"
//#include "lista/lista_record.h"

char path[15] = "esempio.dat";
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

// array di input per facilitare l'assegnazione alle variabili precedenti
// i valoi immessi da terminale.
char *inputs[3] = {nome_sito, nome_account, nome_password};  

int main() {
  int running = 1; // flag che controlla l'andamento del programma.
  int number_of_words = 0; // numero di parole ottenute dalla funzione split.
  int found_records = 0; // numero di record trovati dalla find.
  RECORD *head = NULL; // primo elemento della lista di RECORD
  RECORD **array_records = NULL; 
  FILE *stream = NULL; // puntatore a struttura file che serve per la deserializzazione.
  
  // VISUAL SETUP INIZIALE.
  clear_screen();  
  draw_menu();
   
  // DESERIALIZZAZIONE DELLA LISTA
  read(stream, &head, path);
  print(head);

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
        //printf("stringa immessa: %s \t lunghezza stringa: %d\n", puntatore_parole[i], len(puntatore_parole[i])); // debug
      } 
      
      if (equals(puntatore_parole[0], comandi[0])) // EXIT
        running = 0; 
      else if (equals(puntatore_parole[0], comandi[1])) // CLEAR
        clear_screen();
      else { // ACTIONS

        if (equals(puntatore_parole[0], comandi[2])) { // SHOW
          printf("inserito show\n");
          if (strcmp(puntatore_parole[1], "*") == 0)
            print(head);
          else {
            for (int i = 0; i < number_of_words - 1; i+=1)  
              if (!(strcmp(puntatore_parole[i + 1], "none") == 0))  // flag da terinale per indicare che non si vuole cercare un parametro.
                strcpy(inputs[i], puntatore_parole[i + 1]);

            found_records = find(head, &array_records, nome_sito, nome_account);
            if (found_records > 0) {
              for (int i = 0; i < found_records; i += 1) 
                printf("record trovato: %s \t %s \t %s\n", array_records[i]->sito, array_records[i]->mail, array_records[i]->password);
            } else {
              printf("nessun record trovato");
            }
            // free the inputs
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], " ");
            free_find(&array_records);
          }
        }
        else if (equals(puntatore_parole[0], comandi[3])) { // INSERT
          printf("inserito insert\n");
          if (number_of_words < 4)
            printf("sono stati inseriti troppi pochi parametri");        
          else {
            // copia delle stringhe immesse all'intero dell'array input. 
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], puntatore_parole[i + 1]);
            // inserimento di un record alla fine della coda.
            insert(&head, inputs[0], inputs[1], inputs[2]);
          }
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
  // SCRITTURA DELLA LISTA NEL FILE 
  write(stream, &head, path);
  // quando il programma finisce queste risorse devono essere deallocate.
  free_split(&puntatore_parole, number_of_words);
  free_list(&head);
}
