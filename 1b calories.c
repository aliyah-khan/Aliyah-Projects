/* Aliyah Khan
  Program 1b
  1/27/21
  COP 3223*/

#include <stdio.h>

int main(void) {

  //variables
  #define WALK_CAL 5
  #define STAND_CAL 2
  #define DRINK_CAL 20
  #define FOOD_CAL 40
  #define CALS_PER_POUND 3500
  float walk;
  float stand;
  float drink;
  float eat;
  float totalCal;
  float totalLbs;

  //getting user input for the user's activity
  printf("How many minutes were you walking?\n");
  scanf("%f", &walk);

  printf("How many minutes were you standing?\n");
  scanf("%f", &stand);

  printf("How many minutes were you drinking?\n");
  scanf("%f", &drink);

  printf("How many minutes were you eating?\n");
  scanf("%f", &eat);

  //multiplying to get the total number of calories for each day
  walk = walk*WALK_CAL;
  stand = stand*STAND_CAL;
  drink = drink*DRINK_CAL;
  eat = eat*FOOD_CAL;

  //equation for the total calories for the day
  totalCal = walk + stand - eat - drink;

  //converting calories into pounds
  totalLbs = totalCal/CALS_PER_POUND;

  //if statement to determine whether the user gained or lost weight
  if (totalLbs > 0){
    printf("You lost %.3f pounds today!",totalLbs);
  }
  else{
    printf("Weight lost is %.3f pounds.",totalLbs);
  }
  return 0;
}
