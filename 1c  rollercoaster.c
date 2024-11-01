/*Aliyah Khan
 program 1c
 1/27/21
 COP 3223*/

  #include <stdio.h>

  int main (void){

  #define FIRST_CAR_LENGTH 10
  #define NORMAL_CAR_LENGTH 8
  #define CAR_CAPACITY 4

  int N;
  int trainLength;
  int trackLength;
  int numCars;
  int oneTrain;
  int trainTotal;
  int surplus;
  int people;

  //getting user input for N
printf("What is the value for N?\n");
scanf("%d", &N);

//repeating the prompt as many ties as the user has entered
for(int i=0; i < N; i++){
    //user input for track and train length
    printf("What is the total length of the track, in feet?\n");
    scanf("%d", &trackLength);

    printf("What is the maximum length of a train in feet?\n");
    scanf("%d", &trainLength);

    //subtracting 10 for the first car and dividing by 8 for the number of cars per train
    numCars = (trainLength - FIRST_CAR_LENGTH) / NORMAL_CAR_LENGTH;
    numCars++;

    //getting the length of one train
    oneTrain = ((numCars * NORMAL_CAR_LENGTH) + 2);

    //finding the total number of trains
    trainTotal = ((trackLength / 4) / trainLength);

    //finding the total number of people on the rollercoaster
    people = numCars * trainTotal * CAR_CAPACITY ;

    printf("Your ride can have at most %d people on it at one time. \n", people);

    //printing whether there's a surplus from the maximum train length or not
    if (trainLength > oneTrain){
            surplus = trainLength - oneTrain;
        printf("Maximum train length has surplus %d feet\n", surplus);
    }
    else{
        printf("Maximum length fits exactly");
    }

}
  return 0;
  }
