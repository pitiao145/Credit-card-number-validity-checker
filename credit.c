#include <cs50.h>
#include <stdio.h>

int get_x_digit(long cardnumber, int x);
int calc_sum_even(long cardnumber);
int calc_sum_odd(long cardnumber);

int main(void)
{
// Ask user to input credit card number (repeat until number is valid ).
    long c;
    do
    {
        c = get_long("Number: ");
    }
    while (c < 0);
//Perform Luhn’s Algorithm to do an initial check of the credit card number validity. If not, return invalid.
    int s1 = calc_sum_even(c);
    int s2 = calc_sum_odd(c);

    //Check if the total modulo 10 is congruent to 0.
    if ((s1 + s2) % 10 == 0)
    {
        // If first digit is 4 AND there are 13 OR 16 digits --> VISA
        // If first two digits are 34 OR 37 AND there are 15 digits --> AMEX
        // If first two digits are 51 OR 52 OR 53 OR 54 OR 55 AND there are 16 digits -->MC

        //Check if the 16th number is not zero. If this is true then there are 16 digits and we need to check if it is VISA or MASTERCARD.

        if (get_x_digit(c, 16) != 0)
        {
            //Check if VISA
            if (get_x_digit(c, 16) == 4)
            {
                printf("VISA\n");
            }

            //Check if MASTERCARD
            else if ((get_x_digit(c, 16) == 5) && (get_x_digit(c, 15) == 1 || get_x_digit(c, 15) == 2 || get_x_digit(c, 15) == 3
                                                   || get_x_digit(c, 15) == 4 || get_x_digit(c, 15) == 5))
            {
                printf("MASTERCARD\n");
            }
            //Otherwise invalid.
            else
            {
                printf("INVALID\n");
            }
        }
        //Check Check if the 15th number is not zero. If this is true then there are 15 digits and we need to check if it is AMEX.
        else if (get_x_digit(c, 15) != 0)
        {
            if ((get_x_digit(c, 15) == 3) && (get_x_digit(c, 14) == 4 || get_x_digit(c, 14) == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //Check if the 13th number is not zero. If this is true then there are 13 digits and we need to check if it is VISA.
        else if (get_x_digit(c, 13) != 0)
        {
            if (get_x_digit(c, 13) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Get specific digit (counting from right to left):
int get_x_digit(long cardnumber, int x)
{
    long d;
    for (int i = 0; i < x; i++)
    {
        d = cardnumber % 10;
        cardnumber /= 10;
    }

    return (int) d;
}


//Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
int calc_sum_even(long cardnumber)
{
    int se = 0;
    for (int j = 2; j <= 16; j += 2)
    {
        int a = 2 * get_x_digit(cardnumber, j);
        //printf("%i ", a);
        if (a == 10 || a == 12 || a == 14 || a == 16 || a == 18)
        {
            int s_sum = 0;
            for (int k = 1; k <= 2; k++)
            {
                int b = get_x_digit(a, k);
                s_sum += b;
            }
            se += s_sum;
        }
        else
        {
            se += a;
        }
    }
    //printf("%i", se);
    //printf("\n");
    return se;
}

//Sum of the digits that weren’t multiplied by 2.
int calc_sum_odd(long cardnumber)
{
    int so = 0;
    for (int j = 1; j <= 16; j += 2)
    {
        int a = get_x_digit(cardnumber, j);
        //printf("%i ", a);
        so += a;
    }
    //printf("%i", so);
    //printf("\n");
    return so;
}
