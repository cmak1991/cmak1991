#include <cs50.h>
#include <stdio.h>

// 4003600000000014

string get_card_type(long cc);

int main(void)
{
// ask for credit card number
    long cc;
    {
        cc = get_long("CC Number: ");
        // printf("%li\n", number);
    }

// what kind of card is it
    string card_type = get_card_type(cc);

// check for card length
    int length = 0;
    long number = cc;
    while (number > 0)
    {
        number /= 10;
        length++;
    }

    // must be 13, 15, or 16 digits
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

// calculate checksum
    long last = cc;
    int sum1 = 0;
    int sum2 = 0;

    do
    {
        // get last digit of number
        int mod1 = last % 10;

        // remove last digit of number and add to sum1
        last /= 10;
        sum1 += mod1;

        // remove second to last digit
        int mod2 = last % 10;
        last /= 10;

        // double second to last digit and add to sum2
        mod2 *= 2;
        int d1 = mod2 % 10;
        int d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (last > 0);

    int total = sum1 + sum2;

// print output
    // if checksum requirements are met
    if (total % 10 == 0)
    {
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}

// define get_card_type function
string get_card_type(long cc)
{
    string card_type;

    // get first two digits
    long start = cc;

    do
    {
        start /= 10;
    }
    while (start > 100);

    // AMEX if starts with 34 or 37
    if (start == 34 || start == 37)
    {
        card_type = "AMEX";
    }
    // MC if starts with 51, 52, 53, 54, or 55
    else if ((start / 10 == 5) && (0 < (start % 10) && (start % 10) < 6))
    {
        card_type = "MASTERCARD";
    }
    // VISA if starts with 4
    else if (start / 10 == 4)
    {
        card_type = "VISA";
    }
    // otherwise INVALID
    else
    {
        card_type = "INVALID";
    }

    return card_type;
}
