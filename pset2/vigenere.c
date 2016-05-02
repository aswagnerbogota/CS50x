#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
// Declare Variables and Arrays
    string key, message;

// Check Command Line Argument Count
    if (argc != 2)
    {
        printf("Retry!\n");
        return 1;
    }
    
// Check that keyword only uses letters
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                key = argv[1];
            }
            else
            {
                printf("Keyword has to be letters only!!\n");
                return 1;
            }
        }
    }
    
// Get plaintext input
    message = GetString();

// Key Variables
    int key_length = strlen(key);
    int message_length = strlen(message);
    int key_array[key_length];
    int key_strlen_array[message_length];
    int rotation_array[message_length];

// Create key_array (How many times does letter need to be shifted)
    for (int j = 0; j < key_length; j++)
    {
        if (isupper(key[j]))
        {
            key_array[j] = (key[j] - 65);
        }
        else if (islower(key[j]))
        {
            key_array[j] = (key[j] - 97);
        }
    }

// Create key_strlen_array (Points to key_array and tells rotation_array how many times to shift)
    for (int k = 0, x = 0; k < message_length; k++, x++)
    {
        if (isalpha(message[k]))
        {
            key_strlen_array[k] = x % key_length;
        }
        else
        {
            key_strlen_array[k] = 99;
            x--;
        }
        
// Create rotation_array (How many times to rotate letter)
        if (key_strlen_array[k] >= 0 && key_strlen_array[k] <= 26)
        {
            rotation_array[k] = key_array[key_strlen_array[k]];
        }
        else if (key_strlen_array[k] == 99)
        {
            rotation_array[k] = 0;
        }
    }

// Encipher
    for (int i = 0; i < message_length; i++)
    {
        
// Capital Letters
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            if ((message[i] + rotation_array[i]) > 'Z')
            {
                printf("%c", (((message[i] + rotation_array[i]) % 90) + 64));
            }
            else
            {
                printf("%c", (message[i] + rotation_array[i]));
            }
        }
        
// Lower case letters
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            if ((message[i] + rotation_array[i]) > 'z')
            {
                printf("%c", (((message[i] + rotation_array[i]) % 122) + 96));
            }
            else
            {
                printf("%c", (message[i] + rotation_array[i]));
            }
        }
        
// Symbols etc.
        else
        {
            printf("%c", (message[i] + rotation_array[i]));
        }
    }
    printf("\n");
    return 0;
}