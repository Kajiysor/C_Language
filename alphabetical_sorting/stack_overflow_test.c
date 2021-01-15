#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES 5
#define NAME_LEN 10

void print_names(char names[][NAME_LEN])
{
    int i;
    for (i = 0; i < NAMES; ++i)
    {
        printf("%s\n", names[i]);
    }
}

int main(void)
{
    char names[NAMES][NAME_LEN] = {"xxx", "uuu", "ccc", "aaa", "bbb"};

    print_names(names);
    printf("---------------------------------\n");

    qsort(names, NAMES, NAME_LEN, strcmp);

    print_names(names);

    return 0;
}