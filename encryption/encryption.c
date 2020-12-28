#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 10

/* Bierzemy plik jako obowiązkowy argument funkcji main() */

int main(int argc, char *Argv[])
{

    /* Tworzymy zmienne odpowiadające za pliki, na których będziemy działać oraz hasło */

    FILE *file1, *file2;
    char znak;
    char haslo[NMAX];
    int j = 0, dlugosc_hasla;

    /* Generujemy tymczasową nazwę pliku */

    char Tymczasowy[L_tmpnam];
    tmpnam(Tymczasowy);

    /* Prosimy użytkownika o wprowadzenie hasła do szyfrowania i deszyfrowania */

    printf("Wpisz hasło: ");
    scanf("%s", haslo);

    /* Otwieramy plik, na którym będziemy działać oraz plik tymczasowy, pomocniczy */

    if (NULL == (file1 = fopen(Argv[1], "rb")))
        return 1;

    if (NULL == (file2 = fopen(Tymczasowy, "wb")))
        return 1;

    znak = getc(file1);
    dlugosc_hasla = strlen(haslo);

    /* Tworzymy pętle, w której bierzemy kolejne znaki pliku, na którym operujemy i szyfrujemy je
       oraz zapisujemy do pliku pomocniczego */

    while (znak != EOF)
    {
        znak = znak ^ (haslo[j % (dlugosc_hasla)]);
        putc(znak, file2);
        znak = getc(file1);
        j++;
    }

    /* Zamykamy pliki, usuwamy nasz oryginalny plik, który następnie zostaje
       zastąpiony plik tymczasowy(zaszyfrowany bądź odszyfrowany) */

    fclose(file1);
    fclose(file2);
    unlink(Argv[1]);
    rename(Tymczasowy, Argv[1]);
    return 0;
}