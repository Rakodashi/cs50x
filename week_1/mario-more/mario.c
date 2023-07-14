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
        // For each column, specifically with the two gaps in the middle
        for (int j = 0; j < n + i + 3; j++)
        {
            /*This makes the first stair shape,
            then adds the two spaces in the middle,
            and then the reversed stair, to finally form a pyramid*/
            if (j == n || i + j < n - 1 || j == n + 1)
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