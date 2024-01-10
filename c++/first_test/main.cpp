#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int if_else_test (int int1, int int2){
	if (int1 > int2) {
        return 0;
	} else if (int1 < int2) {
		return 1;
	} else {
		return 5;
	}
}

void small_function (int int1) {
	if (int1 < 18) {
		cout << "Good day.";
	} else {
		cout << "Good evening.";
	}
}

void switch_function (int day) {
    switch (day) {
        case 1:
            cout << "Monday";
	        break;
	    case 2:
	        cout << "Tuesday";
	        break;
	    case 3:
            cout << "Wednesday";
            break;
	    case 4:
            cout << "Thursday";
            break;
	    case 5:
            cout << "Friday";
            break;
	    case 6:
            cout << "Saturday";
            break;
	    case 7:
            cout << "Sunday";
            break;
	}
}

void while_function (int i) {
	int first_value = i;
	while (i < 5) {
		cout << i << "\n";
		i++;
	};
	// do/while will always be executed atleast once
	i = first_value;
	do {
		cout << i << "\n";
		i++;
	}
	while (i < 5);
}

void loop_function () {
	// Outer loop
	for (int i = 1; i <= 2; ++i) {
		cout << "Outer: " << i << "\n"; // Executes 2 times

		// Inner loop
		for (int j = 1; j <= 3; ++j) {
			cout << " Inner: " << j << "\n"; // Executes 6 times (2 * 3)
		}
	}
}

void battleships() {
	// We put "1" to indicate there is a ship.
	bool ships[4][4] = {
		  { 0, 1, 1, 0 },
		  { 0, 0, 0, 0 },
		  { 0, 0, 1, 0 },
		  { 0, 0, 1, 0 }
	};

	// Keep track of how many hits the player has and how many turns they have played in these variables
	int hits = 0;
	int numberOfTurns = 0;

	// Allow the player to keep going until they have hit all four ships
	while (hits < 4) {
		  int row, column;

		  cout << "Selecting coordinates\n";

		  // Ask the player for a row
		  cout << "Choose a row number between 0 and 3: ";
		  cin >> row;

		  // Ask the player for a column
		  cout << "Choose a column number between 0 and 3: ";
		  cin >> column;

		  // Check if a ship exists in those coordinates
		  if (ships[row][column]) {
			    // If the player hit a ship, remove it by setting the value to zero.
			    ships[row][column] = 0;

			    // Increase the hit counter
			    hits++;

			    // Tell the player that they have hit a ship and how many ships are left
			    cout << "Hit! " << (4-hits) << " left.\n\n";
		  } else {
			    // Tell the player that they missed
			    cout << "Miss\n\n";
		  }

		  // Count how many turns the player has taken
		  numberOfTurns++;
	}

	cout << "Victory!\n";
	cout << "You won in " << numberOfTurns << " turns";
}

struct car {
  string brand;
  string model;
  int year;
};

void struct_things(){
	// Create a car structure and store it in myCar1;
	car myCar1;
	myCar1.brand = "BMW";
	myCar1.model = "X5";
	myCar1.year = 1999;

	// Create another car structure and store it in myCar2;
	car myCar2;
	myCar2.brand = "Ford";
	myCar2.model = "Mustang";
	myCar2.year = 1969;
	 
	//Print the structure members
	cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
	cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
}

void myArrayTakingFunction(int myNumbers[5]) {
	for (int i = 0; i < 5; i++) {
		cout << myNumbers[i] << "\n";
	}
};

int plusFunc(int x, int y) {
	return x + y;
};

double plusFunc(double x, double y) {
	return x + y;
};

class MyClass {       // The class
	public:             // Access specifier
		int myNum;        // Attribute (int variable)
		string myString;  // Attribute (string variable)
};

