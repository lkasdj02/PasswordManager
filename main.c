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
  int operation_result = 0;
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
    // COMMAND INPUT
    draw_prompt(prompt);
    fgets(command, MAX_LENGTH, stdin);
    number_of_words = split(command, SPACE, &puntatore_parole); 

    // printf("numero parole: %d\n", number_of_words);
    if (number_of_words > 0 && number_of_words <= 4) { // se il numero di parole rientra nei canoni specificati dai comandi
      
      // RENDERE TUTTI GLI INPUT DA TASTIERA MINUSCOLI PER I CONFRONTI
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
              printf("Nessun record trovato.\n");
            }
            // clear the inputs
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], " ");
            free_find(&array_records);
          }
        }
        else if (equals(puntatore_parole[0], comandi[3])) { // INSERT
          printf("inserito insert\n"); // copia delle stringhe immesse all'intero dell'array input. 
          if (number_of_words < 4) {
            printf("ATTENZIONE: sono stati inseriti troppi pochi argomenti.\n");
          } else {
          
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], puntatore_parole[i + 1]);
              
            found_records = find(head, &array_records, inputs[0], inputs[1]);
            free_find(&array_records); // possiamo deallocare la memoria sin da subito dato che alla fine ci serve solamente il numero di record.

            if (found_records > 0)
              printf("ATTENZIONE: sono stati trovati altri record con lo stesso dominio e account;\n si prega di reinserire dei dati validi.\n");
            else {
              // inserimento di un record alla fine della coda.
              operation_result = push(&head, inputs[0], inputs[1], inputs[2]);
              printf("numero record inseriti: %d\n", operation_result);
            }
            // clean input.
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], " ");
          }
        }
        else if (equals(puntatore_parole[0], comandi[4])) { // UPDATE
          printf("inserito update\n");
          if (number_of_words < 4) {
            printf("ATTENZIONE: sono stati inseriti troppi pochi argomenti.\n");
          } else {
          
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], puntatore_parole[i + 1]);
              
            found_records = find(head, &array_records, inputs[0], inputs[1]);
            free_find(&array_records); // possiamo deallocare la memoria sin da subito dato che alla fine ci serve solamente il numero di record.

            if (found_records <= 0)
              printf("ATTENZIONE: non sono stati trovati record da aggiornare;\n si prega di reinserire dei dati validi.\n");
            else {
              // inserimento di un record alla fine della coda.
              operation_result = update(&head, inputs[0], inputs[1], inputs[2]);
              printf("numero record aggiornati: %d\n", operation_result);
            }

            // clean input.
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], " ");
          }
        }
        else if (equals(puntatore_parole[0], comandi[5])) { // DELETE
          printf("inserito delete\n");
          if (number_of_words < 3) {
            printf("la funzione DELETE_GROUP deve essere ancora implementata");
          } else {

            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], puntatore_parole[i + 1]);
            
            found_records = find(head, &array_records, inputs[0], inputs[1]);
            free_find(&array_records); 

            if (found_records <= 0) {
              printf("ATTENZIONE: non sono stati trovati record con lo stesso dominio e account;\n si prega di reinserire dei dati validi.\n");
            } else {
              operation_result = delete_one(&head, inputs[0], inputs[1]);
              printf("numero record eliminati: %d\n", operation_result);
            }

            // clear the inputs
            for (int i = 0; i < number_of_words - 1; i+=1)  
              strcpy(inputs[i], " ");
          }
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
