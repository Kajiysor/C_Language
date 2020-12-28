#include <stdio.h>
int non_binary_conversion(unsigned n, char *bin)
{
    int i;
    for (i = 0; n > 0; i++)
    {
        bin[i] = n % 2;
        n = n / 2;
    }
    return i;
}

int main()
{
    int i;
    unsigned n;
    char bin[16];
    printf("Wprowadź liczbę do przekonwertowania: \n");
    scanf("%d", &n);
    i = non_binary_conversion(n, bin);
    printf("Ta liczba w postaci binarnej to: \n");
    printf("%ls\n", &i);
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}