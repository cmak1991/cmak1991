#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8
    index = grade level of text
    L = avg number of letters per 100 words
    S = avg number of sentences per 100 words
*/

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// takes a text and determines its reading level by computing the Coleman-Liau index of the text
int main(void)
{
    // prompts user for string of text
    string text = get_string("Text: ");
    //printf("%s\n", text);

    // count number of letters (any lower or upper case character from a to z)
    int letters = count_letters(text);
    //printf("%i letters\n", letters);

    // count number of words (separated by a space " ")
    int words = count_words(text);
    //printf("%i words\n", words);

    // count number of sentences (end marked by "." "?" "!")
    int sentences = count_sentences(text);
    //printf("%i sentences\n", sentences);

    // print grade level rounded to nearest integer
    float avg_letters = (float) letters / (float) words * 100;
    float avg_sentences = (float) sentences / (float) words * 100;
    int index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);
    //printf("%i\n", index);

    // if index < 1, print "Before Grade 1"
    if (index < 1)
    {
        printf("Before Grade 1");
    }

    // if index > 16, print "Grade 16+"
    else if (index > 16)
    {
        printf("Grade 16+");
    }

    else
    {
        printf("Grade %i", index);
    }
    printf("\n");
}

// count the number of letters in a text
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }

    // returns 0 if not a letter
    // int isalpha(char c);

    return letters;
}

// count the number of words in a text
int count_words(string text)
{
    int words = 1;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    return words;
}

// count the number of sentences in a text
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}
