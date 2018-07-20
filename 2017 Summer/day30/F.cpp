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
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1005,maxk=2000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int color[maxn*2],x[maxn],y[maxn],head[maxn*2],dfn[maxn*2];
int num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxk];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

bool dfs(int now) {
	if (color[now]==1) return true;
	if (color[now]==2) return false;
	color[now]=1;
	color[now^1]=2;
	dfn[++num]=now;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!dfs(to)) return false;
	}
	return true;
}

int main() {
	int n,r,l,i,j;
	num=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&r,&l);
	for (i=0;i<l;i++) {
		scanf("%d%d",&x[i],&y[i]);
		for (j=0;j<i;j++) {
			if (x[i]==x[j]) {
				if (abs(y[i]-y[j])<=2*r) addedge(j*2,(i*2)^1),addedge(i*2,(j*2)^1);
			} else if (y[i]==y[j]) {
				if (abs(x[i]-x[j])<=2*r) addedge((j*2)^1,i*2),addedge((i*2)^1,j*2);
			}
		}
	}
	mem0(color);
	for (i=0;i<l;i++) {
			if (!color[i*2]) {
				num=0;
				if (!dfs(i*2)) {
					for (j=1;j<=num;j++) 
						color[dfn[j]]=color[dfn[j]^1]=0;
					if (!dfs(i*2+1)) {
				    	printf("NO");
				    	return 0;
			    	}
				}
			}
		}
	printf("YES");
	return 0;
}

