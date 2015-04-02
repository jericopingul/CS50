/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#include "dictionary.h"


// create hash table and assign to null
node* hTable[HT_SIZE] = {NULL};

// global variable to count number of words in dictionary
int nWords = 0;

/**
 * Creating hash function
 * Returns index of the "bucket"/array
 */
int hashFunction(const char* word)
{
    int index = 0;
    
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        index += word[i];
    
    }
    
    return index % HT_SIZE;
    
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int n = strlen(word);
    // variable for lower case
    char lCase[n + 1];
    int i;
    // change to lower case
    for(i = 0; i < n; i++)
    {
        lCase[i] = tolower(word[i]);
    }
    lCase[i] = '\0';
    
    // get index of location in hash table
    int index = hashFunction(lCase);
    
    // if hashtable empty
    if(hTable[index] == NULL)
    {
        return false;
    }
    
    // node to compare with word to be found
    node* cursor = hTable[index];
    
    // while we haven't reached the end of the list
    while(cursor != NULL)
    {
        // compare if our word matches a word in list
        if(!strcmp(lCase, cursor->word))
        {
            return true;    // found
        }
        
        cursor = cursor->next;
    }
    
    // word not in dictionary
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary for read and check
    FILE *f = fopen(dictionary, "r");
    if(f == NULL)
    {
        return false;
    }
    
    // array to store word
    char word[LENGTH + 1];
    
    // go through file and load every word onto hash table
    while (fscanf(f, "%s\n", word)!= EOF)
    {
        // create new node memory for new word
        node* newNode = malloc(sizeof(node));
        
        // copy new word onto node
        strcpy(newNode->word, word);
        
        // increase number of words
        nWords++;
        
        // index of where to place word in hash table
        int index = hashFunction(word);
        
        // if the hashtable is pointing to null at this index
        // insert as head of list
        if(hTable[index] == NULL)
        {
            hTable[index] = newNode;
            newNode->next = NULL;
        }
        // otherwise if hashtable is not empty
        // insert node at head of the list
        else
        {
            newNode->next = hTable[index];
            hTable[index] = newNode;
        }
    }
    
    fclose(f);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return nWords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    int index = 0;
    
    while(index < HT_SIZE)
    {
        // move onto the next index if this index is empty
        if(hTable[index] == NULL)
        {
            index++;
        }
        // otherwise
        else
        {
            while(hTable[index] != NULL)
            {
                // temporary variable pointer to free memory
                node* temp = hTable[index];
                
                // move onto next in link list 
                hTable[index] = temp->next;
                
                // clear memory from this temporary memory
                free(temp);
            }
            
            // move onto next index once this list is cleared
            index++;
        }
        
    }
    
    // return true once successful
    return true;
}
