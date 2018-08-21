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
    	BigInteger a[][]=new BigInteger [100][100];
    	for (int i=1;i<=80;i++) {
			a[i][1]=a[0][i]=BigInteger.ONE;
		}
		for (int i=1;i<=80;i++) {
			for (int j=2;j<=80;j++) {
				a[i][j]=a[i-1][j].add(a[i][j-1]);
			}
		}
    	while (cas!=0) {
    		cas--;
    		int n,m;
    		BigInteger MOD,ans=BigInteger.ONE;
    		n=in.nextInt();
    		m=in.nextInt();
    		MOD=in.nextBigInteger();
    		if (MOD.compareTo(BigInteger.ONE)==0) {
    			System.out.println(0);
    			continue;
    		}
    		for (int i=1;i<=n*m;i++) {
    			ans=ans.multiply(BigInteger.valueOf(i));
    		}
    		ans=ans.multiply(BigInteger.valueOf(m));
    		ans=ans.divide(a[n][m]);
    		ans=ans.mod(MOD);
    		System.out.println(ans);
    	}
    }
}
