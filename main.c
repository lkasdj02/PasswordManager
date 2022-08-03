#include "new_file_manager.h"
#include "visuals.h"
#include <string.h>
#define MAX_LENGTH 255
#define SPACE ' ' 
//#include "string_utils.h"
//#include "string_utils.h"
//#include "lista/lista_record.h"


char command[MAX_LENGTH];
char **puntatore_parole;

int main() {
  int running = 1;

  clear_screen();  
  draw_menu();
  while(running) { // while fino a quando non arriva il comando EXIT.
    draw_prompt();
    fgets(command, MAX_LENGTH, stdin);
    int words = split(command, SPACE, &puntatore_parole); // leonardo basso leo
    
    //if (strcmp(to_lowercase(puntatore_parole[0]), "exit"))
    //  running = 0;
  }
}
