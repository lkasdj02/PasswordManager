#include "file_manager.h"
#include "string_utils.h"

RECORD *create_record(char *sito, char *account, char *password) {
    
    // PRE: sito, account, password sono dei puntatori a char che conengono
    // le stringhe atte ad inizializzare la variabile di tipo struct.
    // POST: la funzione ritorna un puntatore ad una variabile allocatao dinamicamente
    // nella HEAP.
    
    // allocazione memoria per una variabile di tipo RECORD.
    RECORD *ptr_to_record = (RECORD*)malloc(sizeof(RECORD));
    // inizializzazione valori della struttura.
    copy(ptr_to_record->sito, sito);
    copy(ptr_to_record->mail, account);
    copy(ptr_to_record->password, password);

    // ritornare il puntatore alla variabile allocata nella heap.
    return ptr_to_record;
}

int insert(FILE *fp, char *path, char *mode, RECORD *r) {

    // PRE: fp è un puntatore ad una struttura di tipo FILE.
    // path e mode sono puntatori a char che contengono il path del file nel quale andare a fare operazioni sui record
    // la modalità di accesso al file.
    // r è il valore di un puntatore una variabile di tipo RECORD all'interno della memoria HEAP; sua memorizzazione.
    
    // POST: insert ritorna 1 se il record è stato scritto correttamente all'interno del file, 0 altrimenti.
    
    // apertura del file esempio.dat.
    fp = fopen("esempio.dat", mode);

    // buona programmazione
    if (fp == NULL) {
        fclose(fp);
        return 0;
    }
    else 
        fwrite(r, sizeof(RECORD), 1, fp); 

    fclose(fp);
    return 1;
}

int select_all(FILE *fp, char *path, char *mode, RECORD **array_destinazione) {
    
    // PRE: fp è un puntatore ad una struttura di tipo FILE.
    // path e mode sono puntatori a char che contengono il path del file nel quale andare a fare operazioni sui record
    // la modalità di accesso al file.
    // array_destinazione è un riferimento ad un array; il chiamante infatti passa il riferimento al suo array in modo
    // da lasciare alla funzione il compito di gestire l'allocazione della memoria necessaria alla sua memorizzazione.
    
    // POST: select all ritorna il numero di record letti all'interno del file specificato da path.
    
    // conto numero record nel file.
    fp = fopen("esempio.dat", mode);
    fseek(fp, 0, SEEK_END);
    int numero_record = (int)(ftell(fp) - 1) / sizeof(RECORD);
    printf("numero record: %d\n", numero_record);

    // riposizionare fp all'inizio del file.
    fseek(fp, 0, SEEK_SET); 

    // CREAZIONE DI UN ARRAY DI RECORD nella memoria dinamica
    *array_destinazione = (RECORD *)malloc(sizeof(RECORD) * numero_record);
    for (int i = 0; i < numero_record; i += 1)
         fread(&(*array_destinazione)[i], sizeof(RECORD), 1, fp);

    // leggere ogni singolo record.
    // fread(*array_destinazione, sizeof(RECORD), numero_record, fp); 
    fclose(fp);

    return numero_record;
}
