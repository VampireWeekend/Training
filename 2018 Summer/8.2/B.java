package main;

import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;

public class Main {

    public static BigInteger MOD = BigInteger.valueOf(1000000007);

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a,b,c,d,e,f,ans;
        a=BigInteger.valueOf(0);
		b=c=BigInteger.valueOf(2);
		BigInteger n=in.nextBigInteger();
		while (c.compareTo(n)<0) {
			c=b.multiply(BigInteger.valueOf(6)).subtract(a);
			a=b;b=c;
		}
		 d=BigInteger.valueOf(0);
			e=f=BigInteger.valueOf(6);
			while (f.compareTo(n)<0) {
				f=e.multiply(BigInteger.valueOf(14)).subtract(d);
				d=e;e=f;
			}
        	if (c.compareTo(f)<0)
        	System.out.println(c); else System.out.println(f);
    }
}