class Vehicle {
  public:
    string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

class Car: public Vehicle {        // The class
	public:          // Access specifier
		string brand;  // Attribute
		string model;  // Attribute
		int year;      // Attribute
		int speed(int maxSpeed);
		Car(string x, string y, int z); // Constructor declaration
};

// Constructor definition outside the class
Car::Car(string x, string y, int z) {
	brand = x;
	model = y;
	year = z;
};

int Car::speed(int maxSpeed) {
  return maxSpeed;
}

int main (int argc, char *argv[]) {
	// You compile the program with g++ main.cpp
	// Then run it with ./a.out/
	// -----------------------------------------
	// If you dont have the using namespace 
	// you would have to add the std:: to cout.
	cout << "Hello world!\n";
	cout << "Why am I doing this in c++?\n\n";
	int myInt = 12;
	cout << "The int is declared on line:" << myInt;
	int thatInt = 14;
	cout << "\n";
	int thisInt = myInt + thatInt;
	cout << thisInt;
	cout << "\n";
	//int x, y;
	//int sum;
	//cout << "Type a number: ";
	//cin >> x;
	//cout << "\nType another number: ";
	//cin >> y;
	//sum = x + y;
	//cout << "\nSum is: " << sum << "\n";
	// Next is char declaied with ASCII values
	char a = 65, b = 66, c = 67;
	cout << a;
	cout << b;
	cout << c;
	// You can ofcourae declare it
	// with single quotes
	char d = 'D';
	cout << d;
	string example_string = "\nString type needs to be imported!\n";
	cout << example_string;
	int x1 = 10;
	cout << x1;
	--x1;
	cout << x1;
	++x1;
	cout << x1;
	bool check_1 = x1 < 5 &&  x1 < 10;
	bool check_2 = x1 < 5 || x1 < 4;
	bool check_3 = !(x1 < 5 && x1 < 10);
	cout << "\nLocal and\nx < 5 &&  x < 10\nResult:" << check_1;
	cout << "\nLocal or\nx < 5 || x < 4\nResult:" << check_2;
	cout << "\nLogical not\n!(x < 5 && x < 10)\nResult:" << check_3;
	string firstName = "\nJohn ";
	string lastName = "Doe\n";
	string fullName = firstName.append(lastName);
	cout << fullName;
	string txt1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "\nThe length of the txt string is: " << txt1.length();
	string txt2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "\nThe length of the txt string is: " << txt2.size();
	cout << "\n";
	string myString = "Hello\n";
	cout << myString;
	myString[0] = 'J';
	cout << "\n";
	cout << myString;
	// Outputs Jello instead of Hello
	cout << "\n";
	cout << sqrt(64);
	cout << "\n";
	cout << round(2.6);
	cout << "\n";
	cout << log(2);
	cout << "\n";
	int test_answer = if_else_test(5,5); 
	cout << "\nTest answer:" << test_answer << "\n";
	int myAge = 25;
	int votingAge = 18;
	cout << "\n---\n";
	cout << (myAge >= votingAge); // returns 1 (true), meaning 25 year olds are allowed to vote! 
	cout << "\n---\n";
	small_function(myAge);
	cout << "\n";
	// Short but harder to read if else 
	int time = 9;
	string result = (time < 18) ? "Good day." : "Good evening.";
	cout << result;
	cout << "\n";
	while_function(0);
	loop_function();
	cout << "\n";
	// This is how to make an array
	// You dont have to specify the size of the array,
	// but you should as it will reduce errors
	string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
	cars[0] = "Opel";
	cout << cars[0];
	int getArrayLength = sizeof(cars);
	// Get length of array in bytes
	cout << "\n";
	cout << getArrayLength;
	cout << "\n";
	string letters[2][4] = {
		{ "A", "B", "C", "D" },
		{ "E", "F", "G", "H" }
	};
	letters[0][0] = "Z";
	for (int i = 0; i < 2; i++) {
		  for (int j = 0; j < 2; j++) {
			    for (int k = 0; k < 2; k++) {
			      cout << letters[i][j][k] << "\n inner inner\n";
			    }
		  }
	}
	cout << "\n";
	// Referances
	string food = "Pizza";
	string &meal = food;
	string* ptr = &food;    // Pointer declaration

	cout << food << "\n";  // Outputs Pizza
	cout << meal << "\n";  // Outputs Pizza
	
	// Reference: Output the memory address of food with the pointer (0x6dfed4)
	cout << ptr << "\n";

	// Dereference: Output the value of food with the pointer (Pizza)
	cout << *ptr << "\n";

	// Output the value of food (Pizza)
	cout << food << "\n";

	// Output the memory address of food (0x6dfed4)
	cout << &food << "\n";

	// Access the memory address of food and output its value (Pizza)
	cout << *ptr << "\n";

	// Change the value of the pointer
	*ptr = "Hamburger";

	// Output the new value of the pointer (Hamburger)
	cout << *ptr << "\n";

	// Output the new value of the food variable (Hamburger)
	cout << food << "\n";
	int myNumbers[5] = {10, 20, 30, 40, 50}; 
	myArrayTakingFunction(myNumbers);
	cout << "\n";
	// Function Overloading example
	// Function has same name,
	// but takes different types,
	// and returns different types
	// Check out how the functions are made above
	int myNum1 = plusFunc(8, 5);
	double myNum2 = plusFunc(4.3, 6.26);
	cout << "Int: " << myNum1 << "\n";
	cout << "Double: " << myNum2;
	cout << "\n";
	// Class usecase
	MyClass myObj;  // Create an object of MyClass

	// Access attributes and set values
	myObj.myNum = 15; 
	myObj.myString = "Some text";

	// Print attribute values
	cout << myObj.myNum << "\n";
	cout << myObj.myString; 
	cout << "\n";
	

	// using class spesific functiona
	Car myCar("BMW", "M3", 2024); // Create an object of Car
	cout << myCar.speed(345); // Call the method with an argument
	cout << myCar.brand << " " << myCar.model << " " << myCar.year << "\n";
	myCar.honk();
	cout << "\n";
	// ------------------------------------- END
	// Return useless 0
	cout << "\n";
	//battleships();
	return 0;
}

