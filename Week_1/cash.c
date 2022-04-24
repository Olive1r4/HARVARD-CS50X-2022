#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_cents(int cents);

int main (void)
{
    int change = 0;

    printf("Change Owed: ");
    scanf("%d", &change);

    get_cents(change);
    printf("%d\n", get_cents(change));
}

int get_cents(int cents)
{
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int total = 0;

    quarters = cents / 25;
    cents = cents % 25;
    dimes = cents / 10;
    cents = cents % 10;
    nickels = cents / 5;
    cents = cents % 5;
    pennies = cents;

    total = quarters + dimes + nickels + pennies;

    return total;
}