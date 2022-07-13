#include "file_manager.h"
#include "string_utils.h"

RECORD *create_record(char *sito, char *account, char *password) {
    // allocazione memoria per una variabile di tipo RECORD.
    RECORD *ptr_to_record = (RECORD*)malloc(sizeof(RECORD));
    // inizializzazione valori della struttura.
    copy(ptr_to_record->sito, sito);
    copy(ptr_to_record->mail, account);
    copy(ptr_to_record->password, password);

    // ritornare il puntatore alla variabile allocata nella heap.
    return ptr_to_record;
}

