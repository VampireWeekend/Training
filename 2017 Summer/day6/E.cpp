#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <string> 
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
int t[10][10];

int main() {
	int i,j,ans;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++) {
			scanf("%d",&t[i][j]);
		}
	}
	ans=0;
	int a,b,c,d,e,l;
	for (a=0;a<10;a++) {
		for (b=0;b<10;b++) {
			for (c=0;c<10;c++) {
				for (d=0;d<10;d++) {
			//	a=2;b=0;c=1;d=6;
					int flag=0;
					e=t[t[t[t[0][a]][b]][c]][d];
					int ee;
					int q;
					
						for (l=0;l<=9;l++) {
							if (l!=a) {
							ee=t[t[t[t[0][l]][b]][c]][d];
							if (t[ee][e]==0) flag=1;
							}
						}
						for (l=0;l<=9;l++) {
							if (l!=b) {
				         	ee=t[t[t[t[0][a]][l]][c]][d];
							if (t[ee][e]==0) flag=1;
							}
						}
						for (l=0;l<=9;l++) {
							if (l!=c) {
				         	ee=t[t[t[t[0][a]][b]][l]][d];
							if (t[ee][e]==0) flag=1;
							}
						}
						for (l=0;l<=9;l++) {
							if (l!=d) {
				         	ee=t[t[t[t[0][a]][b]][c]][l];
							if (t[ee][e]==0) flag=1;
							}
						}
						for (l=0;l<=9;l++) {
							if (l!=e) {
				         	if (t[e][l]==0) flag=1;
							}
						}
						if (a!=b) {
							ee=t[t[t[t[0][b]][a]][c]][d];
				        if (t[ee][e]==0) flag=1;
						}
						if (b!=c) {
							ee=t[t[t[t[0][a]][c]][b]][d];
						if (t[ee][e]==0) flag=1;
						}
				        if (c!=d) {
				        	ee=t[t[t[t[0][a]][b]][d]][c];
						if (t[ee][e]==0) flag=1;
				        }
				        if (d!=e) {
				        	ee=t[t[t[t[0][a]][b]][c]][e];
						if (t[ee][d]==0) flag=1;
				        }
					if (flag) ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
