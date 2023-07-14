#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE curPx = image[i][j];
            int average = round((curPx.rgbtBlue + curPx.rgbtGreen + curPx.rgbtRed) / 3.0);
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
            RGBTRIPLE curPx = image[i][j];

            float sepiaRed = round(sepiaRed = .393 * curPx.rgbtRed + .769 * curPx.rgbtGreen + .189 * curPx.rgbtBlue);
            float sepiaGreen = round(sepiaGreen = .349 * curPx.rgbtRed + .686 * curPx.rgbtGreen + .168 * curPx.rgbtBlue);
            float sepiaBlue = round(sepiaBlue = .272 * curPx.rgbtRed + .534 * curPx.rgbtGreen + .131 * curPx.rgbtBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE placeholder[height][width];

    for (int i = 0; i < height; i++)
    {
        int curPx = 0;
        for (int j = width - 1; j >= 0; j--, curPx++)
        {
            placeholder[i][curPx] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = placeholder[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE placeholder[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int radius = 0;
            int rows[] = { i - 1, i, i + 1};
            int columns[] = {j - 1, j, j + 1};
            float tRed = 0, tGreen = 0, tBlue = 0;

            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int curRow = rows[k];
                    int curCol = columns[l];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];
                        tRed += pixel.rgbtRed;
                        tGreen += pixel.rgbtGreen;
                        tBlue += pixel.rgbtBlue;
                        radius++;
                    }
                }
            }
            placeholder[i][j].rgbtRed = round(tRed / radius);
            placeholder[i][j].rgbtGreen = round(tGreen / radius);
            placeholder[i][j].rgbtBlue = round(tBlue / radius);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = placeholder[i][j];
        }
    }
    return;
}
