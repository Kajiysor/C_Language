#include <stdio.h>
int main()
{
    int i;
    unsigned n;
    char *bin;
    printf("Wprowadź liczbę do przekonwertowania: \n");
    scanf("%d", &n);
    for (i = 0; n > 0; i++)
    {
        bin[i] = n % 2;
        n = n / 2;
    }

    printf("Ta liczba w postaci binarnej to: \n");

    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
    printf("\n");
    return 0;
}