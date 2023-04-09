#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declaring variables
    int i = 0, j = 0, k = 0, t = 0;
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

// Printing pyramid
    while (i < height)
    {
        j = -1;
        t = -1;
        k = i;
        //right aligning a pyramid
        while (k < height - 1)
        {
            printf(" ");
            k++;
        }
        //printing hashes
        while (j < i)
        {
            printf("#");
            j++;
        }
        printf("  ");

        //added second block
        while (t < i)
        {
            printf("#");
            t++;
        }
        printf("\n");
        i++;
    }
}