#include <stdio.h>
#include <cs50.h>

string usersname(void);

int main(void)
{
    string name = usersname();  //save what the user types in variable name. Main calls the functiion usersname
    printf("Hello %s!\n", name);
}

string usersname(void) //function that ask name and return it as a string
{
    string n = get_string("What's your name?:\n");
    return n;
}