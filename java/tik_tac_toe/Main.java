import java.util.Scanner;                // Import the Scanner class
import java.util.InputMismatchException; // Import the Scanner Error

public class Main {
  // keep gamestate outside
  String[][] grid;
  boolean current_player; 
  public static void main(String[] args) {
      Main game_state = new Main();
      // Start decleration
      // Imported Classes
      Scanner scan = new Scanner(System.in);
      // Create variables
      game_state.grid = createFreshGame();
      String msg_input_row = "Please input row:";
      String msg_input_column = "Please input column:";
      // Clear terminal
      clearScreen();
      // Greet the user
      System.out.println("Tic Tac To!");
      // Start loop
      while ( true ) {
	  System.out.println("");
	  // System.out.println(game_state.current_player);
	  // Use try incase of invalid number input
	  try {
	      // Try things
	      System.out.println(msg_input_row);
	      int row = scan.nextInt();
	      System.out.println(msg_input_column);
	      int column = scan.nextInt();
	      game_state.setMove(row,column,game_state.current_player);
	      game_state.checkWinner();
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

  public boolean setMove(int row, int column, boolean who) {
      try {
	  System.out.println("--> setMove");
	  String who_string;
	  if (who) {
	      who_string = "X";
	  } else {
	      who_string = "O";
	  }
	  grid[row][column] = who_string; 
	  return true;
      }
      catch (ArrayIndexOutOfBoundsException e){
	  System.out.println("Number inputed resulted in error!");
	  return false;
      }
  }

  public boolean checkWinner() {
      System.out.println("--> checkWinner");
      getGameState();
      return true;
  }

  public String getGameState() {
      String row0 = "|";
      String row1 = "|";
      String row2 = "|";
      for (int i = 0; i < grid.length; ++i) {
      for(int j = 0; j < grid[i].length; ++j) {
        // System.out.println(grid[i][j]);
	if (i == 0) {
	    row0 = row0 + grid[i][j] + "|";
	} else if (i == 1) {
	    row1 = row1 + grid[i][j] + "|";
	} else if (i == 2) {
	    row2 = row2 + grid[i][j] + "|";
	}
      }
    }
    System.out.println(row0);
    System.out.println(row1);
    System.out.println(row2);
     return " gamestate "; 
  }

  public static void clearScreen() {   
    System.out.print("\033[H\033[2J");   
    System.out.flush();   
   }
}
