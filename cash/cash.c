#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{  
    void calculate(int a);
    int quarter = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    float change = get_float("How much change are you owed?\n");
    
change:
    if (change < 0)
    {
        change = get_float("You actually owe us money, please enter a different amount!\n");
        goto change;
    }
    else if (change == 0)
    {
        printf("There is no change for you to receive\n");
        goto end;
    }
    else
    {
        printf("You are owed $%.5f \n", change);
    }
    int cents = round(change * 100);
    printf("Which is %i ¢\n", cents);
    calculate(cents); //stuff
end:
    return 0;
}
void calculate(int coins) //stuff
{ 
    int quarters, modQuarters, dimes, modDimes, nickles, modNickles, pennies, modPennies, totalCoins;
    quarters = coins / 25; //stuff
    modQuarters = coins % 25; //stuff
    dimes = modQuarters / 10; //stuff
    modDimes = modQuarters % 10; //stuff
    nickles = modDimes / 5; //stuff
    modNickles = modDimes % 5; //stuff
    pennies = modNickles / 1; //stuff
    modPennies = modNickles % 1; //stuff
    totalCoins = quarters + dimes + nickles + pennies; //stuff
    printf("We need to return %i Quarters, %i Dimes, %i Nickles, %i Pennies\n", quarters, dimes, nickles, pennies);
    printf("For a total of %i coins\n", totalCoins);
 
}
