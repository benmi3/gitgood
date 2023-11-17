import java.util.Scanner;                // Import the Scanner class
import java.util.InputMismatchException; // Import the Scanner Error
import java.util.Random;                 // Import the Random class

public class Main {
  public static void main(String[] args) {
      // Start decleration
      // Imported Classes
      Random rand = new Random();
      Scanner scan = new Scanner(System.in);
      // Create variables
      boolean correct_guess = false;
      int secret = rand.nextInt(100);
      // Greet the user
      System.out.println("Guess the number!");
      // Start loop
      while ( correct_guess == false) {
	  System.out.println("Please input your guess!");
	  // Use try incase of invalid number input
	  try {
	      // Get int input from user
	      int guess = scan.nextInt();
	      // If the answer is correct
	      // break loop
	      if (check_guess(guess, secret)) {
		  break;
	      }
	  }
	  catch (InputMismatchException e) {
	      // If invalid input is made
	      // Give warning
	      // then move on to next input
	      System.out.println("Please input a readable number");
	      scan.next();
	      continue;
	  }
      }
      // The loop has broken
      // which means the correct answer was given
      System.out.println("You win!"); 
  }

  public static boolean check_guess(int guess, int secret) {
      if (guess == secret) {
	  return true;
      } else if (guess > secret) {
	  System.out.println("Too big!");
	  return false;
      } else {
	  System.out.println("Too small!");
	  return false;
      }
  }
}
