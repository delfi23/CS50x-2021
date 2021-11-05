#include <stdio.h>

int main(void)
{
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", numbers[i]);
    }
    
    printf("\n");
    
    int tot = 9, temp;
    
    for (int i = 0; i < 10 / 2; i++)
    {
        
        temp = numbers[i];
        numbers[i] = numbers[tot];
        numbers[tot] = temp;
        tot = tot - 1;
    }
    
    printf("\n");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", numbers[i]);
    }
    printf("\n");
}


/*

for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][(width -1) - j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++ )
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = buffer[i][j];
        }
    }
    
*/

