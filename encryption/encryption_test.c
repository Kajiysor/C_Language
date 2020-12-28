#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 10

int main(int argc, char *Argv[])
{
    FILE *file1, *file2;
    char znak;
    char haslo[NMAX];
    char Tymczasowy[L_tmpnam];
    int j = 0, dlugosc;
    tmpnam(Tymczasowy);
    printf("Wpisz hasło: ");
    scanf("%s", haslo);
    if (NULL == (file1 = fopen(Argv[1], "rb")))
        return 1;

    if (NULL == (file2 = fopen(Tymczasowy, "wb")))
        return 1;

    znak = getc(file1);
    dlugosc = strlen(haslo);
    printf("%d\n", dlugosc);

    while (znak != EOF)
    {
        printf("Znak: %c\n", znak);
        znak = znak ^ (haslo[j % (dlugosc)]);
        putc(znak, file2);
        znak = getc(file1);
        j++;
    }

    fclose(file1);
    fclose(file2);
    unlink(Argv[1]);
    rename(Tymczasowy, Argv[1]);
    return 0;
}