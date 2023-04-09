#include <cs50.h>
#include <stdio.h>

int sum_of_multiplied_digits(long card_number);
int sum_of_other_digits(long card_number);
int validity_check(long card_number);
int check_card_length(long card_number);
int check_starting_digits(long card_number);
int check_second_digit(long card_number);

int main(void)
{
    long card_number;
    int mult_d = 0;
    int d = 0;
    int valid, first_digit, card_length, second_digit;
    do
    {
        card_number = get_long("Number: ");
    }
    while(card_number <= 0);

    valid = validity_check(card_number);
    first_digit = check_starting_digits(card_number);
    card_length = check_card_length(card_number);
    second_digit = check_second_digit(card_number);
    //printf("%i\n", valid);
    //printf("%i\n", first_digit);
    //printf("%i\n", card_length);
    //printf("%i\n", second_digit);

    if(valid == 1)
    {
        if(first_digit == 3 && card_length == 15 && (second_digit == 34 || second_digit == 37))
        {
            printf("AMEX\n");
        }
        else if(first_digit == 5 && card_length == 16 && (second_digit >= 51 && second_digit <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if(first_digit == 4 && (card_length == 13 || card_length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
        {
            printf("INVALID\n");
        }

    return 0;
}

int sum_of_multiplied_digits(long card_number)
{
    int digit;
    int position = 0;
    int result = 0;
    int res_dig;
    int res_dec_dig;
    int final_res;
    while (card_number > 0)
    {
        digit = card_number % 10;
        card_number /= 10;
        if(position % 2 != 0)
        {
            //printf("pos %i dig %i", position, digit);
            result = digit*2;
            //printf("result is %i", result);
            if (result >= 10)
            {
                res_dig = result % 10;
                res_dec_dig = result / 10;
                result = res_dig + res_dec_dig;
            }
            final_res += result;
            //printf("final_res %i", final_res);
        }
        position++;
    }
    return final_res;
}

int sum_of_other_digits(long card_number)
{
    int digit;
    int position = 0;
    int final_res = 0;
    while (card_number > 0)
    {
        digit = card_number % 10;
        card_number /= 10;
        if(position % 2 == 0)
        {
            final_res += digit;
        }
        position++;
    }
    return final_res;
}

int validity_check(long card_number)
{
    int total_sum = 0;
    int a = 0;
    int b = 0;
    int result = 0;
    a = sum_of_multiplied_digits(card_number);
    b = sum_of_other_digits(card_number);
    total_sum = a + b;
    if(total_sum % 10 == 0)
    {
        result = 1; //if valid
    }
    else
    {
        result = 0; //if not valid
    }
    return result;
}

int check_card_length(long card_number)
{
    int i = 0;
    while (card_number > 0)
    {
        card_number /= 10;
        i++;
        //printf("%i\n", i);
    }
    //printf("i is %i", i);
    return i;
}

int check_starting_digits(long card_number)
{
    int starting_digit, card_length;
    card_length = check_card_length(card_number);
    while(card_number >= 10)
        card_number/= 10;
    return card_number;
}

int check_second_digit(long card_number)
{
    int starting_digit, card_length;
    card_length = check_card_length(card_number);
    while(card_number >= 100)
        card_number/= 10;
    return card_number;
}