# include<stdio.h>              
# include<cs50.h>
# include<string.h>
# include<ctype.h>

bool validate(string); //function to validate that users gives a correct string
int noncharacter(string); //returns 1 if there is a nonchar and 0 if there is not
int repeatedcharacter(string); // 1 if repeated, 0 if not

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else
    {
        string key = argv[1];
        string abc = "abcdefghijklmnopqrstuvwxyz";
        
        // Check that user enter a validate key
        if (validate(key))
        {
            string plain = get_string("plaintext: ");
            int len = strlen(plain);
            char cypher[len];
            
            for (int i = 0; i < len; i++)
            {
                //Check if plain[i] is a character
                if (isalpha(plain[i]))
                {
                    //Compare with the alphabet and see in which position is that letter
                    //Then save in cypher the corresponding letter to that position in string key
                    for(int j = 0; j < 26; j++)
                    {
                        if(abc[j] == (tolower(plain[i])))
                        {
                            //Preserve case if upper and lower
                            if (isupper(plain[i]))
                            {
                                cypher[i] = toupper(key[j]);
                            }
                            else
                            {
                                cypher[i] = tolower(key[j]);
                            }
                            break;
                        }
                    }
                }
                else
                {
                    //If not alphabetic save it in cypher as it is
                    cypher[i] = plain[i];
                }
            }
            cypher[len] = '\0';
                
            printf("ciphertext: %s", cypher);
            printf("\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

bool validate(string key)
{
    //user enter a key with more than 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    //user enter a key with 26 characters but it contains non characters as well
    else
    {
        if (noncharacter(key))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
        //user enter a key with 26 characters but it contains repeated characters
        else if (repeatedcharacter(key))
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
        else
        {
            return true;
        }
    }
}

int noncharacter(string key)
{
    int r = 0, i = 0;
    
    do
    {
        if (!isalpha(key[i]))
        {
            r = 1;
        }
        i++;
    }
    while (isalpha(key[i]) || key[i] != '\0');

    return r;
}

int repeatedcharacter(string key)
{
    int r = 0;
    int n = strlen(key);
    
    for (int i = 0; i < n; i++)  
    {
        key[i] = tolower(key[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key[j] == key[i])
            {
                r = 1;
            }
        }
    }
    return r;
}