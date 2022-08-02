#include "new_file_manager.h"
//#include "string_utils.h"
//#include "lista/lista_record.h"

int main() {

  RECORD *head = init("github.com", "leonardo.basso02@gmail.com", "bale2002.", NULL);
  RECORD *p1   = init("github.com", "leonardo.basso02@outlook.com", "IpadBluh2022.", NULL);
  head->next = p1;
  print(head);
}
