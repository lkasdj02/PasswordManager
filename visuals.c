#include "visuals.h"


void draw_menu() {
  printf(" PASSWORD MANAGER ");
}

void draw_prompt() {
  printf("$-> ");
}

void color_line(char *s) {
  printf("\033[1;33m");
  printf("%s", s);
  printf("\033[0m");
}

void clear_screen() {
 printf("\e[1;1H\e[2J");
}
