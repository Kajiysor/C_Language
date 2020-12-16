#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXINPUT 100
int main()
{
    char input[MAXINPUT] = "";
    int length, i, number, x;

    scanf("%s", input);
    length = strlen(input);
    for (i = 0; i < length; i++)
        if (isdigit(input[i]) == 0)
        {
            printf("Entered input is not a number\n");
            exit(1);
        }
    printf("Given input is a number\n");
    number = atoi(input);
    x = number * 2;
    printf("%d\n", x);
}