#include "file_manager.h"
#include "string_utils.h"

// questa funzione si presta bene all'uso di una lista.
RECORD *create_record(char *sito, char *account, char *password) {
    
    // PRE: sito, account, password sono dei puntatori a char che conengono
    // le stringhe atte ad inizializzare la variabile di tipo struct.
    // POST: la funzione ritorna un puntatore ad una variabile allocatao dinamicamente
    // nella HEAP.
    
    // CONTROLLO DI FLUSSO.
    char *stringhe[3] = { sito, account, password };
    for (int i = 0; i < 3; i += 1)
        if (len(stringhe[i]) > sizeof(RECORD) / 3)
            return NULL;

    // allocazione memoria per una variabile di tipo RECORD.
    RECORD *ptr_to_record = (RECORD*)malloc(sizeof(RECORD));
    // inizializzazione valori della struttura.
    copy(ptr_to_record->sito, sito);
    copy(ptr_to_record->mail, account);
    copy(ptr_to_record->password, password);

    // ritornare il puntatore alla variabile allocata nella heap.
    return ptr_to_record;
}

int count_records(FILE *fp, char *path, char *mode) {
    
    // PRE: fp è un puntatore ad un file, path il suo percorso e mode
    // la modalità con la quale si vuole accedere al file.
    // POST: la funzione ritorna il numero record presente nel file specificato
    // dal percorso.
    
    fp = fopen(path, mode);
    int numero_record;

    fseek(fp, 0, SEEK_END);
    // printf("posizione fp: %lu\n", ftell(fp)); // DEBUG
    numero_record = (int)(ftell(fp)) / sizeof(RECORD);
    // printf("numero record: %d\n", numero_record); // DEBUG
    fseek(fp, 0, SEEK_SET); 

    fclose(fp);
    return numero_record;
   
     
}

int find_position(FILE *fp, char *path, char *mode, char *s, char *a) {

    
    RECORD appoggio = { " ", " ", " " };
    int posizione_record = -1;
    int n = count_records(fp, path, mode);
    printf("numero record: %d.\n", n);
    printf("sito da cercare: %s \n", s); // DEBUG
    printf("path: %s mode: %s\n", path, mode);
    fp = fopen(path, mode);
    for (int i = 0; i < n; i += 1) {
        fread(&appoggio, sizeof(RECORD), 1, fp);
        printf("sito1: %s \t account: %s \n", appoggio.sito, appoggio.mail); // DEBUG
        if (equals(appoggio.sito, s) && equals(appoggio.mail, a))
            posizione_record = i;
    }
    fclose(fp);
    return posizione_record;
}

