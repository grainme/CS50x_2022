#include "helpers.h"
#include <math.h>

// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0 ; row < height ; row++)
    {
        for (int col = 0 ; col < width ; col++)
        {
            int sum = image[col][row].rgbtBlue + image[col][row].rgbtGreen + image[col][row].rgbtRed;
            int average = round(sum / 3.0);
            image[col][row].rgbtBlue = image[col][row].rgbtGreen = image[col][row].rgbtRed = average ;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0 ; row < height ; row++)
    {
        for (int col = 0 ; col < width ; col++)
        {
            float sepiaRed = .393 * image[col][row].rgbtRed + .769 * image[col][row].rgbtGreen + .189 * image[col][row].rgbtBlue;
            float sepiaGreen = .349 * image[col][row].rgbtRed + .686 * image[col][row].rgbtGreen + .168 * image[col][row].rgbtBlue;
            float sepiaBlue = .272 * image[col][row].rgbtRed + .534 * image[col][row].rgbtGreen + .131 * image[col][row].rgbtBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[col][row].rgbtRed = round(sepiaRed);
            image[col][row].rgbtGreen = round(sepiaGreen);
            image[col][row].rgbtBlue = round(sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0 ; row < height ; row++)
    {
        for (int col = 0 ; col < width / 2 ; col++)
        {
            // Reversing the pixels from right to left
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - col - 1];
            image[row][width - col - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy of image
    RGBTRIPLE temp[height][width];

    // Iterating through the whole image
    for (int j = 0 ; j < height ; j++)
    {
        for (int i = 0 ; i < width ; i++)
        {
            int temp_Red = 0;
            int temp_Green = 0;
            int temp_Blue = 0;
            int count = 0;

            for (int y = j - 1 ; y < j + 2 ; y++)
            {
                for (int x = i - 1 ; x < i + 2 ; x++)
                {
                    // Check the pixels around the current pixel
                    if (y > -1 && y < height && x > -1 && x < width)
                    {
                        temp_Red += image[y][x].rgbtRed;
                        temp_Blue += image[y][x].rgbtBlue;
                        temp_Green += image[y][x].rgbtGreen;
                        // Tracking the amount of pixels around the curr pix
                        count += 1;
                    }
                }
            }

            // Updating data of the copy object
            temp[j][i].rgbtRed = round(temp_Red / (float)count);
            temp[j][i].rgbtGreen = round(temp_Green / (float)count);
            temp[j][i].rgbtBlue = round(temp_Blue / (float)count);
        }
    }
    // Updating the original image
    for (int i = 0 ; i < height ; i++)
    {
        for (int k = 0 ; k < width ; k++)
        {
            image[i][k] = temp[i][k];
        }
    }
}
