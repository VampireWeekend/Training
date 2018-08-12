
import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;

public class Main {

    public static BigInteger MOD = BigInteger.valueOf(1000000007);

    public static void main(String[] args) {
  //  	n, a(n) = (24 - 42n + 23n^2 - 6n^3 + n^4)/24.
    	Scanner in = new Scanner(System.in);
        BigInteger n,ans;
        n=in.nextBigInteger();
        if (n.compareTo(BigInteger.valueOf(3))==0) ans=BigInteger.valueOf(1);
        else {
        	ans=n.pow(4).subtract(n.pow(3).multiply(BigInteger.valueOf(6))).add(n.pow(2).multiply(BigInteger.valueOf(23)));
        	ans=ans.subtract(n.multiply(BigInteger.valueOf(42))).add(BigInteger.valueOf(24));
        	ans=ans.divide(BigInteger.valueOf(24));
        }
        ans=ans.mod(MOD);
       	System.out.println(ans);
    }
}
