#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int popi, pope, popendyear, years = 0;
    do
    {
        popi = get_int("Start size:\n");
        
    }
    while (popi < 9);

    // TODO: Prompt for end size
    do
    {
        pope = get_int("End size:\n");
        
    }
    while (pope < popi);

    // TODO: Calculate number of years until we reach threshold
    if (popi != pope)
    {
        do
        {
            popendyear = popi + (popi / 3) - (popi / 4);
            popi = popendyear;
            years++;
        
        }
        while (popendyear < pope);
    }
   
    // TODO: Print number of years
    printf("Years: %i\n", years);
}