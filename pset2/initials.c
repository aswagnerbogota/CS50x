#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Declare Variables
    string name = GetString();
    int stringl = strlen(name);
    
    // Print first letter of string as capital letter
    printf("%c", toupper (name[0]));
    
    // Look for spaces and print letter after as capital
    for (int i = 0; i < stringl; i++)
    {
        if (name[i] == 32)
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}