#include <stdio.h>
#include <cs50.h>


int height;

int main(void)
{
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);

    for(int i = 0; i < height; i++) 
	{
        for(int x = 0; x < height-1-i; x++)
        {
            printf(" ");
        }
        
		for(int y = 0; y < i+2; y++)
		{
			printf("#");
		}
		
		printf("\n");
	}	
}