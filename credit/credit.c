#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long startLast(long n);
    long startSecondToLast(long n);
    int countDigits(long n);
    long twodigits = 0;
    int mc1, mc2, mc3, mc4, mc5, ae1, ae2, v; // variables holding first 1 or 2 digits based on the task
    int counter1, counter2, counter3;
    mc1 = 51;
    mc2 = 52;
    mc3 = 53;
    mc4 = 54;
    mc5 = 55;
    ae1 = 34;
    ae2 = 37;
    v = 4;
    long card = get_long("Enter your card number.\n");
    int digits = countDigits(card);

    for (long i = card; i > 9; i = i / 10) // finds the last 2 digits and saves them in "twodigits" var
    {
        twodigits = i;
    }

    int last = startLast(card);
    int secondToLast = startSecondToLast(card);
    if (((last + secondToLast) % 10 == 0) && (digits == 16 || digits == 15
            || digits == 13))     // checks which card it is based on first 1 or 2 digits
    {
        if (digits == 16 || digits == 13)    // if correct do this
        {
            if (twodigits == mc1 || twodigits == mc2 || twodigits == mc3 || twodigits == mc4 || twodigits == mc5)
            {
                printf("MASTERCARD\n");
            }
            else if (twodigits / 10 == v)
            {
                printf("VISA\n");
            }
            else      // if nothing exit
            {
                printf("INVALID\n");
            }

        }
        if (digits == 15)
        {
            if (twodigits == ae1 || twodigits == ae2)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

    }
    else
    {
        printf("INVALID\n");
    }

}
long startLast(long n) // calculates digits starting from last digit and doing every other
{
    long sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 100;
    }
    return sum;
}
long startSecondToLast(long n) // calculates sum digits starting from secnod to last digit
{
    long temp = 0;
    long split_temp = 0;
    long sum = 0;
    while (n != 0)
    {
        n = n / 10;  // removes last digit from the card
        temp = (n % 10) * 2;   // singles out the second to last digit
        if (temp > 9) // check if the digit is greater than 9
        {
            split_temp = ((temp / 10) + (temp % 10)); // if it is it adds the digits together
        }
        else
        {
            split_temp = temp; // if not it just sets the value of split temp to temp avoiding another if
        }
        sum = sum + split_temp;
        n = n / 10;
    }
    return sum;
}
int countDigits(long n)
{
    long digit = n;
    int counter = 0;
    while (digit > 0)
    {
        digit = digit / 10;
        counter++;
    }
    return counter;
}
