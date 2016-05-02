#include <stdio.h>
#include <cs50.h>
#include <math.h>

float input;

int main(void)
{
        // Sends start message, gets the Users input, checks for correctness, multiplies by 100, and rounds it up
    printf("O, hai!");
    do
    {
        printf("How much changed is owed?");
        input = GetFloat();
    }
    while(input < 0);
    int rounded;
    
    rounded = round(input * 100);
    
    
    // Calculate Coins
    int counter = 0;
    
    while (rounded >= 25)
    {
        rounded = rounded - 25;
        counter++;
    }
    while (rounded >= 10)
    {
        rounded = rounded - 10;
        counter++;
    }
    while (rounded >= 5)
    {
        rounded = rounded - 5;
        counter++;
    }
    while(rounded >= 1)
    {
        rounded = rounded - 1;
        counter++;
    }
    printf("%d\n", counter);
    
}