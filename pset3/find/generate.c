/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks to make sure there is at least two but maximum three command line arguments, otherwise returns false
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Declares variable n and changes command line argument 2 from a string into an integer as it's value
    int n = atoi(argv[1]);

    // Either takes user supplied seed input (Command line argument 3) and changes it from a string into an integer to use with srand48 as input for drand48
    // or takes the system time of the computer used as seed input.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Runs a loop n times and creates a random number every time which is multiplied by LIMIT to create a number above 1 which it then prints before repeating the step
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}