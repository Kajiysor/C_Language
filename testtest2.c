#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
    {
        int number;
        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        char *sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        printf("Enter decimal that you want to convert to roman: \n");
        scanf("%s", &number);    
        while(number>0)
        {
            int div = number/num[i];
            number = number%num[i];
            while(div--)
            {
                printf("%s", sym[i]);
            }
            i--;
        }
        printf("\n");
        return 0;
    }