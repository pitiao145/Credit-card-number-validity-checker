# Credit-card-number-validity-checker
An app to check if a given credit card number is valid (supports Visa, Mastercard, American Express).

The user can give a credit card number as input, and the program if the credit card number is a valid one or not.

The program is based on the following assumptions/simplifications:
  -  All American Express numbers start with 34 or 37; 
  -  MasterCard numbers start with 51, 52, 53, 54, or 55
  -  Visa numbers start with 4.
  -  Checksum is performed with Luhn’s Algorithm
See https://developer.paypal.com/tools/sandbox/card-testing/ to try some credit card numbers.

This program has been implemented in both the C programming language as in Python.
