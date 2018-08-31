package main;

import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;

public class Main {

 //   public static BigInteger MOD = BigInteger.valueOf(1000000007);

    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	int cas;
    	cas=in.nextInt();
    	while (cas!=0) {
    		int n;
    		n=in.nextInt();
    		BigInteger ans=BigInteger.ONE;
    		for (int i=1;i<=n;i++) {
    			ans=ans.multiply(BigInteger.valueOf(2));
    		}
    		System.out.println(ans);
    	}
    }
}
