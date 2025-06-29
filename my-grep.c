/* 23.6.2025, Valtteri Ahola, Project 2: Unix Utilities - my-grep.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *tiedosto;
    char *puskuri = NULL;
    size_t puskurinkoko = 0;
    size_t aRivi;
    int i;

    if (argc == 1) {
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    } else if (argc == 2) {
        // Read from stdin and print to console if match with search term
        if ((aRivi = getline(&puskuri, &puskurinkoko, stdin)) != -1) {
            if (strstr(puskuri, argv[1])) {
                    printf("%s", puskuri);
                }
        }
        if (puskuri != NULL) {
            free(puskuri);
        }
    } else {
        // Read from files and print to console if row in file match with search term 
        for (i = 2; i < argc; i++) {
            if((tiedosto = fopen(argv[i], "r")) == NULL) {
            printf("my-grep: cannot open file\n");
            exit(1);
            }
            while ((aRivi = getline(&puskuri, &puskurinkoko, tiedosto)) != -1) {
                if (strstr(puskuri, argv[1])) {
                    printf("%s", puskuri);
                }
            }
            if (puskuri != NULL) {
                free(puskuri);
            }
            fclose(tiedosto);
        }
    }
    return 0;
}
