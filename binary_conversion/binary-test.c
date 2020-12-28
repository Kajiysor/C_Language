#include <stdio.h>
#define NMAX 16
int binary_conversion(unsigned n, char *bin)
{
    int index = NMAX - 1;
    while (index >= 0)
    {
        /* Store LSB of num to bin */
        bin[index] = n & 1;

        /* Decrement index */
        index--;

        /* Right Shift num by 1 */
        n >>= 1;
    }
}
int main()
{
    int i;
    unsigned n;
    char bin[NMAX];
    printf("Wprowadź liczbę do przekonwertowania: \n");
    scanf("%d", &n);
    binary_conversion(n, bin);
    printf("Ta liczba w postaci binarnej to: \n");
    printf("%ls\n", &i);
    for (i = 0; i < NMAX; i++)
    {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}