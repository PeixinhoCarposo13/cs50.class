/*
A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also
stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with
credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa
uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could
print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start
with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern
ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical
relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions),
if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake
number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

In a file called credit.c in a folder called credit, implement a program in C that checks the validity of a given credit card number.

So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm,
you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

4003600000000014

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.

In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf) whether
it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your
code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you
may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading
zeroes. But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. (Why?)

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).
$ ./credit
Number: 4003600000000014
VISA
*/

#include <stdio.h>

int main(void)
{
  // Credit card number to be validated
  long long cardNumber;

  printf("Number: ");
  scanf("%lld", &cardNumber);

  // Here for testing purposes, I will just print what brand the card is based by their size and starting digits
  //  American Express: 15 digits, starts with 34 or 37
  if ((cardNumber >= 340000000000000 && cardNumber <= 349999999999999) || (cardNumber >= 370000000000000 && cardNumber <= 379999999999999))
  {
    // Here now i wil start to implement the Luhn's algorithm to validate the card number
    int listAmex[15];
    int divTeste;
    long long div = 100000000000000;

    // Here I will create a list with the digits of the card number, so I can manipulate them later
    for (int i = 0; i < 15; i++)
    {
      divTeste = cardNumber / div;
      cardNumber = cardNumber - (divTeste * div);
      div /= 10;
      listAmex[i] = divTeste;
    }

    // Now I will implement the Luhn's algorithm
    int sum = 0;
    // Here i will go through the list of digits.
    for (int j = 0; j < 15; j++)
    {
      // Every other digit starting from the second to last digit will be multiplied by 2, and if the product is greater than 9, I will sum the digits of the product.
      if (j % 2 == 0)
      {
        int product = listAmex[j] * 2;
        if (product > 9)
        {
          sum += product / 10 + product % 10; // Here I will sum the digits of the product. Ex: if the product is 12, I will sum 1 + 2 = 3
        }
        else
        {
          sum += product;
        }
      }
      // The other digits will be added to the sum without any manipulation.
      else
      {
        sum += listAmex[j];
      }
    }

    if (sum % 10 == 0)
    {
      printf("AMEX\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }

  // MasterCard: 16 digits, starts with 51, 52, 53, 54, or 55
  else if (cardNumber >= 5100000000000000 && cardNumber <= 5599999999999999)
  {
    int listMaster[16];
    int divTeste;
    long long div = 1000000000000000;

    for (int i = 0; i < 16; i++)
    {
      divTeste = cardNumber / div;
      cardNumber = cardNumber - (divTeste * div);
      div /= 10;
      listMaster[i] = divTeste;
    }

    int sum = 0;
    for (int j = 0; j < 16; j++)
    {
      if (j % 2 == 0)
      {
        int product = listMaster[j] * 2;
        if (product > 9)
        {
          sum += product / 10 + product % 10;
        }
        else
        {
          sum += product;
        }
      }
      else
      {
        sum += listMaster[j];
      }
    }
    if (sum % 10 == 0)
    {
      printf("MASTERCARD\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  // Visa: 13 or 16 digits, starts with 4
  else if ((cardNumber >= 4000000000000 && cardNumber <= 4999999999999) || (cardNumber >= 4000000000000000 && cardNumber <= 4999999999999999))
  {
    // Here I will check if the card number is 13 digits or 16 digits, and then I will implement the Luhn's algorithm accordingly.
    if (cardNumber >= 4000000000000 && cardNumber <= 4999999999999)
    {
      int listVisa[13];
      int divTeste;
      long long div = 1000000000000;

      for (int i = 0; i < 13; i++)
      {
        divTeste = cardNumber / div;
        cardNumber = cardNumber - (divTeste * div);
        div /= 10;
        listVisa[i] = divTeste;
      }

      int sum = 0;
      for (int j = 0; j < 13; j++)
      {
        if (j % 2 == 0)
        {
          int product = listVisa[j] * 2;
          if (product > 9)
          {
            sum += product / 10 + product % 10;
          }
          else
          {
            sum += product;
          }
        }
        else
        {
          sum += listVisa[j];
        }
      }
      if (sum % 10 == 0)
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
      int listVisa[16];
      int divTeste;
      long long div = 1000000000000000;

      for (int i = 0; i < 16; i++)
      {
        divTeste = cardNumber / div;
        cardNumber = cardNumber - (divTeste * div);
        div /= 10;
        listVisa[i] = divTeste;
      }

      int sum = 0;
      for (int j = 0; j < 16; j++)
      {
        if (j % 2 == 0)
        {
          int product = listVisa[j] * 2;
          if (product > 9)
          {
            sum += product / 10 + product % 10;
          }
          else
          {
            sum += product;
          }
        }
        else
        {
          sum += listVisa[j];
        }
      }
      if (sum % 10 == 0)
      {
        printf("VISA\n");
      }
      else
      {
        printf("INVALID\n");
      }
    }
  }
  else
  {
    printf("INVALID\n");
  }

  return 0;
}