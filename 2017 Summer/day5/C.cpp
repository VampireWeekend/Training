#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=305;
int a[maxn][maxn],one[maxn][maxn],zero[maxn][maxn];
int lone[maxn][maxn],uone[maxn][maxn];

int sqr(int x) {
	return x*x;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,m,i,j,k;
		scanf("%d%d",&n,&m);
		one[0][0]=0;
		for (j=1;j<=m;j++)
		    one[0][j]=one[j][0]=lone[j][0]=uone[0][j]=0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				scanf("%d",&a[i][j]);
				if (a[i][j]) {
				if (a[i-1][j]) {
					uone[i][j]=uone[i-1][j]+1;
				} else uone[i][j]=1;
				if (a[i][j-1]) {
					lone[i][j]=lone[i][j-1]+1;
				} else lone[i][j]=1;
			    	one[i][j]=one[i][j-1]+one[i-1][j]-one[i-1][j-1];
					one[i][j]++;
		    	} else {
		    		uone[i][j]=lone[i][j]=0;
		    		one[i][j]=one[i][j-1]+one[i-1][j]-one[i-1][j-1];
		    	}
		//		cout << i << " " << j << "     ";
		//		cout << one[i][j] << ' ' << lone[i][j] << ' ' << uone[i][j] << ' ' << endl; 
			}
		}
		int tot=0;
		for (i=2;i<=n;i++) {
			for (j=2;j<=n;j++) {
				for (k=2;k<=min(lone[i][j],uone[i][j]);k++) {
					if (min(lone[i-k+1][j],uone[i][j-k+1])>=k) {
						int num=one[i-1][j-1]-one[i-k+1][j-1]
						-one[i-1][j-k+1]+one[i-k+1][j-k+1];
						if (abs(2*num-sqr(k-2))<=1) tot++;
					}
				} 
			} 
		}
		printf("%d\n",tot);
	}
	return 0;
}
