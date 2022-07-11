#define MAX_LENGTH 255
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

int main() {

    char stringa[MAX_LENGTH];


    printf("inserire una stringa: \t");
    fgets(stringa, MAX_LENGTH, stdin);
    int r = replace(stringa, (strlen(stringa) - 1), '\0'); 
    if (r) 
        for (int i = 0; i < strlen(stringa); i += 1)
            printf("%d ", stringa[i]);

    printf("\n"); 
    printf("lunghezza: %d", len(stringa)); 
}
