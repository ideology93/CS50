#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error - lease provide a username!"); // yes
        return 1;
    }
    char salt[2] = {argv[1][0], argv[1][1]}; // yes

    char password[6] = "\0\0\0\0\0\0"; // yes
    string alphabet = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // yes
    int numofletters = 53;
    string hash = argv[1];
    // char salt[3];
    // memcpy(salt, hash, 2);
    // salt[2] = '\0';
    for (int five = 0; five < numofletters; five++) // yes
    {

        for (int four = 0; four < numofletters; four++) // yes
        {

            for (int three = 0; three < numofletters; three++) // yes
            {

                for (int two = 0; two < numofletters; two++) // yes
                {

                    for (int one = 0; one < numofletters; one++) // yes
                    {
                        password[0] = alphabet[one];
                        password[1] = alphabet[two];
                        password[2] = alphabet[three];
                        password[3] = alphabet[four];
                        password[4] = alphabet[five];
                        if (strcmp(crypt(password, salt), hash) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
