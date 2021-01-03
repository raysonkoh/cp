import java.math.BigInteger;
import java.util.Scanner;
import java.util.ArrayList;

public class m {
  public static void main(String[] args) {
    ArrayList<BigInteger> fact = new ArrayList<>();
    fact.add(new BigInteger("1"));
    fact.add(new BigInteger("1"));

    for (int i = 2; i <= 100; i++) {
      fact.add(fact.get(i - 1).multiply(new BigInteger(Integer.toString(i))));
    }

    Scanner sc = new Scanner(System.in);
    while (sc.hasNextLine()) {
      String line = sc.nextLine();
      int[] freq = new int[256];
      for (int i = 0; i < 256; i++) {
        freq[i] = 0;
      }

      int tolSize = 0;
      for (int i = 0; i < line.length(); i++) {
        int ascii = (int) line.charAt(i);
        freq[ascii]++;
        tolSize++;
      }

      BigInteger res = fact.get(tolSize);
      for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
          res = res.divide(fact.get(freq[i]));
        }
      }
      System.out.println(res.toString());
    }
  }
}