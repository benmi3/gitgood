#include <stdbool.h> // You need this for bool
#include <stdio.h>
#include <string.h> // Need this for strlen, strcat

int main(int argc, char *argv[]) {

  // A thing about Constant variables, is that it is considered good
  // practice to declare them with uppercase.
  const int MINUTESPERHOUR = 60;
  const float PI = 3.14;

  // Create variables
  bool myBool = true;            // From stdbool.h
  int myNum = 5;                 // Integer (whole number)
  float myFloatNum = 5.9956;     // Floating point number
  double myDoubleNum = 19.99;    // Double floating point number
  char myLetter = 'D';           // Character
  char myString[] = "My String"; // String / Array of Characters
  char myOtherString[] = " and other string";
  strcat(myString, myOtherString);
  int myStringLen = strlen(myString);

  // Print variables
  printf("%d", myBool);  // Bool, as its 0 or 1, you use the same as for int
  printf("%d\n", myNum); // Int
  printf("%i\n", myNum); // Int
  printf("%f\n", myFloatNum);   // Float
  printf("%F\n", myFloatNum);   // Float
  printf("%lf\n", myDoubleNum); // Double
  printf("%c\n", myLetter);     // Char
  printf("%s\n", myString);     // Chars/string
  printf("%d", myStringLen);    // int, len of the string

  printf("%f\n",
         myFloatNum); // Default will show 6 digits after the decimal point
  printf("%.1f\n", myFloatNum); // Only show 1 digit
  printf("%.2f\n", myFloatNum); // Only show 2 digits
  printf("%.4f", myFloatNum);   // Only show 4 digits

  // Create variables of different data types
  int items = 50;
  float cost_per_item = 9.99;
  float total_cost = items * cost_per_item;
  char currency = '$';

  // Print variables
  printf("Number of items: %d\n", items);
  printf("Cost per item: %.2f %c\n", cost_per_item, currency);
  printf("Total cost = %.2f %c\n", total_cost, currency);

  // Set the maximum possible score in the game to 500
  int maxScore = 500;

  // The actual score of the user
  int userScore = 420;

  /* Calculate the percantage of the user's score in relation to the maximum
  available score. Convert userScore to float to make sure that the division is
  accurate */
  float percentage = (float)userScore / maxScore * 100.0;

  // Print the percentage
  printf("User's percentage is %.2f\n", percentage);

  int myAge = 25;
  const int VOTINGAGE = 18;   // This is a const, so make it capital
  const int DRINKINGAGE = 20; // This too

  if (myAge >= VOTINGAGE) {
    printf("Old enough to vote!\n");
    if (myAge >= DRINKINGAGE) {
      printf("You can also drink!\n");
    }
  } else {
    printf("Not old enough to vote.\n");
  };

  int time = 20;
  // This is an example of Short Hand if...Else
  // Not recomended for readbility, but can be used if nesessery
  (time < 18) ? printf("Good day.") : printf("Good evening.");

  int day = 4;

  switch (day) {
  case 1:
    printf("Monday\n");
    break;
  case 2:
    printf("Tuesday\n");
    break;
  case 3:
    printf("Wednesday\n");
    break;
  case 4:
    printf("Thursday\n");
    break;
  case 5:
    printf("Friday\n");
    break;
  case 6:
    printf("Saturday\n");
    break;
  case 7:
    printf("Sunday\n");
    break;
  }

  int i = 0;

  while (i < 5) {
    printf("%d\n", i);
    i++;
  }
  i = 0;

  do {
    printf("%d\n", i);
    i++;
  } while (i < 1);

  int outer, inner;

  // Outer loop
  for (outer = 1; outer <= 2; ++outer) {
    printf("Outer: %d\n", outer); // Executes 2 times

    // Inner loop
    for (inner = 1; inner <= 3; ++inner) {
      printf(" Inner: %d\n", inner); // Executes 6 times (2 * 3)
      printf("%d x %d = %d\n", outer, inner, outer * inner);
    }
  }

  int myNumbers[] = {25, 50, 75, 100};
  int number_iterator;

  for (number_iterator = 0; number_iterator < 4; number_iterator++) {
    printf("%d\n", myNumbers[number_iterator]);
  }

  int matrix[2][3] = {{1, 4, 2}, {3, 6, 8}};

  int ii, jj;
  for (ii = 0; ii < 2; ii++) {
    for (jj = 0; jj < 3; jj++) {
      printf("%d\n", matrix[ii][jj]);
    };
  };

  char str1[] = "Hello";
  char str2[] = "Hello";
  char str3[] = "Hi";

  // Compare str1 and str2, and print the result
  printf("%d\n", strcmp(str1, str2)); // Returns 0 (the strings are equal)

  // Compare str1 and str3, and print the result
  printf("%d\n", strcmp(str1, str3)); // Returns -4 (the strings are not equal)

  // --------------------------------------------- scanf example
  // Create an int and a char variable
  int inputNum;
  char inputChar;

  // Ask the user to type a number AND a character
  printf("Type a number AND a character and press enter: \n");

  // Get and save the number AND character the user types
  scanf("%d %c", &inputNum, &inputChar);

  // Print the number
  printf("Your number is: %d\n", inputNum);

  // Print the character
  printf("Your character is: %c\n", inputChar);

  char fullName[30];

  // --------------------------------------------- Fget example

  printf("Type your full name: \n");
  fgets(fullName, sizeof(fullName), stdin);

  printf("Hello %s", fullName);

  // Type your full name: John Doe
  // Hello John Doe

  // --------------------------------------------- Pointer example
  int *ptr = &inputNum;
  // int* myNum; // there are 2 ways of declaring pointers
  // int *myNum; // Note the placement of the start*
  printf("%p\n", ptr);
  printf("%d\n", *ptr);

  return 0;
}
