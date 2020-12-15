#include <stdio.h>

int main()

{
    int c = getchar();

    while (c != EOF) {
        putchar(c-1);
        c = getchar();
    }

    return 0;
}