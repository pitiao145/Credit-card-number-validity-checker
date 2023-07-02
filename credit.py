import cs50
# Check if a credit card number is valid. If it is valid, return if it is VISA, Mastercard or American Express. 

def main():
    #   Ask user to input credit card number (repeat until number is valid ).
    c = -1
    while c <= 0:
        c = cs50.get_int("Number: ")
    #   Perform Luhn’s Algorithm to do an initial check of the credit card number validity. If not, return invalid.
    s1 = calc_sum_even(c)
    s2 = calc_sum_odd(c)

    #   print(f"s1 = {s1}")
    #   print(f"s2 = {s2}")
    #   Check if the total modulo 10 is congruent to 0.``
    if ((s1 + s2) % 10 == 0):
        #   If first digit is 4 AND there are 13 OR 16 digits --> VISA
        #   If first two digits are 34 OR 37 AND there are 15 digits --> AMEX
        #   If first two digits are 51 OR 52 OR 53 OR 54 OR 55 AND there are 16 digits -->MC
        #   Check if the 16th number is not zero. If this is true then there are 16 digits and we need to check if it is VISA or MASTERCARD.

        if (get_x_digit(c, 16) != 0):
            #   Check if VISA
            if (get_x_digit(c, 16) == 4):
                print("VISA")
            #   Check if MASTERCARD
            elif ((get_x_digit(c, 16) == 5) and (get_x_digit(c, 15) == 1 or get_x_digit(c, 15) == 2 or get_x_digit(c, 15) == 3 or get_x_digit(c, 15) == 4 or get_x_digit(c, 15) == 5)):
                print("MASTERCARD")
            #   Otherwise invalid.
            else:
                print("INVALID")

        #   Check if the 15th number is not zero. If this is true then there are 15 digits and we need to check if it is AMEX.
        elif (get_x_digit(c, 15) != 0):
            if ((get_x_digit(c, 15) == 3) and (get_x_digit(c, 14) == 4 or get_x_digit(c, 14) == 7)):
                print("AMEX")
            else:
                print("INVALID")
        #   Check if the 13th number is not zero. If this is true then there are 13 digits and we need to check if it is VISA.
        elif (get_x_digit(c, 13) != 0):
            if (get_x_digit(c, 13) == 4):
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")

#   Get digit at position x (counting from right to left):


def get_x_digit(cardnumber, x):
    d = 0
    for i in range(0, x):
        d = cardnumber % 10
        cardnumber /= 10
    #   print(f"digit: {int(d)}")
    return int(d)

#   Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.


def calc_sum_even(cardnumber):
    se = 0
    for i in range(2, 17, 2):
        a = 2 * get_x_digit(cardnumber, i)
        if (a == 10 or a == 12 or a == 14 or a == 16 or a == 18):
            s_sum = 0
            for j in range(1, 3):
                b = get_x_digit(a, j)
                s_sum += b
            se += s_sum
        else:
            se += a
    #   print(f"se= {se}")
    return se

#   Sum of the digits that weren’t multiplied by 2.


def calc_sum_odd(cardnumber):
    so = 0
    for i in range(1, 17, 2):
        a = get_x_digit(cardnumber, i)
        so += a
    #   print(f"so = {so}")
    return so


if __name__ == "__main__":
    main()
