// Blur image


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    int totPixels;
    
    // Loops through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalBlue = 0, totalGreen = 0;
            
            //Check if pixel is on edges
            if (((0 <= j < width) && (i == 0 || i == height - 1)) || ((0 < i < height - 1) && (j == 0 || j == width - 1)))
            {
                if (i == 0)
                {
                    if (j == 0)     // pixel [0][0]
                    {
                        totPixels = 4;
                        for (int r = i; r <= i + 1; r++)
                        {
                            for (int c = j; c <= j + 1; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                    else if (j == width - 1)        //Pixel [0][width - 1]
                    {
                        totPixels = 4;
                        for (int r = i; r <= i + 1; r++)
                        {
                            for (int c = j - 1; c <= j; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                    else    //Pixel [0][...]
                    {
                        totPixels = 6;
                        for (int r = i; r <= i + 1; r++)
                        {
                            for (int c = j - 1; c <= j + 1; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                }
                else if (i == height - 1)
                {
                    if (j == 0)         //Pixel [height - 1][0]
                    {
                        totPixels = 4;
                        for (int r = i - 1; r <= i; r++)
                        {
                            for (int c = j; c <= j + 1; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                    else if (j == width - 1)        //Pixel [height - 1][width - 1]
                    {
                        totPixels = 4;
                        for (int r = i - 1; r <= i; r++)
                        {
                            for (int c = j - 1; c <= j; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                    else            //Pixel [height - 1][...]
                    {
                        totPixels = 6;
                        for (int r = i - 1; r <= i; r++)
                        {
                            for (int c = j - 1; c <= j + 1; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                }
                else
                {
                    totPixels = 6;
                    if (j == 0)             //Pixels [1 to height - 2] [0]
                    {
                        for (int r = i - 1; r <= i + 1; r++)
                        {
                            for (int c = j; c <= j + 1; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                    else if (j == width - 1)            //Pixels [1 to height - 2] [width - 1]
                    {
                        for (int r = i - 1; r <= i + 1; r++)
                        {
                            for (int c = j - 1; c <= j; c++)
                            {
                                totalRed += image[r][c].rgbtRed;
                                totalBlue += image[r][c].rgbtBlue;
                                totalGreen += image[r][c].rgbtGreen;
                            }
                        }
                    }
                }
            }
            else
            {
                //not edges
                totPixels = 9;
                for (int r = i - 1; r <= i + 1; r++)
                {
                    for (int c = j - 1; c <= j + 1; c++)
                    {
                        totalRed += image[r][c].rgbtRed;
                        totalBlue += image[r][c].rgbtBlue;
                        totalGreen += image[r][c].rgbtGreen;
                    }
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