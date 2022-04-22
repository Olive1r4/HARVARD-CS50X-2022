#include <stdio.h>
#include <string.h>

int longer(long number);

int main (void)
{
    long num;
    printf("Number: ");
    scanf("%ld", &num);
    //num = get_long("Number: ");
    //call function count digits
    int digits = longer(num);

    printf("%i\n",digits);
}

//count digits function
int longer(long number)
{
    int last;
    int count = 0;

    do
    {
        last = (number/10);
        printf("%i\n",last);
        number = last;
        count ++;
    }
    while(last != 0);
    return count;
}