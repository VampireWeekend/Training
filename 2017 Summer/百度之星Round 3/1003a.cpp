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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 7
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
bool visit[maxn][maxn];
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int dfs(int i,int j,int step) {
	if (step==2*N) return 1;
	visit[i][j]=1;
	int ans=0;
	for (int k=0;k<8;k++) {
		int x=i+dir[k][0],y=j+dir[k][1];
	    if (x>0&&y>0&&x<=N&&y<=2&&!visit[x][y]) {
	    	ans+=dfs(x,y,step+1);
	    }	
	}
	visit[i][j]=0;
	return ans;
}

int main() {
	mem0(visit);
	int ans=0;
	for (int i=1;i<=N;i++) {
		ans+=dfs(i,1,1)+dfs(i,2,1);
	}
	cout << ans;
	return 0;
}

