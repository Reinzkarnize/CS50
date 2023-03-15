// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// const unsigned int N = 676;
const unsigned int N = 17576;
int total_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // decide wich bucket word will go
    int len = strlen(word);
    int tab = 676 * (toupper(word[0]) - 'A');

    if (len >= 2)
    {
        tab += 26 * (toupper(word[1]) - 'A');
    }
    if (len >= 3)
    {
        tab += (toupper(word[2]) - 'A');
    }

    // convert word to lowercase
    char text[len];
    strcpy(text, word);
    for (int i = 0; i < len; i++)
    {
        text[i] = tolower(text[i]);
    }

    node *cursor = table[tab];
    while (cursor != NULL)
    {
        if (strcmp(text, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';
    int len = strlen(word);
    int tab = 676 * (toupper(word[0]) - 'A');

    if (len >= 2)
    {
        tab += 26 * (toupper(word[1]) - 'A');
    }
    if (len >= 3)
    {
        tab += (toupper(word[2]) - 'A');
    }
    return tab;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    char word[LENGTH];

    for (int i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));
        if (table[i] == NULL)
        {
            printf("Error allocating memory");
            unload();
            return false;
        }
        table[i]->next = NULL;

        for (int j = 0; j < LENGTH + 1; j++)
        {
            table[i]->word[j] = '\0';
        }
    }

    while (fscanf(infile, "%s", word) != EOF)
    {
        // determine wich bucket the word will go
        int tab = hash(word);

        // allocate new memory for the word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Error allocating memory");
            unload();
            return false;
        }

        // set value to NULL
        for (int i = 0; i < LENGTH + 1; i++)
        {
            n->word[i] = '\0';
        }

        // put dictionary word to the hash table
        for (int i = 0, len = strlen(word); i < len; i++)
        {
            n->word[i] = word[i];
        }
        n->next = table[tab];

        table[tab] = n;
        total_words++;
    }

    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
