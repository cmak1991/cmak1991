#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_alpha(string key);
bool no_repeats(string key);

int main(int argc, string argv[])
{
    // ensure only one command line argument is input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // ensure key contains all letters
    if (!(only_alpha(argv[1])))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // ensure key contains 26 digits
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // ensure key contains each letter exactly once
    if (!(no_repeats(argv[1])))
    {
        printf("Key must contain 26 distinct characters.\n");
        return 1;
    }

    // prompt user for plaintext
    string text = get_string("plaintext:  ");
    string cipher = text;
    string key = (argv[1]);

    // encipher
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]))
        {
            int location = text[i] - 97;
            cipher[i] = tolower(key[location]);
        }
        else if (isupper(text[i]))
        {
            int location = text[i] - 65;
            cipher[i] = toupper(key[location]);
        }
        else
        {
            cipher[i] = text[i];
        }
    }

    // output ciphertext
    printf("ciphertext: %s\n", cipher);
    return 0;
}

bool only_alpha(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!(isalpha(key[i])))
        {
            return false;
        }
    }
    return true;
}

bool no_repeats(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = 1; j < strlen(key); j++)
        {
            if (key[i] == key[j] && i != j)
            {
                return false;
            }
        }
    }
    return true;
}
