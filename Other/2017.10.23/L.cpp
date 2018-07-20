#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int p[15],a[100005][6];
int n;

void judge(int q,int x,int y) {
	if (q==0) a[n][x]++,a[n][y]++;
	if (q==1) a[n][x]+=3;
	if (q==2) a[n][y]+=3;
}

void dfs(int step) {
	if (step==7) {
		n++; 
		judge(p[1],1,2);
		judge(p[2],1,3);
		judge(p[3],1,4);
		judge(p[4],2,3);
		judge(p[5],2,4);
		judge(p[6],3,4);
	} else {
		p[step]=0;
		dfs(step+1);
		p[step]=1;
		dfs(step+1);
		p[step]=2;
		dfs(step+1);
	}
}

int main() {
	int cas,cnt=0;
	mem0(a);n=0;
	dfs(1);
	scanf("%d",&cas);
	while (cas--) {
		int i,q,w,e,r,cn=0;
		cnt++;
		scanf("%d%d%d%d",&q,&w,&e,&r);
		for (i=1;i<=n;i++) {
			if (q==a[i][1]&&w==a[i][2]&&e==a[i][3]&&r==a[i][4]) cn++;
		}
		printf("Case #%d: ",cnt);
		if (cn==1) printf("Yes\n"); else if (cn==0) printf("Wrong Scoreboard\n");
		else printf("No\n");
	}
	return 0;
}
