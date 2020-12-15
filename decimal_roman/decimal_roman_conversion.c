#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NMAX 1000

/* Zadeklarowanie prototypów funkcji */

int digit(char);
int convert_to_roman(int liczba_arabska);
int convert_to_decimal(char liczba_rzymska[]);

/* Zadelkarowanie funkcji odpowiadającej za konwertowanie liczb z arabskich na rzymskie */

int convert_to_roman(int arab)
    {
        /* Zadeklarowanie dwóch tablic odpowiedzialnych za wszystkie możliwości zapisu liczb rzymskich */

        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        char *rzym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        printf("Przekonwertowana liczba: ");

        /* Wywołanie pętli, która sprawdza ile razy w danej liczbie mieści się 1000, 900, 500... i wypisuje po kolei ich ilość */

        while(arab>0)
        {
            int div = arab/num[i];
            arab = arab%num[i];
            while(div--)
            {
                printf("%s", rzym[i]);
            }
            i--;
        }
        printf("\n");
    }

/* Zadeklarowanie funkcji odpowiadającej za konwertowanie liczb rzymskich na arabskie */

int convert_to_decimal(char roman[])
    {

        int j=0;
        long int number =0;

        /* Wywołanie pętli odpowiedzialnej za konwersje */

        while(roman[j]){
    
            /* Sprawdzenie czy wartość podanej liczby rzymskiej jest mniejsza od 0 */

            if(digit(roman[j]) < 0){
                printf("Wprowadzona liczba jest niepoprawna: %c\n",roman[j]);
                return 0;
            }
    
            /* Sprawdzenie czy podana liczba rzymska jest poprawna (sprawdzenie czy w liczbie rzymskiej liczba mniejsza
               nie jest podana dwie liczby wcześniej przed większą np. IXV I<V) */

            if((strlen(roman) -j) > 2){
                if(digit(roman[j]) < digit(roman[j+2])){
                    printf("Wprowadzona liczba jest niepoprawna\n");
                    return 0;
                }
            }
    
            /* Sprawdzenie czy liczba poprzedzająca jest większa od następnej, a w przeciwnym wypadku odjęcie od liczby większej liczbę mniejszą */

            if(digit(roman[j]) >= digit(roman[j+1]))
                number = number + digit(roman[j]);
            else{
                number = number + (digit(roman[j+1]) - digit(roman[j]));
                j++;
            }
            j++;
        }
    
        printf("Przekonwertowana liczba: %ld\n",number);

    }
    
/* Zadeklarowanie funkcji odpowiedzialnej za przypisanie danej liczbie rzymskiej liczby arabskiej */

int digit(char c)
{
    int value=0;

    switch(c)
    {
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }
 
    return value;
}

/* Zadeklarowanie głównej funkcji odpowiedzialnej za sprawdzenie czy podana liczba jest liczbą arabską czy rzymską i wywołanie
   odpowiedniej funkcji odpowiedzialnej za konwersję */

int main()
{
    int arab;
    char roman[NMAX];
    char input[NMAX] = "";
    int length, z, number;
    
    printf("Wprowadź liczbę, którą chcesz przekonwertować (arabska lub rzymska, musi być większa od 0):\n");
    scanf ("%s", input);

    /* Wywołanie pętli odpowiedzialnej za sprawdzenie czy wprowadzona została liczba (liczba arabska) czy tablica znaków (liczba rzymska)
       i wywołanie funkcji konwertujących z odpowiednimi zmiennymi */
 
    length = strlen (input);
    for (z=0;z<length; z++)
        if (isdigit(input[z])==0)
        {
            convert_to_decimal(input);
            exit(1);
        }
    arab = atoi(input);
    convert_to_roman(arab);

    return 0;
}