import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        ArrayList<BigInteger> l = new ArrayList<>();
        l.add(new BigInteger("1"));
        while (l.size() < 70) {
            l.add(l.get(l.size() - 1).multiply(new BigInteger("3")));
        }

        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String s = sc.next();
            if (s.equals("0"))
                break;
            BigInteger bi = new BigInteger(s);
            bi = bi.subtract(new BigInteger("1"));
            ArrayList<BigInteger> res = new ArrayList<>();
            int len = bi.bitLength();
            for (int i = 0; i <= len; i++) {
                if (bi.testBit(i)) {
                    res.add(l.get(i));
                }
            }
            if (res.size() == 0) {
                System.out.println("{ }");
            } else {
                System.out.print("{ ");
                boolean isFirst = true;
                for (BigInteger x : res) {
                    if (isFirst)
                        isFirst = false;
                    else
                        System.out.print(", ");
                    System.out.print(x.toString());
                }
                System.out.println(" }");
            }
        }
    }
}