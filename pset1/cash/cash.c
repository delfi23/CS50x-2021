# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    float change;
    int q = 0, d = 0, n = 0, p = 0, coins = 0;
    
    // Prompt for amount change
    do
    {
        change = get_float("Change owed:  ");
    }
    while (change < 0);
    
    int cents = round(change * 100);    //Convert dollars into pennies
    q = cents / 25;                     // q is the amount of quarter coins needed
    d = (cents - q * 25) / 10;          // d is for the dime coins
    n = (cents - q * 25 - d * 10) / 5;  // n for the nickels
    p = (cents - q * 25 - d * 10 - n * 5);  // p for the pennies needed
    
    printf("Coins: %i\n", q + d + n + p); // total amount of coins will be summing up all 4 
    
}