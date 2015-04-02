/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm (binary search)
    
    // lower and upper limits
    int low = 0;        
    int up = n - 1;
    
    while(low <= up)
    {
        int mid = (up + low)/2;
        
        // value found
        if(values[mid] == value)
            return true;
        // update upper bound
        else if(value < values[mid])
            up = mid - 1;
        // update lower bound
        else if(value > values[mid])
            low = mid + 1;
    }       
     
    return false; // not in list
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int temp; // for swap
    int swap; // optimisation, swap recorder
    
    // go through array
    for(int k = 0; k < n - 1; k++)
    {
        swap = 0; 
        
        for(int i = 0; i < n - 1 - k; i++)
        {
            // swap if not in order
            if(values[i] > values[i+1])
            {
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swap++;
            }
            
        }
        // no swaps - sorted
        if(!swap)
        {
            break;
        }
    }
}
