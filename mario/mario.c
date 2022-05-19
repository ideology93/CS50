#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height = get_int("Height:\n");
height:
    if (height < 1 || height > 8)
    {
        printf("Please enter a number between 1 and 8\n"); // asks for input again
        height = get_int("Height:\n");  // asks for input again if its wrong
        goto height; // goes back to the if statement
    }
     
    int cnt1 = height;   // 2 counters to i
    int cnt2 = height;
   
    for (int i = 0; i < height; i++) //loops stuff
    {     
        cnt1--;
        cnt2--;
        for (int b = 0; b < cnt1; b++)
        {    
            printf(" ");
        }
        for (int dee = cnt1; dee < height; dee++) //loops more stuff
        {
            printf("#");
        }
        printf("  ");
        for (int j = cnt2; j < height; j++)//loops more stuff
        {  
            printf("#");  
        }
        printf("\n");
    }
}
