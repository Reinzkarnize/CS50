#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop for each pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Count for average color per one pixel RGB
            float n = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            int avr = round(n / 3);

            // Apply avegare RGB to pixel
            image[i][j].rgbtRed = avr;
            image[i][j].rgbtGreen = avr;
            image[i][j].rgbtBlue = avr;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop for each pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Apply sepia algorithm
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // round number to nearest integer
            int sRed = round(sepiaRed);
            int sGreen = round(sepiaGreen);
            int sBlue = round(sepiaBlue);

            // Make sure value is not above max value of hexadecimal
            if (sRed > 255)
            {
                sRed = 255;
            }
            if (sGreen > 255)
            {
                sGreen = 255;
            }
            if (sBlue > 255)
            {
                sBlue = 255;
            }

            // Apply value to a pixel
            image[i][j].rgbtRed = sRed;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtBlue = sBlue;
        }
    }



    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rowPixel[width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rowPixel[j] = image[i][j];
        }

        int mirror = width - 1;
        for (int k = 0; k < width; k++)
        {
            image[i][k] = rowPixel[mirror];
            mirror--;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make copy the oroginal image for the reference of unblurred image
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    // Marker of counter for each 3x3 box average
    float totalRed;
    float totalGreen;
    float totalBlue;

    int totalBox;

    // Loop for each pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Reset marker value to 0
            totalRed = 0;
            totalGreen = 0;
            totalBlue = 0;
            totalBox = 0;

            // count 3x3 box average
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    int boxH = i + a;
                    int boxW = j + b;

                    if (boxH >= 0 && boxH < height && boxW >= 0 && boxW < width)
                    {
                        totalRed += original[boxH][boxW].rgbtRed;
                        totalGreen += original[boxH][boxW].rgbtGreen;
                        totalBlue += original[boxH][boxW].rgbtBlue;

                        totalBox++;
                    }
                }

            }

            // Total value each color divided by total box included
            totalRed = totalRed / totalBox;
            totalGreen = totalGreen / totalBox;
            totalBlue = totalBlue / totalBox;

            // Round to nearest integer
            int bRed = round(totalRed);
            int bGreen = round(totalGreen);
            int bBlue = round(totalBlue);

            // Assign average blur value to image
            image[i][j].rgbtRed = bRed;
            image[i][j].rgbtGreen = bGreen;
            image[i][j].rgbtBlue = bBlue;
        }
    }
    return;
}
