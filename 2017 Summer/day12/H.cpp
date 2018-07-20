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
const int maxn=11,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int row[maxn],col[maxn],sub[maxn];
int a[maxn][maxn]

int kuai(int i,int j) {
	return ((i-1)/3)*3+(j-1)/3+1;
}

bool dfs(int i,int j) {
	int n;
	if (i==10) return true;
	if (a[i][j]=='.') {
		for (n=1;n<=9;n++) {
			
		}
	} else return dfs(j==9?i+1:i,j==9?1:j+1);
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	mem0(row);
	mem0(col);
	mem0(sub);
	char c;
	for (i=1;i<=9;i++) {
		for (j=1;j<=9;j++) {
			scanf("%c",&c);
	    	if (c!='.') {
			    int num=c-'0';
			    int p=(1<<(num-1));
			    row[i]+=p;
			    col[j]+=p;
			    sub[kuai(i,j)]+=p;
	    	}
		}
	}
	dfs(1,1);
	return 0;
}

