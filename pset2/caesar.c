#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
// Declare variables
    string k;
    int key;
    string message;

// Get Key and convert to int
    if (argc != 2)
    {
        printf("Retry!\n");
        return 1;
    }
    else 
    {
        k = argv[1];
        key = atoi(k);
        if (key == 0)
        {
            printf("Input needs to be numeric!!\n");
            return 1;
        }
    }
    
// Convert key to key2 under 26
    int key2 = (key % 26);
    
// Get Message
    message = GetString();
    
// Encipher
// Check each characrter by itself
    for (int i = 0, n = strlen(message); i < n; i++)
    {
    
// Lower case letters
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            if ((message[i] + key2) > 'z')
            {
                printf("%c", (((message[i] + key2) % 122) + 96));
            }
            else
            {
                printf("%c", (message[i] + key2));
            }
        }
        
// Capital letters
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            if ((message[i] + key2) > 'Z')
            {
                printf("%c", (((message[i] + key2) % 90) + 64));
            }
            else
            {
                printf("%c", (message[i] + key2));
            }
        }
    
// Symbols etc.
        else
        {
            printf("%c", message[i]);
        }
    }
    
printf("\n");
}