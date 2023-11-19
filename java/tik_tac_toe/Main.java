import java.util.Scanner;                // Import the Scanner class
import java.util.InputMismatchException; // Import the Scanner Error

public class Main {
  // keep gamestate outside
  String[][] grid;
  boolean current_player; 
  int turn_counter;

  public static void main(String[] args) {
      Main game_state = new Main();
      // Start decleration
      // Imported Classes
      Scanner scan = new Scanner(System.in);
      // Create variables
      game_state.grid = createFreshGame();
      game_state.turn_counter = 0;
      String msg_input_row = "Please input row (0-2):";
      String msg_input_column = "Please input column (0-2):";
      // Clear terminal
      game_state.clearScreen();
      // Greet the user
      System.out.println("Tic Tac To!");
      // Start loop
      while ( true ) {
	  System.out.println(game_state.turn_counter);
	  game_state.displayGameState();
	  // Variables
	  int row;
	  int column;
	  String player_sign;
	  String player_pointer;
	  // Checks
	  if (game_state.current_player) {
	      player_sign = "X";
	  } else {
	      player_sign = "O";
	  }
	  player_pointer = String.format("The current player: %s", player_sign);
	  System.out.println(player_pointer);
	  // Use try incase of invalid number input
	  try {
	      // Try things
	      do {
		System.out.println(msg_input_row);
		row = scan.nextInt();
	      }
	      while (row > 2);
	      do {
		  System.out.println(msg_input_column);
	          column = scan.nextInt();
	      }
	      while (column > 2);
	      }
	  catch (InputMismatchException e) {
	      // If invalid input is made
	      // Give warning
	      // then move on to next input
	      System.out.println("Somethings happened! Please try again!");
	      waitFive();
	      scan.next();
	      continue;
	  }
	  if (game_state.setMove(row, column, game_state.current_player)== false) {
	      System.out.println("Current move was denied. \nTry Again");
	      waitFive();
	      continue;
	  } 
	  if (game_state.checkWinner()) {
	      String announcement = String.format("The game took %o turns!", game_state.turn_counter);
	      System.out.println(announcement);
	      break;
	  }
	  ++game_state.turn_counter;
	  game_state.current_player = game_state.setCurrentPlayer();
      }
      // stop scanner
      scan.close();
      // The loop has broken
      // which means the correct answer was given
      System.out.println("Thank you for playing!");
      waitFive();
  }

  public static String[][] createFreshGame() {
      String[][] new_game = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };
      return new_game;
  }

  public boolean setCurrentPlayer(){
      if (current_player) {
	  return false;
      } else {
	  return true;
      }
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
	  if (grid[row][column] == " ") {
	      grid[row][column] = who_string; 
	      return true;
	  } else {
	      return false;
	  }
      }
      catch (ArrayIndexOutOfBoundsException e){
	  System.out.println("Number inputed resulted in error!");
	  return false;
      }
  }

  public boolean checkWinner() {
      System.out.println("--> checkWinner");
      // Display the current gamestate
      displayGameState();
      // check if winnable state has been achived
      String check_1 = checkWinner_1();
      String check_2 = checkWinner_2();
      String check_3 = checkWinner_3();
      if (check_1 != " ") {
	  String.format("Winner is: %s",check_1);
	  return true;
      } else if (check_2 != " ") {
	  String.format("Winner is: %s", check_2);
	  return true;
      } else if (check_3 != " ") {
	  String.format("Winner is: %s", check_3);
	  return true;
      }
      return false;
  }

  public String checkWinner_1() {
      System.out.println("--> checkWinner_1");
      String check = " ";
      // This checks simple row
      for (int i = 0; i < grid.length; ++i) {
	  int check_x = 0;
	  int check_y = 0;
	  for (int j = 0; j < grid[i].length; ++j) {
	      if (grid[i][j] != " ") {
		  if (grid[i][j] == "X") {
		      ++check_x;
		  } else if (grid[i][j] == "O") {
		      ++check_y;
		  }
	      }
	  }
	  if (check_x > 2) {
	      check = "X";
	  } else if (check_y > 2) {
	      check = "O";
	  }
      }
      return check;
  }

  public String checkWinner_2() {
      System.out.println("--> checkWinner_2");
      String check = " ";
      // This checks column
      // This function might break due to array
      // array out of bound
      for (int i = 0; i < grid.length; ++i) {
	  int check_x = 0;
	  int check_y = 0;
	  for (int j = 0; j < grid[i].length; ++j) {
	      if (grid[j][i] != " ") {
		  if (grid[j][i] == "X") {
		      ++check_x;
		  } else if (grid[j][i] == "O") {
		      ++check_y;
		  }
	      }
	  }
	  if (check_x > 2) {
	      check = "X";
	  } else if (check_y > 2) {
	      check = "O";
	  }
      }
      return check;
  }

  public String checkWinner_3() {
      System.out.println("--> checkWinner_3");
      String check = " ";
      // This checks for cross wins
      if (grid[0][0] != " "){
	  if (grid[0][0] == grid[1][1]) {
	      if (grid[1][1] == grid[2][2]) {
		  check = grid[2][2];
	      }
	  }
      }
      if (grid[0][2] != " ") {
	  if (grid[0][2] == grid[1][1]) {
	      if (grid[1][1] == grid[2][0]) {
		  check = grid[2][0];
	      }
	  }
      }
      return check;
  }

  public String displayGameState() {
      clearScreen();
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
    System.out.println("-------");
    System.out.println(row0);
    System.out.println("-------");
    System.out.println(row1);
    System.out.println("-------");
    System.out.println(row2);
    System.out.println("-------");
     return " gamestate "; 
  }

  public static void clearScreen() {   
    System.out.print("\033[H\033[2J");   
    System.out.flush();   
   }

  public static void waitFive() {
      try {
	  Thread.sleep(2000);
      } catch(InterruptedException e){
	  System.out.println("Wow, you couldnt wait for 5 seconds?");
	  e.printStackTrace();
    }
  }
}
