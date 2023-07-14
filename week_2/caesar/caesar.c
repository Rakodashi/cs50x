#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
void encrypt(string plaintext, string ciphertext, int k);


int main(int argc, string argv[])
{
    // argv[0] = "./caesar"
    //argv[1] = key

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Validation done
    int k = atoi(argv[1]);
    string s = get_string("plaintext: ");
    int n = strlen(s);
    char ciphertext[n + 1];
    encrypt(s, ciphertext, k);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

void encrypt(string plaintext, string ciphertext, int k)
{
    int i = 0;
    for (i = 0; i < strlen(plaintext); i++)
    {
        char currentCh = plaintext[i];

        if (isalpha(currentCh))
        {
            char temp = tolower(currentCh);
            int pi = temp - 'a';
            char ci = ((pi + k) % 26) + 'a';
            ciphertext[i] = islower(currentCh) ? ci : toupper(ci);
        }
        else
        {
            ciphertext[i] = currentCh;
        }
    }
    // Ciphertext done:
    ciphertext[i] = '\0';
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char currentCh = s[i];
        if (!isdigit(currentCh))
        {
            return false;
        }
    }
    return true;
}
// Make sure program was run with just one command-line argument

// Make sure every character in argv[1] is a digit

// Convert argv[1] from a `string` to an `int`

// Prompt user for plaintext

// For each character in the plaintext:

// Rotate the character if it's a letter


//TODO

//Get key
//Get paintext
//Encipher
//Print ciphertext

/*
int key = 0;
string plaintext;
string cyphertext;

    strlen(text) = ~
    int get_string("%d\n", plaintext)
    {
        printf("Plaintext: %s\n")
        return 0;
    }
    isalpha("A") = true
    isupper("A") = true
    islower("A") = false

atoi(argv[])

char rotate(char c, int n)
{
    rotate ("A", 1)
}

Ci = (Pi + k) % 26

if argc == 1
int get_plaintext(string plaintext)
*/