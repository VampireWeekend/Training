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
const int maxn=505,maxk=60005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int head[maxn],val[maxn],du[maxn],a[maxn],b[maxn],p[maxn],u[maxn];
char s[5];
bool visit[maxn];
int num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxk*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

void update(int n) {
	mem0(visit);
	queue<int> q;
	int i;
	memcpy(du,b,sizeof(du));
	for (i=1;i<=n;i++) {
		if (du[i]==0) q.push(i),visit[i]=1;
	}
	meminf(val);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			val[to]=min(val[to],val[now]);
			val[to]=min(val[to],a[now]);
			du[to]--;
			if (du[to]==0)
			    if (!visit[to]) visit[to]=1,q.push(to);
		}
	}
}

int main() {
	num=0;
	memset(head,-1,sizeof(head));
	int n,i,j,m,q,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		p[i]=u[i]=i;
	}
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
		b[y]++;
	}
	update(n);
	for (i=1;i<=q;i++) {
		scanf("%s",s); 
		if (s[0]=='P') {
			scanf("%d",&x);
			if (val[p[x]]==inf) printf("*\n"); else printf("%d\n",val[p[x]]);
		} else {
			scanf("%d%d",&x,&y);
			int z=a[p[x]];a[p[x]]=a[p[y]];a[p[y]]=z;
			z=p[x];p[x]=p[y];p[y]=z;
			update(n);
		}
	}
	return 0;
}

