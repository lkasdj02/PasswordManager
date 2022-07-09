#define MAX_LENGTH 255
#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

int main() {

    char stringa[MAX_LENGTH];


    printf("inserire una stringa: \t");
    int l = 0;
    while (*(stringa + l) != '\n') {
        *(stringa + l) = getchar();
        putchar(*(stringa + l));
        l+=1;
    }
}
