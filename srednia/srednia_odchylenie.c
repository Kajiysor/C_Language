#include <stdio.h>
#include <math.h>

int main()
{
    /* Zadeklarowanie potrzebnych zmiennych
    sum --> suma wszystkich dotąd wpisanych liczb
    sq --> suma kwadratów wszystkich dotąd wpisanych liczb
    amt --> ilość wpisanych dotąd liczb */

    double num;
    double sum = 0;
    double amt = 0;
    double sq = 0;

    /* Pętla, która wczytuje liczby tak długo aż nie zostanie wczytany znak końca pliku */

    while (scanf("%lf", &num) != EOF)
    {

    /* Wykonanie działań na odpowiednich zmiennych */

     sum += num;
     sq += num*num;
     amt++;
    }

    /* Wzory na średnią arytmetyczną i odchylenie standardowe */

    double avg = sum/amt;
    double dev = sqrt(((amt*sq) - (sum*sum))/(amt*amt));

    /* Wypisanie wyników */

    printf("Suma podanych liczb to: %lf\n", sum);
    printf("Średnia aretmetyczna podanych liczb to: %lf\n", avg);
    printf("Odchylenie standardowe podanych liczb to: %lf\n", dev);
    return 0;

}