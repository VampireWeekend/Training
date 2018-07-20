#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=4,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[8][8];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i,j,k,n;
	mem0(a);
	for (i=1;i<=4;i++) {
		for (j=1;j<=4;j++) {
			scanf("%d",&a[i][j]);
		}
	} 
	int dir;
	cin >> dir;
	if (dir==0) {
		for (i=1;i<=4;i++) {
			int last=-1;
			for (j=1;j<=4;j++) {
				if (a[i][j]!=0) {
					if (last==-1) last=j;
					else {
						if (a[i][j]==a[i][last]) {
							a[i][last]*=2;
							a[i][j]=0;
							last=-1;
						}else last=j;
					}
				}
			}
		}
		for (i=1;i<=4;i++) {
			for (j=1;j<=4;j++) {
				int cnt=0;
				while (a[i][j]==0&&cnt<=4) {
					for (k=j;k<=4;k++)
					    a[i][k]=a[i][k+1];
					cnt++;
				}
			}
		}
	}
	if (dir==2) {
		for (i=1;i<=4;i++) {
			int last=-1;
			for (j=4;j>=1;j--) {
				if (a[i][j]!=0) {
					if (last==-1) last=j;
					else {
						if (a[i][j]==a[i][last]) {
							a[i][last]*=2;
							a[i][j]=0;
							last=-1;
						}else last=j;
					}
				}
			}
		}
		for (i=1;i<=4;i++) {
			for (j=4;j>=1;j--) {
				int cnt=0;
				while (a[i][j]==0&&cnt<=4) {
					for (k=j;k>=1;k--)
					    a[i][k]=a[i][k-1];
					cnt++;
				}
			}
		}
	}
	if (dir==1) {
		for (i=1;i<=4;i++) {
			int last=-1;
			for (j=1;j<=4;j++) {
				if (a[j][i]!=0) {
					if (last==-1) last=j;
					else {
						if (a[j][i]==a[last][i]) {
							a[last][i]*=2;
							a[j][i]=0;
							last=-1;
						} else last=j;
					}
				}
			}
		}
		for (i=1;i<=4;i++) {
			for (j=1;j<=4;j++) {
				int cnt=0;
				while (a[j][i]==0&&cnt<=4) {
					for (k=j;k<=4;k++)
					    a[k][i]=a[k+1][i];
					cnt++;
				}
			}
		}
	}
	if (dir==3) {
		for (i=1;i<=4;i++) {
			int last=-1;
			for (j=4;j>=1;j--) {
				if (a[j][i]!=0) {
					if (last==-1) last=j;
					else {
						if (a[j][i]==a[last][i]) {
							a[last][i]*=2;
							a[j][i]=0;
							last=-1;
						}else last=j;
					}
				}
			}
		}
		for (i=1;i<=4;i++) {
			for (j=4;j>=1;j--) {
				int cnt=0;
				while (a[j][i]==0&&cnt<=4) {
					for (k=j;k>=1;k--)
					    a[k][i]=a[k-1][i];
					cnt++;
				}
			}
		}
	}
	for (i=1;i<=4;i++) {
		for (j=1;j<=4;j++) {
			printf("%d",a[i][j]);
			if (j!=4) printf(" ");
		}
		printf("\n");
	} 
	return 0;
}
