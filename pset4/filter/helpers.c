#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average of 3 colors and save in a new variale 
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.00);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // If sepia exceeds 255 then need to be changed
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
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n = round(width / 2);
    
    //Loops through all pixels from left middle side
    for (int i = 0; i < height; i++)
    {
        int w = width - 1;
        for (int j = 0; j < n; j++)
        {
            //Change each pixel value to its reflected value by using a temporay variable
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][w];
            image[i][w] = temp;
            w--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalBlue = 0, totalGreen = 0;
            int totPixels = 0;
            
            for (int h = -1; h <= 1; h++)
            {
                for (int w = -1; w <= 1; w++)
                {
                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }
                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }
                    
                    totalRed += image[i+h][j+w].rgbtRed;
                    totalBlue += image[i+h][j+w].rgbtBlue;
                    totalGreen += image[i+h][j+w].rgbtGreen;
                    totPixels++;
                }
            }
            
            newImage[i][j].rgbtRed = round(totalRed / (totPixels * 1.0));
            newImage[i][j].rgbtBlue = round(totalBlue / (totPixels * 1.0));
            newImage[i][j].rgbtGreen = round(totalGreen / (totPixels * 1.0));
        }
    }
    
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][j];
        }
    }
    return;
}
