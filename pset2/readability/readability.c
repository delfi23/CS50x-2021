# include<stdio.h>
# include<cs50.h>
# include<ctype.h>
# include<math.h>

int main(void)
{
    // words starts in one because if not it doesnt count the last one
    int letters = 0, words = 1, sentences = 0, grade = 0;
    float L = 0, S = 0;
    
    string text = get_string("TEXT: ");
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        // when text[i] is an alphabetic character then add one to letters until string ends in \0
        if (isalpha(text[i]))
        {
            letters++;
        }
        // when text[i] is a white space then add one to words until string ends in \0
        else if (text[i] == ' ')
        {
            words++;
        }
        // when text[i] is a dot a coma or a ? then add one to sentences until string ends in \0
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    
    L = (float) letters / words * 100;
    S = (float) sentences / words * 100;
    
    grade = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
