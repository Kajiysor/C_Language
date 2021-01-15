#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 256
#define BUFFERSIZE 50

/* Stworzenie funkcji porównującej tekst */

int compare(const void *a, const void *b)
{
    return strcmp(*(char *const *)a, *(char *const *)b);
}

/* Wywołanie funkcji main(), dzięki zmiennym w, które są w 
   komentarzach można przerobić program tak aby sortował po 
   podaniu pliku jako argumentu funkcji main() */

int main(/*int argc, char *argv[]*/)
{
    /*char const *const fileName = argv[1];*/
    /*FILE *file = fopen(fileName, "r");*/

    /* Deklaracja zmiennych odpowiedzialnych za wczytywany tekst, tablice, 
       która będzie gromadzić wiersze tekstu oraz zmiennych pomocniczych */

    char line[BUFFERSIZE];
    char *TEKST[NMAX];
    int j = 0;
    int i = 0;

    /* Poproszenie użytkownika o wprowadzenie tekstu */

    printf("Wprowadź tekst oddzielając wiersze klawiszem ENTER, a kończąc cały tekst kombinacją klawiszy CTRL+D:\n");

    /* Wywołanie pętli, 
       która przegląda poszczególne wiersze wprowadzonego 
       tekstu i usuwa wiersze puste, następnie przekazuje wyczytane 
       wiersze do tablicy TEKST[] */

    while (fgets(line, NMAX, stdin /*file*/) != NULL && i < NMAX)
    {
        if (!strcmp(line, "\n"))
            continue;
        TEKST[i] = malloc(strlen(line) + 1);
        strcpy(TEKST[i], line);
        i++;
    }

    /*fclose(file);*/

    /* Wywołanie funkcji qsort(), która sortuje 
       tablice TEKST[] za pomocą funkcji porównawczej compare() */

    qsort(TEKST, i, sizeof(char *), compare);

    /* Wypisanie posortowanego tekstu */

    printf("==========POSORTOWANE ALFABETYCZNIE==========\n");
    for (j; j < i; j++)
    {
        printf("%s", TEKST[j]);
    }

    printf("\n");
    return 0;
}