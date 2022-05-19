#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int shift(char c);
int digits_only(char *s);
int main(int argc, string argv[])
{

    if (argc == 1 || digits_only(argv[1]) == 0)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    if (argc == 2 && isalpha(*argv[1]) > 0) //  checks if there is an entered argument
    {
        string plaintext = get_string("plaintext: \n");  // gets input from user, the text we want ENCRYPTED
        int ptlen = strlen(plaintext);    // string length
        int kwlen = strlen(argv[1]);
        printf("ciphertext: ");
        int cnt = 0;
        for (int i = 0; i < ptlen; i++)    // loops through string
        {
            char current_kw = tolower(argv[1][cnt]);
            int current_pt = plaintext[i];   // saves ascii val of current char in string to an int variable
            int remains = shift(current_kw);   //in case the number of cypher goes past letter Z, it loops through
            int finaleone = remains + current_pt;
            if (islower(current_pt) && isalpha(current_pt))  // check for lowercase & if its a letter
            {
                if (finaleone > 122) // removes the 0th and 25chars
                {
                    cnt++;
                    int finaletwo = finaleone - 123;
                    current_pt = 97;
                    printf("%c", current_pt + finaletwo);
                }
                else
                {
                    cnt++;
                    printf("%c", finaleone);
                }
            }
            else if (isupper(current_pt) && isalpha(current_pt)) // check for uppercase & if its a letter
            {
                if (finaleone > 90)
                {
                    cnt++;
                    int finaletwo = finaleone - 91;
                    current_pt = 65;
                    printf("%c", current_pt + finaletwo);
                }
                else
                {
                    cnt++;
                    printf("%c", finaleone);
                }
            }
            else
            {
                printf("%c", current_pt);

            }
            if (cnt == kwlen)
            {
                cnt = 0;
            }
        }
    }
    printf("\n");
    return 0;


}
int shift(char c)
{
    int move = tolower(c) - 97;
    return move;

}
int digits_only(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return 0;
        }

    }
    return 1;

}

