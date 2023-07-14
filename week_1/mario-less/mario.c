#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // For each row
    for (int i = 0; i < n; i++)
    {
        // For each column
        for (int j = 0; j < n; j++)
        {
            //If you have a value which i+j < n-1, it will print a dot, otherwise if i+j => n-1, it will print a hash
            if (i + j < n - 1)
            {
                printf(" ");
            }

            else
            {
                printf("#");
            }
        }

        // Move to next row
        printf("\n");
    }
}