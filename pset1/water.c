#include <stdio.h>
#include <cs50.h>

int bottles(int x)
{
    return x * 12;
}

int main(void)
{
    printf("minutes: ");
    int n = GetInt(); 
    n = bottles(n);
    printf("bottles: %i\n", n);
}

