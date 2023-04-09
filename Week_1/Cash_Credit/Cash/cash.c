#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int i;
    do
    {
        i = get_int("Change owed: ");
    }
    while (i < 0);
    return i;
}

//calculating quarters
int calculate_quarters(int cents)
{
    int result;
    if (cents >= 25)
    {
        result = cents / 25;
    }
    else
    {
        result = 0;
    }
    return result;
}

//calculating dimes
int calculate_dimes(int cents)
{
    int result;
    if (cents >= 10)
    {
        result = cents / 10;
    }
    else
    {
        result = 0;
    }
    return result;
}

//calculating nickels
int calculate_nickels(int cents)
{
    int result;
    if (cents >= 5)
    {
        result = cents / 5;
    }
    else
    {
        result = 0;
    }
    return result;
}

//calculating pennies
int calculate_pennies(int cents)
{
    int result;
    if (cents >= 1)
    {
        result = cents / 1;
    }
    else
    {
        result = 0;
    }
    return result;
}
