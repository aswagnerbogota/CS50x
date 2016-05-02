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
    // TODO: implement a searching algorithm
    int max = n - 1;
    int min = 0;
    
    while (max >= min)
    {
        int midpoint = (max + min) / 2;
        if (values[midpoint] == value)
        {
            return true;
        }
        else if (values[midpoint] > value)
        {
            max = midpoint - 1;
        }
        else 
        {
            min = midpoint + 1;
        }
    }
    return false;
}
    


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        
        for (int j = i+1; j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int hold = values[min];
            values[min] = values[i];
            values[i] = hold;
        }
    }
    
    
    
    return;
}

/* Linear Search
  
      if ( n < 1)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        {
            return true;
        }
    }
    return false;

*/
