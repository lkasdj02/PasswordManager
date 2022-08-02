#include "lista/lista_record.h"


// PRE: fp è un puntatore ad un file, path il suo percorso e mode
// la modalità con la quale si vuole accedere al file.
// POST: la funzione ritorna il numero record presente nel file specificato
// dal percorso.
int count_records(FILE *fp, char *path, char *mode);
// PRE: *in: puntatore a struct FILE.
// **start: riferimento (puntatore) ad un puntatore a RECORD.
// POST: la funzione ritorna il numero di record letti all'interno di un file
// specificato da path.
int read(FILE *in, RECORD **start, char *path);
// PRE: *out: puntatore a struct FILE.
// **start: riferimento (puntatore) ad un puntatore a RECORD.
// POST: la funzione ritorna il numero di record scritti all'interno di un file
// specificato da path.
int write(FILE *out, RECORD **start, char *path);

