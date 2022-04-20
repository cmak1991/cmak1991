#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
// ensure proper usage
    // only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // only digits as key
    if (!(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert argv[1] to int
    int k = atoi(argv[1]);

    // only positive digits
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // get plaintext from user
    string text = get_string("plaintext:  ");
    string cipher = text;

    // encrypt plaintext
    for (int i = 0; i < strlen(text); i++)
    {
        cipher[i] = rotate(text[i], k);
    }

    // print ciphertext
    printf("ciphertext: %s\n", cipher);
}

bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!(isdigit(key[i])))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char newc;
    if isupper(c)
    {
        newc = ((c - 65 + n) % 26) + 65;
    }
    else if islower(c)
    {
        newc = ((c - 97 + n) % 26) + 97;
    }
    else
    {
        newc = c;
    }
    return newc;
}
