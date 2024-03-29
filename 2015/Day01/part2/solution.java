package Day01;

import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public final class solution {
  
  public static void main(String[] args) throws IOException {

    Scanner sc = new Scanner(new File("input.txt"));
    String steps = sc.next();
    
    int count = 0;
    int position = 0;

    for (int i = 0; i < steps.length(); i++) {
      count += steps.charAt(i) == '(' ? 1 : -1;
      position++; 

      if (count == -1) {
        System.out.println("Santa enters the basement at position " + position);
        break;
      }
    }

    sc.close();
  }
}
