#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    int i = 0;
    int j;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = 133;
                image[i][j].rgbtGreen = 108;
                image[i][j].rgbtRed =  252;
            }
            j++;
        }
        i++;
    }
}
