#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 32

/* Tworzymy funkcję odpowiedzialną za konwersję przy użyciu operacji arytmetycznych */

int non_binary_conversion(unsigned dec, char *bin)
{
    int i;

    /* Tworzymy pętle, w której resztę z dzielenia naszej liczby przez 2 przypisujemy po kolei
       do tablicy znaków odpowiedzialnej za liczbę binarną a następnie tę liczbę dzielimy przez 2 */

    for (i = 0; dec > 0; i++)
    {
        bin[i] = dec % 2;
        dec = dec / 2;
    }
    return i;
}

/* Tworzymy funkcję odpowiedzialną za konwersję przy użyciu przesunięć bitowych */

int binary_conversion(unsigned dec, char *bin)
{
    int i = NMAX - 1;

    /* Tworzymy pętlę, w której przypisujemy do tablicy odpowiedzialnej za liczbę binarną
       najmniej istotny bit do indeksu tablicy od końca i wykonujemy przesunięcie bitowe w prawo*/

    while (i >= 0)
    {
        bin[i] = dec & 01;
        i--;
        dec >>= 1;
    }
}

/* Tworzymy funkcję main, w której to będziemy odpowiednio wywoływać wcześniejsze funkcje */

int main()
{

    /* Tworzymy zmienne */

    int i, answer, j;
    unsigned dec;
    char bin[NMAX];
    int amt = 0;
jump_point:

    /* Prosimy użytkownika o wybranie w jaki sposób chce konwertować */

    printf("Wybierz jakim sposobem chcesz konwertować: \n\
    [1] Konwertowanie za pomocą operacji arytmetycznych \n\
    [2] Konwertowanie za pomocą przesunięć bitowych\n");
    scanf("%d", &answer);

    if (answer == 1)
    {

        /* Wywołujemy funkcję odpowiedzialną za konwertowanie przy użyciu operacji arytmetycznych,
           Wypisujemy tę liczbę w postaci binarnej oraz wypisujemy ile bitów jest potrzebnych na jej zapisanie */

        printf("Wprowadź liczbę do przekonwertowania: \n");
        scanf("%d", &dec);
        i = non_binary_conversion(dec, bin);
        printf("Ta liczba w postaci binarnej to: ");
        for (i = i - 1; i >= 0; i--)
        {
            printf("%d", bin[i]);
            amt++;
        }
        printf("\nIlość bitów potrzebnych do zapisania tej liczby w systemie binarnym to: %d", amt);
    }
    else if (answer == 2)
    {

        /* Wywołujemy funkcję odpowiedzialną za konwertowanie przy użyciu przesunięć bitowych,
           w pierwszej pętli przechodzimy przez liczbę tak by usunąć wszystkie wiodące zera,
           a następnie wypisujemy liczbę w postaci binarnej i liczbę bitów potrzebnych na jej zapisanie */

        printf("Wprowadź liczbę do przekonwertowania: ");
        scanf("%d", &dec);
        binary_conversion(dec, bin);
        printf("Ta liczba w postaci binarnej to: ");
        printf("%ls\n", &i);
        for (j = 0; j <= NMAX; j++)
        {
            if (bin[j] > 0)
                break;
        }
        for (i = j; i < NMAX; i++)
        {
            printf("%d", bin[i]);
        }
        amt = NMAX - j;
        printf("\nIlość bitów potrzebnych do zapisania tej liczby w systemie binarnym to: %d", amt);
    }
    else

    /* Gdy użytkownik nie wybrał żadnej poprawnej opcji to wracamy do momentu w kodzie gdzie
       użytkownik może ponownie dokonać wyboru */

    {
        printf("Wybrałeś złą opcję!\n");
        goto jump_point;
    }

    printf("\n");

    return 0;
}