#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 256
#define BUFFERSIZE 50

int compare(const void *a, const void *b)
{
    return strcmp(*(char *const *)a, *(char *const *)b);
}

int main(/*int argc, char *argv[]*/)
{
    /*char const *const fileName = argv[1];*/
    /*FILE *file = fopen(fileName, "r");*/
    char line[BUFFERSIZE];
    char *TEKST[NMAX];
    int j = 0;
    int i = 0;
    while (fgets(line, NMAX, stdin) != NULL && i < NMAX)
    {
        if (!strcmp(line, "\n"))
            continue;
        TEKST[i] = malloc(strlen(line) + 1);
        strcpy(TEKST[i], line);
        i++;
    }

    /*fclose(file);*/

    qsort(TEKST, i, sizeof(char *), compare);

    printf("==========POSORTOWANE ALFABETYCZNIE==========\n");
    for (j; j < i; j++)
    {
        printf("%s", TEKST[j]);
    }

    printf("\n");
    return 0;
}