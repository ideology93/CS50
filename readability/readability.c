#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <math.h>



int main(int argc, string argv[])
{
    string input = get_string("Text: ");
    float letters = 0;
    float sentences = 0;
    float words = 0;
    float nonletter = 0;
    float spaces = 0;
    float dashes = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ',' || input[i] == '\'' || input[i] == '\"' || input[i] == ':' || input[i] == ';')
        {
            nonletter++;
        }
        else if (input[i] == ' ')
        {
            spaces++;
        }
        else if (input[i] == '-')
        {
            dashes++;
        }
        else if (input[i] == '?' || input[i] == '!' || input[i] == '.')  //writes grade
        {
            sentences++;
        }
        else
        {
            letters++;
        }
    }

    words = (spaces + 1);  // idk but it works
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8; //formula
    int grade = round(index);
    if (grade > 16)
    {
        printf("Grade 16+\n"); //writes grade
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n"); //writes grade
    }
    else
    {
        printf("Grade %i\n", grade); //writes grade
    }

}
