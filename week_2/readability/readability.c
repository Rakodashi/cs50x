#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


int get_index(string sample);

int main(void)
{

    // Get text sample and print according to level
    string text = get_string("Text: ");
    int index = get_index(text);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %d\n", index);
        return 0;
    }
}

int get_index(string sample)
{
    int letters = 0, words = 0, sents = 0;

    for (int i = 0; i < strlen(sample); i++)
    {
        // Count letters
        char ch = sample[i];
        if (isalpha(ch))
        {
            letters++;
        }

        // Count words
        if (isspace(ch))
        {
            words++;
        }

        // Count sentences
        if (ch == '!' || ch == '?' || ch == '.')
        {
            sents++;
        }
    }
    words++;

    // Plugging in the Coleman-Liau formula
    float L = (letters * 100.0f) / words;
    float S = (sents * 100.0f) / words;
    return round(0.0588 * L - 0.296 * S - 15.8);
}