#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit;
    long ccNum;
    int Sum = 0, position = 0, length = 0;
    do
    {
        // Get credit card number
        credit = get_long("Card Number: ");
        ccNum = credit;

        //Luhn's Algorithm
        while (credit != 0)
        {
            if (position % 2 != 0)
            {
                int temp = 2 * (credit % 10);
                if (temp > 9)
                {
                    Sum += (temp % 10 + temp / 10);
                }

                else
                {
                    Sum += temp;
                }
            }

            else
            {
                Sum += credit % 10;
            }
            credit = credit / 10;
            position++;
            length++;
        }
    }

    while (credit != 0);
    if (Sum % 10 == 0)
    {
        // Check if Amex
        long amex = ccNum / 10000000000000;
        if ((amex == 34 || amex == 37) && length == 15)
        {
            printf("AMEX\n");
            return 0;
        }

        // Check if Master
        long master = ccNum / 100000000000000;
        if ((length == 16) && (master >= 51 && master <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }

        // Check if Visa
        long visa = (ccNum / 1000000000000);
        if ((length == 16 || length == 13) && (visa == 4 || master / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }

        // Otherwise it's an invalid number
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }

}

/* test numbers:

378282246310005     AMEX
371449635398431     AMEX
378734493671000     AMEX Corporate
30569309025904      Diners Club
6011111111111117    Discover
6011000990139424    Discover
3530111333300000    JCB
3566002020360505    JCB
2221000000000009    Mastercard
2223016768739313    Mastercard
5555555555554444    Mastercard
5105105105105100    Mastercard
4111111111111111    Visa
4012888888881881    Visa
4222222222222       Visa

Extra numbers to check:
1234567890          should be INVALID
4111111111111113    should be INVALID
4222222222223       should be INVALID
*/