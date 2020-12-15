#include <stdio.h>
#include <string.h>
 
#define NMAX 1000
int main()
{
    /* Inicjalizacja zmiennych i tablic */

    int a[NMAX],b[NMAX];
    int result[(2*NMAX)]={0};
    int i,j,tmp,x;
    char num1[(NMAX+1)],num2[(NMAX+1)];

    /* Poproszenie użytkownika o wprowadzenie liczb, które chce pomnożyć */
    printf("Wprowadź pierwszą liczbę: \n");
    scanf("%s",num1);
    printf("Wprowadź drugą liczbę: \n");
    scanf("%s",num2);

    int l1 = strlen(num1);
    int l2 = strlen(num2);

    /* Pętla, która zmienia tablicę znaków przekazaną przez użytkownika na tablicę liczb całkowitych, przy czym jest ona pisana od końca */

    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        a[j] = num1[i]-'0';
    }

    /* Pętla, która zmienia tablicę znaków przekazaną przez użytkownika na tablicę liczb całkowitych, przy czym jest ona pisana od końca */

    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = num2[i]-'0';
    }

    /* Pętla, która wymnaża po kolei wszystkie elementy tablic od końca i dodaje wynik do indeksu tablicy odpowiadającej za wynik
       przykład: 625*25 ==> result[0] = 5*5, result[1] = 5*2, result[2] = 5*6 |NASTĘPUJE ZWIĘKSZENIE I A ZATEM ZWIĘKSZENIE INDEKSÓW| result[1] = result[1] + 2*5,
       result[2] = result[2] + 2*2, result[3] = 2*6  */

    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            result[i+j] += b[i]*a[j];
        }
    }
    
    /* Pętla, która zapełnia tablicę odpowiedzialna za wynik. Danemu indeksowi przyporządkowuje wartość reszty jego dzielenia przez 10
       a do wartości po indeksem natępnym dodaje liczbę dziesiątek, która się mieści pod danym indeksem */

    for(i = 0;i < l1+l2;i++)
    {
        tmp = result[i]/10;
        result[i] = result[i]%10;
        result[i+1] += tmp;
    }

    /* Pętla przegląda tablice odpowiedzialną za wynik od końca, aż napotka liczbę, która jest większa od zaera, wtedy przekazuje indeks do kolejnej pętli */

    for(i = l1+l2; i>= 0;i--)
    {
        if(result[i] > 0)
            break;
    }
    
    /* Pętla bierze indeks przekazany z poprzedniej pętli i począwszy od niego zaczyna wypisywać tablicę od końca, tym samym podając poprawny wynik mnożenia */

    printf("Wynik: \n");
    for(;i >= 0;i--)
    {
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;
}