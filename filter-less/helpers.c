#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float sum;
    float avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum = image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen;
            avg = round(sum / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float  originalRed, originalBlue, originalGreen;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (sepiaRed >= 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen >= 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue >= 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int center = 0;
    if (width % 2 == 0)
    {
        center = (width / 2);
    }
    else
    {
        center = (width / 2) + 1;
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            if (j < center)
            {
                temp.rgbtBlue = image[i][width - j - 1].rgbtBlue;
                image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;
                image[i][j].rgbtBlue = temp.rgbtBlue;

                temp.rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
                image[i][j].rgbtRed = temp.rgbtRed;

                temp.rgbtGreen = image[i][width - j - 1].rgbtGreen;
                image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
                image[i][j].rgbtGreen = temp.rgbtGreen;
            }
            else
            {
                break;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ogImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ogImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;

            if (i >= 0 && j >= 0) // start
            {
                red += ogImage[i][j].rgbtRed;
                green += ogImage[i][j].rgbtGreen;
                blue += ogImage[i][j].rgbtBlue;
                counter++;
            }
            if (i >= 0 && j - 1 >= 0) // left
            {
                red += ogImage[i][j - 1].rgbtRed;
                green += ogImage[i][j - 1].rgbtGreen;
                blue += ogImage[i][j - 1].rgbtBlue;
                counter++;
            }
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width)) //right
            {
                red += ogImage[i][j + 1].rgbtRed;
                green += ogImage[i][j + 1].rgbtGreen;
                blue += ogImage[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0) // top
            {
                red += ogImage[i - 1][j].rgbtRed;
                green += ogImage[i - 1][j].rgbtGreen;
                blue += ogImage[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j - 1 >= 0) // top left
            {
                red += ogImage[i - 1][j - 1].rgbtRed;
                green += ogImage[i - 1][j - 1].rgbtGreen;
                blue += ogImage[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width)) // top right
            {
                red += ogImage[i - 1][j + 1].rgbtRed;
                green += ogImage[i - 1][j + 1].rgbtGreen;
                blue += ogImage[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0)) // bot
            {
                red += ogImage[i + 1][j].rgbtRed;
                green += ogImage[i + 1][j].rgbtGreen;
                blue += ogImage[i + 1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0)) // bot left
            {
                red += ogImage[i + 1][j - 1].rgbtRed;
                green += ogImage[i + 1][j - 1].rgbtGreen;
                blue += ogImage[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width)) // bot right
            {
                red += ogImage[i + 1][j + 1].rgbtRed;
                green += ogImage[i + 1][j + 1].rgbtGreen;
                blue += ogImage[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
            //image[i][j].rgbtRed = round(red / (counter * 1.0));
            //image[i][j].rgbtGreen = round(green / (counter * 1.0));
            //image[i][j].rgbtBlue = round(blue / (counter * 1.0));
            //image[i][j].rgbtRed = round(red / (counter * 1.0));
            //image[i][j].rgbtGreen = round(green / (counter * 1.0));
            //image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }

    return;
}
