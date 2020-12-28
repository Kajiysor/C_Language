#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 32
int non_binary_conversion(unsigned dec, char *bin)
{
    int i;
    for (i = 0; dec > 0; i++)
    {
        bin[i] = dec % 2;
        dec = dec / 2;
    }
    return i;
}

int binary_conversion(unsigned dec, char *bin)
{
    int i = NMAX - 1;
    while (i >= 0)
    {
        /* Store LSB of num to bin */
        bin[i] = dec & 01;

        /* Decrement index */
        i--;

        /* Right Shift num by 1 */
        dec >>= 1;
    }
}

int main()
{
    int i, answer, j;
    unsigned dec;
    char bin[NMAX];
    int amt = 0;
jump_point:
    printf("Wybierz jakim sposobem chcesz konwertować: \n\
    [1] Konwertowanie za pomocą operacji arytmetycznych \n\
    [2] Konwertowanie za pomocą przesunięć bitowych\n");
    scanf("%d", &answer);

    if (answer == 1)
    {
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
    {
        printf("Wybrałeś złą opcję!\n");
        goto jump_point;
    }

    printf("\n");

    return 0;
}