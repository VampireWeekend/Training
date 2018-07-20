#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
char s[10][1035][1035];

int main() {
	int n,t,q,i,j;
	scanf("%d",&n);
	int cnt=0;
	for (i=1;i<=8;i++) s[1][1][i]=s[1][8][i]='*';
	for (i=1;i<=8;i++) 
	    if (i==1||i==3||i==6||i==8)
		    s[1][6][i]=s[1][7][i]='*'; 
		else s[1][6][i]=s[1][7][i]=' '; 
	for (i=1;i<=8;i++) 
	    if (i==4||i==5)
		    s[1][2][i]=s[1][3][i]=s[1][4][i]=' '; 
		else s[1][2][i]=s[1][3][i]=s[1][4][i]='*'; 
	for (i=1;i<=8;i++) 
	    if (i==2||i==7)
		    s[1][5][i]=' '; 
		else s[1][5][i]='*';
	map<int,int> my;
	my[8]=1;
	for (n=16;n<=1024;n*=2) {
		my[n]=my[n/2]+1;
		//line1
		for (i=1;i<=n;i++) printf("*");
		printf("\n");
		//line2-4
		for (i=1;i<=n/8-1;i++) {
			printf("*");
			for (j=2;j<n;j++) printf(" ");
			printf("*\n");
		}
		//line5
			printf("*");
			for (j=1;j<=n/8-1;j++) printf(" ");
			for (j=1;j<=n/4;j++) printf("*");
			for (j=1;j<=n/4;j++) printf(" ");
			for (j=1;j<=n/4;j++) printf("*");
			for (j=1;j<=n/8-1;j++) printf(" ");
			printf("*\n");
			//line6-12
		for (i=1;i<=n/4-1;i++) {
			printf("*");
			for (j=1;j<=n/8-1;j++) printf(" ");
			for (j=1;j<=n/4;j++) 
			if (j!=1&&j!=n/4) printf(" "); else printf("*");
			for (j=1;j<=n/4;j++) printf(" ");
			for (j=1;j<=n/4;j++) 
			if (j!=1&&j!=n/4) printf(" "); else printf("*");
			for (j=1;j<=n/8-1;j++) printf(" ");
			printf("*\n");
		}
		//line13
			printf("*");
			for (j=1;j<=n/8-1;j++) printf(" ");
			for (j=1;j<=n/4;j++) printf("*");
			for (j=1;j<=n/4;j++) printf(" ");
			for (j=1;j<=n/4;j++) printf("*");
			for (j=1;j<=n/8-1;j++) printf(" ");
			printf("*\n");
	//	line14-line16
		for (i=1;i<=n/8-1;i++) {
			printf("*");
			for (j=2;j<n;j++) printf(" ");
			printf("*\n");
		}	
    }
	return 0;
}
