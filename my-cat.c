/* 23.6.2025, Valtteri Ahola, Project 2: Unix Utilities - my-cat.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKSIMI 1000

int main(int argc, char *argv[]) {
    FILE *tiedosto;
    char aRivi[MAKSIMI];
    int i;

    if (argc == 1) {
        exit(0);
    } else {
        for (i = 1; i < argc; i++) {
            // Read from file and print to console
            if((tiedosto = fopen(argv[i], "r")) == NULL) {
                printf("my-cat: cannot open file\n");
                exit(1);
            }
            while (fgets(aRivi, MAKSIMI, tiedosto) != NULL) {
                printf("%s", aRivi);
            }
            printf("\n");
            fclose(tiedosto);
        }
    }
    return 0;
}