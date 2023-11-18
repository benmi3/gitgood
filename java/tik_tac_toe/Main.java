import java.util.Scanner;                // Import the Scanner class
import java.util.InputMismatchException; // Import the Scanner Error

public class Main {
  public static void main(String[] args) {
      // Start decleration
      // Imported Classes
      Scanner scan = new Scanner(System.in);
      // Create variables
      String[][] grid = createFreshGame();
      // Greet the user
      System.out.println("Tic Tac To!");
      // Start loop
      while ( true ) {
	  System.out.println("");
	  // Use try incase of invalid number input
	  try {
	      // Try things
	      System.out.println("Please input row:");
	      int row = scan.nextInt();
	      System.out.println("Please input column:");
	      int column = scan.nextInt();
	      break;
	      }
	  catch (InputMismatchException e) {
	      // If invalid input is made
	      // Give warning
	      // then move on to next input
	      System.out.println("Somethings happened! Please try again!");
	      scan.next();
	      continue;
	  }
      }
      // stop scanner
      scan.close();
      // The loop has broken
      // which means the correct answer was given
      System.out.println("Thank you for playing!");
  }

  public static String[][] createFreshGame() {
      String[][] new_game = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };
      return new_game;
  }

  public static boolean setMove(int row, int column) {
      System.out.println("TODO");
  }

  public static boolean checkWinner(int x_l, int y_l, boolean who) {
      System.out.println("yay");
      return true;
  }
}
