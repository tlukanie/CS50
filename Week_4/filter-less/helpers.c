#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    int average;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {

            average = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
            j++;
        }
        i++;
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j;
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            sepiaRed = round(0.393 * (float)image[i][j].rgbtRed + 0.769 * (float)image[i][j].rgbtGreen + 0.189 * (float)image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * (float)image[i][j].rgbtRed + 0.686 * (float)image[i][j].rgbtGreen + 0.168 * (float)image[i][j].rgbtBlue);
            sepiaBlue = round(0.272 * (float)image[i][j].rgbtRed + 0.534 * (float)image[i][j].rgbtGreen + 0.131 * (float)image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            j++;
        }
        i++;
    }
    return;
}

static void free_2d_array(int height, int width, RGBTRIPLE *image_temp[])
{
    for (int l = 0; l < height; l++)
    {
        free(image_temp[l]);
    }
    free(image_temp);
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    int h, w, width_temp;
    RGBTRIPLE **image_temp = (RGBTRIPLE **)malloc(height * sizeof(RGBTRIPLE *));
    for (int p = 0; p < height; p++)
        image_temp[p] = (RGBTRIPLE *)malloc(width * sizeof(RGBTRIPLE));
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            image_temp[i][j] = image[i][j];
            j++;
        }
        i++;
    }

    for (h = 0; h < height; h++)
    {
        for (w = 0, width_temp = width; width_temp > 0; w++, width_temp--)
        {
            image[h][w] = image_temp[h][width_temp - 1];
        }
    }

    // free memory after using image_temp
    free_2d_array(height, width, image_temp);
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0, j;
    RGBTRIPLE image_copy[height][width];

    while (i < height)
    {
        j = 0;
        {
            while (j < width)
            {
                float red = 0, green = 0, blue = 0, average = 0;
                for (int y = -1; y < 2; y++)
                {
                    for (int x = -1; x < 2; x++)
                    {
                        if (i + y < 0 || i + y > height - 1 || j + x < 0 || j + x > width - 1)
                        {
                            continue;
                        }
                        blue += image[i + y][j + x].rgbtBlue;
                        green += image[i + y][j + x].rgbtGreen;
                        red += image[i + y][j + x].rgbtRed;
                        average++;
                    }
                }
                image_copy[i][j].rgbtBlue = round(blue / average);
                image_copy[i][j].rgbtGreen = round(green / average);
                image_copy[i][j].rgbtRed = round(red / average);
                j++;
            }
        }
        i++;
    }

    i = 0;
    j = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            image[i][j].rgbtBlue = image_copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image_copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = image_copy[i][j].rgbtRed;
            j++;
        }
        i++;
    }
    return;
}

