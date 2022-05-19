#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Enter the height of pyramid: \n");
height:
    if (height < 1 || height > 8)
    {
        printf("Error: Please enter a number between 1 and 8!\n");
        height = get_int("Enter another value: \n");
        goto height;
    }
    int goingdown = height;
    int space_counter = 0;
    for (int i = 0; i < height; i++)  // outter loop for the height
    {
        goingdown--;// 4
        for (int j = 0; j < goingdown; j++)  // going through spaces
        {
            printf(" ");
            space_counter++;
        }
        for (int g = goingdown; g < height; g++)  // going through hashtags - spaces
        {
            printf("#");
        }
        printf("\n");
    }
}