int insert(FILE *fp, char *path, char *mode, RECORD *r) {

    // PRE: fp è un puntatore ad una struttura di tipo FILE.
    // path e mode sono puntatori a char che contengono il path del file nel quale andare a fare operazioni sui record
    // la modalità di accesso al file.
    // r è il valore di un puntatore una variabile di tipo RECORD all'interno della memoria HEAP; sua memorizzazione.
    
    // POST: insert ritorna 1 se il record è stato scritto correttamente all'interno del file, 0 altrimenti.
    
    // apertura del file esempio.dat.
    fp = fopen(path, mode);

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

int select_some(FILE *fp, char *path, char *mode, char *s, char *a, RECORD **array_destinazione) {
    
    // PRE: fp è un puntatore ad una struttura di tipo FILE.
    // path e mode sono puntatori a char che contengono il path del file nel quale andare a fare operazioni sui record
    // la modalità di accesso al file.
    // array_destinazione è un riferimento ad un array; il chiamante infatti passa il riferimento al suo array in modo
    // da lasciare alla funzione il compito di gestire l'allocazione della memoria necessaria alla sua memorizzazione.
    // sito e account sono dei puntatori ad array cdi char che permettono di fare una selezione basata su questi due parametri
    // (sito e account rispettivamente). 
    
    // POST: select all ritorna il numero di record letti all'interno del file specificato da path.
    
    // contare numero record aventi il sito uguale.
    
    RECORD appoggio = {" ", " ", " "};
    int numero_record = 0;
    int contatore_record = 0;
    int i = 0;
    int *posizioni_record = (int *)malloc(sizeof(int) * 1); // array di posizioni.

    // apertura del file
    fp = fopen(path, mode);
    
    // contare numero record.
    fseek(fp, 0, SEEK_END);
    printf("posizione fp: %lu\n", ftell(fp)); // DEBUG
    numero_record = (int)(ftell(fp)) / sizeof(RECORD);
    printf("numero record: %d\n", numero_record); // DEBUG
    fseek(fp, 0, SEEK_SET); 

    // contiamo numero record che rispettano i parametri della selezione. 
    while (i < numero_record) {
        fread(&appoggio, sizeof(RECORD), 1, fp);
        if (equals((&appoggio)->sito, s)) {
            if (contatore_record == 0) 
                posizioni_record[contatore_record++] = i;
            else {
                posizioni_record = (int *)realloc(posizioni_record, sizeof(int) * (++contatore_record)); // almeno un altro record è stato trovato.
                posizioni_record[contatore_record - 1] = i;
            }
        }
        i+=1;
    } 
    
    // allocare memoria necessaria ad ospitare n record che rispettano i parametri della selezione. 
    *array_destinazione = (RECORD *)malloc(sizeof(RECORD) * contatore_record);
    for (int i = 0; i < contatore_record; i += 1) {
        fseek(fp, posizioni_record[i] * sizeof(RECORD), SEEK_SET);
        fread(*(array_destinazione) + i, sizeof(RECORD), 1, fp);
    }
        
        //printf("%d\n", posizioni_record[i]);

    // CHIUSURA DEL FILE. 
    fclose(fp);

    // FREE DELLA MEMORIA
    free(posizioni_record); 
    return contatore_record;     
}

int select_all(FILE *fp, char *path, char *mode, RECORD **array_destinazione) {
    
    // PRE: fp è un puntatore ad una struttura di tipo FILE.
    // path e mode sono puntatori a char che contengono il path del file nel quale andare a fare operazioni sui record
    // la modalità di accesso al file.
    // array_destinazione è un riferimento ad un array; il chiamante infatti passa il riferimento al suo array in modo
    // da lasciare alla funzione il compito di gestire l'allocazione della memoria necessaria alla sua memorizzazione.
    // POST: select all ritorna il numero di record letti all'interno del file specificato da path.
    
    int numero_record;
    fp = fopen(path, mode);
    
    // conto numero record nel file.
    fseek(fp, 0, SEEK_END);
    printf("posizione fp: %lu\n", ftell(fp));
    numero_record = (int)(ftell(fp)) / sizeof(RECORD);
    printf("numero record: %d\n", numero_record);  
    fseek(fp, 0, SEEK_SET); 

    if (numero_record == 0) { // se il numero di record è 0.
        fclose(fp);
        return 0;
    } else {
        // CREAZIONE DI UN ARRAY DI RECORD nella memoria dinamica
        *array_destinazione = (RECORD *)malloc(sizeof(RECORD) * numero_record);

        // lettura dei record e memorizzazione nell'array appena creato dinamicamente.
        for (int i = 0; i < numero_record; i += 1)
            fread(*(array_destinazione) + i, sizeof(RECORD), 1, fp);

        // fread(*array_destinazione, sizeof(RECORD), numero_record, fp); 
        fclose(fp);
    }
    return numero_record;
}

int update_record(FILE *fp, char *path, char *mode, RECORD *r) {

    int posizione;

    printf("sito: %s \t account: %s \n", r->sito, r->mail); // DEBUG
    // cercare posizione record
    posizione = find_position(fp, path, mode, r->sito, r->mail); 
    printf("la posizione del record cercato è: %d\n", posizione);
    if (posizione != -1)
        return 1;
    else
        return 0;
}
    
