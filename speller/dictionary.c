// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>




#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 25;  // for letters in the alphabet

// Hash table
node *table[N];
int numWords = 0;


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fptr = fopen(dictionary, "r"); // opens dictionary

    if (fptr == NULL) // checks if it exists
    {
        return false; // returns false if it doesn't
    }

    char tempWord[LENGTH + 1]; // buffer that holds 1 word from dictionary.

    while (fscanf(fptr, "%s", tempWord) != EOF) // reads a string at a time into buffer (tmpw)
    {
        node *tempNode = malloc(sizeof(node));
        strcpy(tempNode->word, tempWord);

        int key = hash(tempWord);
        if (key < 0 || key >= N)
        {
            free(tempNode);
            continue;
        }
        if (table[key] == NULL)
        {
            tempNode->next = NULL;
            table[key] = tempNode;
        }
        else
        {
            tempNode->next = table[key];
            table[key] = tempNode;
        }
        numWords++;

    }
    fclose(fptr);
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0xFFFFFFFF;
    if (word[0] != '\0')
    {
        int num = tolower(word[0]);
        if (num >= 'a' && num <= 'z')
        {
            value = num - 'a';
        }
        else
        {
            value = 0xFFFFFFFE;
        }
    }
    return value;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    int key = hash(word);
    if (key >= 0 && key < N)
    {
        node *cursor = table[key];
        while (cursor != NULL)
        {

            int ret = strcasecmp(cursor->word, word);
            if (ret == 0) //*(*(table + key)).word
            {
                return true;
            }
            cursor = cursor->next;
        }
    }
    return false;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *pNode = table[i];
        while (pNode != NULL)
        {
            node *pNodeNext = pNode->next; //(*pNode).next
            free(pNode);
            pNode = pNodeNext;
        }
    }
    return true;
}
