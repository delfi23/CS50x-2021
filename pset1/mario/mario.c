#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0, i = 0, j = 0;

    // Ask for height to user until enters a valid one beteween 1 and 8
    do
    {
        n = get_int("Height:\n");
    }
    while (n < 1 || n > 8);

    // i is for lines and j is for columns
    
    for (i = n - 1; i >= 0; i--)
    {
        // j until double n plus 2 for the spaces in middle
        for (j = 0; j < (n * 2) + 2; j++)
        {
            // If it is not one of the middle spaces
            if(j != n & j != n + 1)
            {   
                if (i <= j & (i + j) <= (n * 2) + 1)
                {
                    printf("#");
                }
                else if((i + j) <= (n * 2) + 1)
                {
                    printf(" ");
                }
            }
            else
            {
                printf(" ");
            }

        }

        printf("\n");
    }

}