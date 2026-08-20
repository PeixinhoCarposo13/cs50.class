/*
Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents).
You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy.
When making change, odds are you want to minimize the number of coins you’re dispensing for each customer,
lest you run out (or annoy the customer!). In a file called cash.c in a folder called cash, implement a program
in C that prints the minimum coins needed to make the given amount of change, in cents, as in the below:

Change owed: 25
1
But prompt the user for an int greater than 0, so that the program works for any amount of change:

Change owed: 70
4
Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an int at all!).

*/

#include <stdio.h>

int main(void)
{
  double productPrice = 0.0;
  double amountPaid = 0.0;
  double changeOwed = 0.0;

  // First i need to ask the user for the amount of change owed

  // Check if the product price is greater than 0
  while (productPrice <= 0)
  {
    printf("Enter the product price: ");
    scanf("%lf", &productPrice);

    if (productPrice <= 0)
    {
      printf("Please enter a positive value for the product price.\n");
    }
  }

  // Check if the amount paid is greater than 0
  while (amountPaid <= 0)
  {
    printf("Enter the amount paid: ");
    scanf("%lf", &amountPaid);

    if (amountPaid <= 0)
    {
      printf("Please enter a positive value for the amount paid.\n");
    }
  }

  // Check if the amount paid is greater than or equal to the product price
  while (amountPaid < productPrice)
  {
    printf("The amount paid must be greater than or equal to the product price.\n");
    printf("Enter the amount paid: ");
    scanf("%lf", &amountPaid);
  }

  changeOwed = amountPaid - productPrice;

  printf("Change owed: %.2f\n", changeOwed);

  // Now i need to calculate the minimum number of coins needed to make the change owed
  // I will consider the following coins: quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent)
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;
  int totalCoins = 0;

  while (changeOwed >= 0.25)
  {
    changeOwed -= 0.25;
    quarters++;
  }

  while (changeOwed >= 0.10)
  {
    changeOwed -= 0.10;
    dimes++;
  }

  while (changeOwed >= 0.05)
  {
    changeOwed -= 0.05;
    nickels++;
  }

  while (changeOwed >= 0.01)
  {
    changeOwed -= 0.01;
    pennies++;
  }

  totalCoins = quarters + dimes + nickels + pennies;

  printf("Minimum coins needed: %d\n", totalCoins);

  return 0;
}