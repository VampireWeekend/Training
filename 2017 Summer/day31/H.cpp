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
const int maxn=205,maxk=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[maxn][maxn],b[maxn][maxn];
int path[maxn],rflow[maxn],inque[maxn],dist[maxn];
int head[maxn],ans1[maxn],ans2[maxn],ans3[maxn],k[maxn];
string s;
int num; 
struct Edge {
	int from,to,cost,flow,pre;
};
Edge edge[maxk*2];

void addedge(int s,int t,int cost,int flow) {
	edge[num]=(Edge){s,t,cost,flow,head[s]};
	head[s]=num++;
	edge[num]=(Edge){t,s,-cost,0,head[t]};
	head[t]=num++;
}

int spfa(int s,int t) {
	mem0(inque);meminf(dist);
	memset(path,-1,sizeof(path));
	memset(rflow,-1,sizeof(rflow));
	queue<int> q;
    q.push(s);
    inque[s]=1;
    int i;
    dist[s]=0;
    rflow[s]=inf;
    while (!q.empty()) {
    	int now=q.front();
    	q.pop();
    	inque[now]=0;
    	for (i=head[now];i!=-1;i=edge[i].pre) {
    		int to=edge[i].to;
    		if (edge[i].flow>0&&dist[now]+edge[i].cost<dist[to]) {
    			dist[to]=dist[now]+edge[i].cost;
    			path[to]=i;
    			rflow[to]=min(rflow[now],edge[i].flow);
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
    		}
    	}
    }
    if (dist[t]==inf) return 0; else return dist[t];
}

int mincostmaxflow(int s,int t) {
	int f,sum=0,now;
	while (f=spfa(s,t)) {
		now=path[t];
		while (now!=-1) {
//			int i=now;
//			cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;   
			edge[now].flow-=rflow[t];
			edge[now^1].flow+=rflow[t];
			now=path[edge[now].from];
//			cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;
		}
		sum+=f;
	}
	return sum;
}

int main (){
	int n,qwe=0;
	scanf("%d",&n);
	while (n!=0) {
		qwe++;
		int i,j;
		num=0;
		memset(head,-1,sizeof(head));
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				scanf("%d",&a[i][j]);
				addedge(i,j+n,a[i][j],1);
			}
		}
		for (i=1;i<=n;i++) {
			addedge(0,i,0,1);
			addedge(i+n,2*n+1,0,1);
		}
		int ans=mincostmaxflow(0,2*n+1);
		int cnt=0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (edge[cnt].flow==0) ans1[i]=j,k[j]=i;
				cnt+=2;
			}
		}
		
		num=0;
		memset(head,-1,sizeof(head));
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				scanf("%d",&b[i][j]);
				addedge(i,j+n,max(a[i][ans1[i]],a[k[j]][j])+b[i][j],1);
			}
		}
		for (i=1;i<=n;i++) {
			addedge(0,i,0,1);
			addedge(i+n,2*n+1,0,1);
		}
		ans=mincostmaxflow(0,2*n+1);
		cnt=0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (edge[cnt].flow==0) ans2[i]=j,ans3[i]=edge[cnt].cost;
				cnt+=2;
			}
		}
		int sum=0;
		printf("Case %d:\n",qwe);
		for (i=1;i<=n;i++) {
			printf("Worker %d: %d %d %d\n",i,ans1[i],ans2[i],ans3[i]);
			sum+=ans3[i]-a[i][ans1[i]]-b[i][ans2[i]];
		}
		printf("Total idle time: %d\n",sum);
		scanf("%d",&n);
	}
	return 0;
}
