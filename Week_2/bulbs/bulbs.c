#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(char bit);
char *convert_to_binary(char dec);
void convert_to_emoji(string binary);
int message_length(string message);

int main(void)
{
    string message = get_string("Message: ");
    int m_l = message_length(message);
    int i = 0;
    while (i < m_l)
    {
        convert_to_emoji(convert_to_binary(message[i]));
        i++;
    }
}

//converting character to a string of its binary equivalent
char *convert_to_binary(char c)
{
    int j = 0;
    char *res;

    res = (char *)malloc(8 * sizeof(char));
    int i = 128;
    {
        while (i > 0 && j < 8)
        {
            if (c >= i)
            {
                res[j] = '1';
                c %= i;
                i /= 2;
            }
            else
            {
                res[j] = '0';
                i /= 2;
            }
            j++;
        }
    }
    return (res);
}

void print_bulb(char bit)
{
    if (bit == '0')
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == '1')
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void convert_to_emoji(string binary)
{
    int i = 0;
    while (i < 8)
    {
        print_bulb(binary[i]);
        i++;
    }
    printf("\n");
}

int message_length(string message)
{
    int length = 0;
    while (message[length])
    {
        length++;
    }
    return (length);
}