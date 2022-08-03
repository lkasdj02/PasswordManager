#include "new_file_manager.h"
#include "visuals.h"
#include <string.h>
//#include "string_utils.h"
//#include "string_utils.h"
//#include "lista/lista_record.h"


char command[MAX_LENGTH];
char **puntatore_parole;
char *comandi[] = {
  "exit\0",
};
char prompt[10] = "$-> "; 

int main() {
  int running = 1;

  clear_screen();  
  draw_menu();
  while(running != 0) { // while fino a quando non arriva il comando EXIT.
    // command input
    draw_prompt(prompt);
    fgets(command, MAX_LENGTH, stdin);
    printf("\n lunghezza stringa: %d\n", len(command));
    //printf("%ld\n", strlen(command));
    int words = split(command, SPACE, &puntatore_parole); // leonardo basso leo

    printf("numero parole: %d\n", words);
    if (words > 0) {

      for (int i = 0; i < words; i += 1) {
        to_lowercase(puntatore_parole[i]);
        printf("%s %d\n", puntatore_parole[i], len(puntatore_parole[i]));
      } 

      int res = equals(puntatore_parole[0], comandi[0]);
      free_split(&puntatore_parole, words);
      if (res == 1) { 
        running = 0; 
      } 
    } else {
      printf("inserire un valore corretto"); 
    }
  }
}
