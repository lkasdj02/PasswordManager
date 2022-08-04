#include "new_file_manager.h"
#include <stdio.h>
#define RECORD_FORMAT_OUT "(%s, %s, %s)\n" 
#define RECORD_FORMAT_IN "(%[^,], %[^,], %[^,])" 
#define SIZE_CONTENT_RECORD 150

int count_records(FILE *fp, char *path, char *mode) {
    
    // PRE: fp è un puntatore ad un file, path il suo percorso e mode
    // la modalità con la quale si vuole accedere al file.
    // POST: la funzione ritorna il numero record presente nel file specificato
    // dal percorso.
    
    fp = fopen(path, mode);
    int numero_record;

    fseek(fp, 0, SEEK_END);
    printf("posizione fp: %lu\n", ftell(fp)); // DEBUG
    numero_record = (int)ftell(fp) / SIZE_CONTENT_RECORD;
    // printf("numero record: %d\n", numero_record); // DEBUG
    fseek(fp, 0, SEEK_SET); 

    fclose(fp);
    return numero_record;
     
}

int read(FILE *in, RECORD **start, char *path) {
  RECORD appoggio = {"", "", ""};
  int read_records = 0;
  in = fopen(path, "rb+");
  int tot_records_in_file = count_records(in, path, "rb+");
  // printf("numero record: %d\n", tot_records_in_file); // DEBUG
  if (in == NULL || path == NULL) 
    return 0;

  while (read_records < tot_records_in_file) { 
    fread(&appoggio, 150, 1, in) ;
    //fscanf(in, RECORD_FORMAT_IN, appoggio.sito, appoggio.mail, appoggio.password);
    //printf("%s %s %s \n", appoggio.sito, appoggio.mail, appoggio.password);
    //printf("posizione file pointer corrente: %ld\n", ftell(in));
    push(start, appoggio.sito, appoggio.mail, appoggio.password);
    read_records+=1;
  } 
  

  fclose(in);
  return read_records;
}

int write(FILE *out, RECORD **start, char *path) {
  
  int written_records = 0;
  out = fopen(path, "wb+");
    
  for(RECORD *current = *start; current != NULL; current = current->next) {
    fwrite(current, 150, 1, out);
    //fprintf(out, RECORD_FORMAT_OUT, current->sito, current->mail, current->password);
    written_records+=1;
  }

  fclose(out);
  return written_records;
}
