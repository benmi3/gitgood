#include <stdio.h>

int main(int argc, char *argv[]) {
  // Create variables
  int myNum = 5;                 // Integer (whole number)
  float myFloatNum = 5.9956;     // Floating point number
  double myDoubleNum = 19.99;    // Double floating point number
  char myLetter = 'D';           // Character
  char myString[] = "My String"; // String / Array of Characters

  // Print variables
  printf("%d\n", myNum);        // Int
  printf("%i\n", myNum);        // Int
  printf("%f\n", myFloatNum);   // Float
  printf("%F\n", myFloatNum);   // Float
  printf("%lf\n", myDoubleNum); // Double
  printf("%c\n", myLetter);     // Char
  printf("%s\n", myString);     // Chars/string

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

  return 0;
}
