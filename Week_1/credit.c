#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkSum(long number);
int lenght(long number);
void checkfirst(long number, int length, int checkSum);

int main (void)
{
    long num;
    printf("Number: ");
    scanf("%ld", &num);

    checkSum(num);
    lenght(num);
    checkfirst(num, lenght(num), checkSum(num));
}

//Function to check the sum of the digits
int checkSum(long number)
{
    int sum = 0;
    int sumSecond = 0;
    int sumLast = 0;
    long numLast = number;
    long numSecond = number;
    int last;

    do
    {
        sum = numLast % 10;
        sumLast = sumLast + sum;
        numLast = numLast / 100;
    }
    while (numLast > 0);

    do
    {
        sum = ((numSecond / 10) % 10);
        if ((sum * 2) >= 10)
        {
            sumSecond = sumSecond + (sum*2) - 9;
        }
        else
        {
            sumSecond = sumSecond + (sum * 2);
        }
        numSecond = numSecond / 100;
    }
    while (numSecond >= 10);
    sum = sumLast + sumSecond;
    return sum;
}

//count digits function
int lenght(long number)
{
    long num;
    int count = 1;

    do
    {
        num = (number / 10);
        number = num;
        count ++;
    }
    while(num >= 10);
    return count;
}
//function to check the first digit and compare it with the sum of the digits
void checkfirst(long number, int lenght, int checkSum)
{
    long num = number;
    do
    {
        num = num / 10;
    }
    while (num > 100);

    int x = checkSum % 10;

    if (x == 0) //check sum
    {
        if ((num == 34 || num == 37) && lenght == 15)
        {
            printf("AMEX\n");
        }
        else if ((num >= 51 && num <= 55) && lenght == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((num >= 40 && num <= 49) && (lenght >= 13 && lenght <= 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}