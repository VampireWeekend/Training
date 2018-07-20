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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,maxk=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int num[maxn],head[maxn];
bool out[maxn];
int inque[maxn],dist[maxn],val[maxn];
int nnum;

struct Edge {
	int from,to,dist,pre;
};
Edge edge[maxn];

void addedge(int f,int t,int d) {
	edge[++nnum]=(Edge){f,t,d,head[f]};
	head[f]=nnum;
}

int spfa(int s,int n){
	int i;
    mem0(inque);
    mem0(val);
    meminf(dist);
	inque[s]=1;
	queue<int> q;
	q.push(s);
	dist[s]=0;
	val[s]=num[s];
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;     
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[edge[i].from]+edge[i].dist<dist[to]&&val[now]>=edge[i].dist) {
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
				dist[to]=dist[edge[i].from]+edge[i].dist;
				val[to]=val[now]-edge[i].dist+num[to];
			}
		}
	}
	int ans=inf;
	for (i=2;i<=n;i++) {
		if (out[i]) ans=min(ans,dist[i]);
	}
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	string s,s1,s2;
	char c[5];
	while (cas--) {
		int n,m,i,j;
		scanf("%d%d",&n,&m);
		map<string,int> my;
		mem0(out);
		for (i=1;i<=n;i++) {
			cin >> s;
			my[s]=i; 
			scanf("%d",&num[i]);
			scanf("%s",c);
			if (c[0]=='y') out[i]=1;
		}
		int d;
		nnum=0;
		memset(head,-1,sizeof(head));
		for (i=1;i<=m;i++) {
			cin >> s1 >> s2 >> d;
			addedge(my[s1],my[s2],d);
		}
		int ans=spfa(1,n);
		if (ans!=inf) printf("%d\n",ans); else printf("No safe path\n");
	}
	return 0;
}
