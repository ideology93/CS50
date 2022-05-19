#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digits_only(char *s);
int check(char *s);
int isUniqueChars(char *string);
int main(int argc, string argv[])
{
    int temp = 0;
    string alphabet = argv[1];
    if (argc == 1 || digits_only(argv[1]) == 0 || strlen(argv[1]) != 26 || isUniqueChars(argv[1]) == 0)

    {
        printf("Usage: /substitution key\n");
        return 1;
    }
    if (argc == 2 && isalpha(*argv[1]) > 0) //  checks if there is an entered argument
    {
        string plaintext = get_string("plaintext: \n");  // gets input from user, the text we want ENCRYPTED
        int j = 0;
        int textLength = strlen(plaintext);    // string length
        int keyLength = 26; // key length
        string newText[textLength];  // create new array size of entered text
        printf("ciphertext: ");
        for (int i = 0; i < textLength; i++)  // iterate thru array
        {
            char current_pt = plaintext[i];  //current charr in array
            if (islower(current_pt) && isalpha(current_pt))
            {
                int currentLetter = current_pt - 97; // -97 for lowercase

                printf("%c", tolower(alphabet[currentLetter]));
                j++;
            }
            else if (isupper(current_pt) && isalpha(current_pt))
            {
                int currentULetter = current_pt - 65;  // -65 for uppercase
                printf("%c", toupper(alphabet[currentULetter]));
                j++;
            }
            else
            {
                printf("%c", current_pt);
            }
        }
        printf("\n");
        return 0;

    }


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
int check(string s)
{
    int temp = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        temp = temp + toupper(s[i]);
    }
    if (temp != 2015)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isUniqueChars(char *string)
{
    int char_set[128] = {0};
    int val;
    for (int i = 0; i < strlen(string); i++)
    {
        val = (int)string[i];
        if (char_set[val] != 0)
        {
            return 0;
        }
        char_set[val] = 1;
    }
    return 1; //This returns 1 if the string is unique
}