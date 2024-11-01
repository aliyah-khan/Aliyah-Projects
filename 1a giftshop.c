/* Aliyah Khan
  Program 1a
  1/27/21
  COP 3223*/

#include <stdio.h>

int main(void) {

  //variables
  #define TAX_RATE 0.065
  float price;
  float itemQuantity;
  int tax;
  float totalCost;


  //user input for the cost and quantity of the item
  printf("What is the cost of the item to be purchased (in dollars)?\n");
  scanf("%f", &price);

  printf("How many of the item are you purchasing?\n");
  scanf("%f", &itemQuantity);

  //figuring out whether the item is taxed or not
  printf("Is the item a taxed item (1=yes, 0= no)?\n");
  scanf("%d", &tax);

  //calculating the cost for the total purchase
  totalCost = (price*itemQuantity)+((price*itemQuantity)*tax*TAX_RATE);

  //printing out the cost of the total purchase
  printf("Your total purchase will cost $%.2f\n", totalCost);
  return 0;
}
