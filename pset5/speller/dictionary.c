// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

void insert(node *, unsigned int);

// Number of buckets in hash table
const unsigned int N = 10000;

// Counter number of words in dictionary as loaded in hash table
int wordsCounter = 0;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[n] = '\0';
    
    // Initializes index for hashed word
    unsigned int index = hash(word_copy);
    
    //unsigned int index = hash(word);      
    node *cursor = table[index];

    while (cursor != NULL)
    {
        // Compares the 2 words case insensitive
        if (strcasecmp(cursor->word, word) == 0)
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
    unsigned int hash = 0;

    //Hash function from reddit by delipity
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }

    return hash % N;

    //hash function using as much buckets as letters of alphabet - time to check 0.42
    //return (tolower(word[0]) - 'a');          // Change N to 26
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char wordBuffer[LENGTH + 1];

    // Scan from the file each word and save in wordBuffer
    while (fscanf(dict, "%s", wordBuffer) != EOF)
    {
        node *newNode = NULL;

        if ((newNode = malloc(sizeof(node))) == NULL)
        {
            return false;
        }

        // Assign to newNode the word and newNode points at NULL so it is always initialized
        strcpy(newNode->word, wordBuffer);
        newNode->next = NULL;
        
        // Hash the word, returns the index where newNode should be located
        unsigned int index = hash(wordBuffer);

        // Insert node into hash table at the index provided by hash function
        insert(newNode, index);
    }

    fclose(dict);

    return true;
}

// Inserts each node into the hash table
void insert(node *newNode, unsigned int index)
{
    node *headList = table[index];
    // Check if the linked list is empty, if it is then newNode is the first node
    if (headList == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        //newNode will be pointing to the first node in list
        newNode->next = table[index];
        //table[index] will be pointing now to the new word
        table[index] = newNode;
    }

    // Update the wordsCounter that are loaded for using it later in size function
    wordsCounter++;

    return;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordsCounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // If there is a loaded dictionary the free its memory
    if (&load)
    {
        for (int i = 0; i < N; i++)
        {
            node *cursor = table[i];
            node *tmp = NULL;
            while (cursor != NULL)
            {
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }

            free(cursor);
        }

        return true;
    }

    return false;
}
