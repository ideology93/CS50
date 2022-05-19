#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1 || !isdigit(*argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);  // sets key to first argument when starting
    if (argc == 2 && isdigit(*argv[1]) > 0) //  checks if there is an entered argument
    {
        string plaintext = get_string("plaintext: \n");  // gets input from user, the text we want ENCRYPTED
        int str = strlen(plaintext);    // string length
        printf("ciphertext: ");
        for (int i = 0; i < str; i++)    // loops through string
        {
            int remains = key % 26;      // checks what the remainder is, in case the number of cypher goes past letter Z, it loops through
            int current_char = plaintext[i];   // saves ascii val of current char in string to an int variable
            int finaleone = remains + current_char;
            if (islower(current_char) && isalpha(current_char))  // check for lowercase & if its a letter
            {
                if (finaleone > 122) // removes the 0th and 25chars
                {
                    int finaletwo = finaleone - 123;
                    current_char = 97;
                    printf("%c", current_char + finaletwo);
                }
                else
                {
                    printf("%c", finaleone);
                }
            }
            else if (isupper(current_char) && isalpha(current_char)) // check for uppercase & if its a letter
            {
                if (finaleone > 90)
                {
                    int finaletwo = finaleone - 91;
                    current_char = 65;
                    printf("%c", current_char + finaletwo);
                }
                else
                {
                    printf("%c", finaleone);
                }
            }
            else
            {
                printf("%c", current_char);
            }
        }
        printf("\n");
        return 0;
    }
}