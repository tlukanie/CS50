#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, end_n, years;
    years = 0;
    do
    {
        printf("Start size: ");
        scanf("%d", &n);
    }
    while (n < 9);

    // TODO: Prompt for end size
    do
    {
        printf("End size: ");
        scanf("%d", &end_n);
    }
    while (end_n < n);

    // TODO: Calculate number of years until we reach threshold
    while (n < end_n)
    {
        n = n + n / 3 - n / 4;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", years);

    return (0);
}
