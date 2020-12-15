#include <stdio.h>

int main()
{

/* Wprowadzenie numeru do którego chcemy poznać liczby pierwsze */

    int x, y, num;
    printf("Wprowadź numer do którego chcesz wskazać liczby pierwsze:\n");
    scanf("%d", &num);

/* Stworzenie tablicy z numerami do naszego numeru */

    int primes[num + 1];

    for (x = 2; x <= num; x++)
        primes[x] = x;

/* Dla każdej liczby, której kwadrat jest mniejszy lub równy naszej podanej liczbie, bierzemy
   jej wielokrotności i oznaczamy jako 0 ponieważ są to liczby złożone. Podczas wykonywania pętli
   nie bierzemy już pod uwagę liczb, które zostaly już oznaczone jako 0 */

    x = 2;
    while ((x*x) <= num)
    {
        if (primes[x] != 0)
        {
            for(y = 2; primes[x] * y <= num; y++)
            {
               primes[primes[x]*y] = 0;
            }
        }
        x++;
    }

/* Wypisujemy wszystkie liczby, którym nie zostało przypisane 0,
   czyli wypisujemy wszystkie liczby pierwsze w zakresie, który podaliśmy na początku */

    for (x = 2; x <= num; x++)
    {
        if (primes[x] != 0)
        {
            printf("%d, ", primes[x]);
        }
    }

    printf("\n");
    return 0;
}