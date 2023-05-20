// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 200000;

// Hash table
node *table[N];

//dictionary size
int DICT_SIZE = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_index;
    node *cursor = NULL;
    bool answer = false;
    //node *temp = NULL;
    // TODO
    //hash word to obtain a hash value
    hash_index = hash(word);
    //access linked list at that index in the hash table
    cursor = table[hash_index];
    //traverse linked list, looking for the word (strcasecmp)
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            answer = true;
        }
        cursor = cursor->next;
    }
    return answer;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //sums up ascii value
    long ascii_value = 0;
    while (*word)
    {
        ascii_value += tolower(*word);
        word++;
    }
    return (ascii_value % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    char temp_word[LENGTH + 1];
    //index in hash table
    int hash_index = 0;
    if (!dict)
    {
        fclose(dict);
        return (false);
    }
    //read strings from file
    while (fscanf(dict, "%s", temp_word) != EOF)
    {
        //create a new node
        node *n = malloc(sizeof(node));
        //check if return value is not NULL
        if (!n)
        {
            unload();
            return (false);
        }
        //copy word into node using strcpy
        strcpy(n->word, temp_word);
        //hash word
        hash_index = hash(temp_word);
        //insert word into hash table
        //if hashtable is empty at index, insert
        if (table[hash_index] == NULL)
        {
            table[hash_index] = n;
            n->next = NULL;
            //count the number of words in the dictionary
            DICT_SIZE++;
        }
        // if hashtable is not empty at index, append
        else
        {
            n->next = table[hash_index];
            table[hash_index] = n;
            //count the number of words in the dictionary
            DICT_SIZE++;
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return (DICT_SIZE);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int i = 0;
    while (i < N)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if (i == N - 1 && cursor == NULL)
        {
            return (true);
        }
        i++;
    }
    return (false);
}
