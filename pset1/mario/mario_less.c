/*#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0, i = 0, j = 0;

    do
    {
        n = get_int("Height:\n");
    }
    while (n < 1 || n > 8);

    for (i = n-1; i >= 0; i--)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0, i = 0, j = 0;
    
    do
    {
        n = get_int("Height:\n");    
    }
    while (n < 1 || n > 8);
    
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < (n * 2) + 2; j++)
        {
            if(j != n & j != n + 1)
            {
                if (i <= j & (i + j) <= (n * 2) +1)
                {
                    printf("#");   
                }
                else
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