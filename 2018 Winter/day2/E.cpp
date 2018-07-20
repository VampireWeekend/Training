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
const int maxn=505,maxk=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],visit[maxn];
char s[maxn],t[maxn],c[maxn]; 
map<string,int> mp;
int num=0;

struct Edge {
	int to,pre;
};
Edge edge[maxk*2];

void addedge(int from,int to) {
	edge[num]=(Edge){to,head[from]};
	head[from]=num++;
}

int main() {
	int n,m,i,j,x,y,cnt=0;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (i=1;i<=n;i++) {
		scanf("%s%s%s",s,c,t);
		x=mp[s];y=mp[t];
		if (x==0) x=mp[s]=++cnt;
		if (y==0) y=mp[t]=++cnt;
		addedge(y,x);
	}
	for (i=1;i<=m;i++) {
		scanf("%s%s%s",s,c,t);
		printf("Query %d: ",i);
			x=mp[t];y=mp[s];
			if (x==y) {
				printf("true\n");continue;
			}
			queue<int> q;
			q.push(x);visit[x]=i;int flag=0;
			while (!q.empty()) {
				int now=q.front();q.pop();
				for (j=head[now];j!=-1;j=edge[j].pre) {
					if (visit[edge[j].to]!=i) {
						if (y==edge[j].to) {
							flag=1;break;
						}
						visit[edge[j].to]=i;
						q.push(edge[j].to);
					}
				}
				if (flag) break;
			}
			if (flag) printf("true\n"); else printf("false\n");
	}
	return 0;
}
