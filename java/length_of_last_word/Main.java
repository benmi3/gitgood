public class Main {
  public static void main(String[] args) {
    System.out.println("Length of Last Word");
    String s1 = "Hello World";
    String s2 = "   fly me   to   the moon  ";
    String s3 = "luffy is still joyboy";
    System.out.println(lengthOfLastWord(s1));
    System.out.println(lengthOfLastWord(s2));
    System.out.println(lengthOfLastWord(s3));
    
  }

  public static int lengthOfLastWord(String s) {
     System.out.println(s);
     int counter = 0;
     char prev_char = ' ';
     for (char ch: s.toCharArray()){
	     if (ch != ' ') {
	         if (prev_char == ' ') {
		     counter = 0;
		     counter ++;
	         } else {
		     if (ch != ' '){
			counter ++;
		     }
		 }
	}
	prev_char = ch;
     }
    return counter;
    }
}

