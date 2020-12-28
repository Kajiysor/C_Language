#include <stdio.h>
int main()
{
    int c, k;
    unsigned dec;

    printf("Enter an integer in decimal number system\n");
    scanf("%d", &dec);

    printf("%d in binary number system is:\n", dec);

    for (c = 6; c >= 0; c--)
    {
        k = dec >> c;

        if (k & 01)
            printf("1");
        else
            printf("0");
    }

    printf("\n");

    return 0;
}