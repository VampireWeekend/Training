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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=10005,maxk=500005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],current[maxn],dist[maxn],d[maxn],x[maxn],y[maxn],q[maxn],pr[maxn];
int num;
int visit[maxn];
vector<int> v[maxn];

struct Edge {  
    int from,to,flow,pre;  
};  
Edge edge[maxk*2];  
  
void addedge(int from,int to,int flow) {  
    edge[num]=(Edge){from,to,flow,head[from]};  
    head[from]=num++;  
    edge[num]=(Edge){to,from,0,head[to]};  
    head[to]=num++;  
  //  cout << from << ' ' << to << endl;
}  
  
bool bfs (int s,int n) {  
    queue<int> q;  
    q.push(s);  
    memset(dist,-1,sizeof(dist));  
    dist[s]=0;  
    while (!q.empty()) {  
        int now=q.front();  
        q.pop();  
        for (int i=head[now];i!=-1;i=edge[i].pre) {  
            int to=edge[i].to;  
            if (dist[to]==-1&&edge[i].flow>0) {  
                dist[to]=dist[now]+1;  
                q.push(to);  
            }  
        }  
    }  
    return dist[n]!=-1;  
}  
  
int dfs(int now,int flow,int n) {  
    int f;  
    if (now==n) return flow;  
    for (int i=current[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        current[now]=i;  
        if (dist[now]+1==dist[to]&&edge[i].flow>0&&(f=dfs(to,min(flow,edge[i].flow),n))) {  
            edge[i].flow-=f;  
            edge[i^1].flow+=f;  
            return f;  
        }  
    }  
    return 0;  
}  
  
int dinic(int s,int n) {  
    int sum=0,f;  
    while (bfs(s,n)) {  
        memcpy(current,head,sizeof(head));  
        while (f=dfs(s,inf,n)) sum+=f;  
    }  
    return sum;  
}  

int main() {
	int n,m,cnt;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
		d[x[i]]++;d[y[i]]++;
	}
	for (int i=1;i<=n;i++) {
		if (d[i]<n/2) continue;
		memset(head,-1,sizeof(head));
		num=cnt=0;
		visit[i]=i;
		int size=v[i].size();
		for (int j=0;j<size;j++) {
			addedge(i,v[i][j],1);
			visit[v[i][j]]=i;
		}
		for (int j=0;j<size;j++) {
			int sz=v[v[i][j]].size();
			for (int k=0;k<sz;k++) {
				int to=v[v[i][j]][k];
				if (to!=i&&visit[to]!=i) {
					addedge(v[i][j],to,1);
					if (pr[to]!=i) q[++cnt]=to,pr[to]=i;
				}
			}
		}
		for (int j=1;j<=cnt;j++) {
			addedge(q[j],n+1,1);
		}
		int ans=dinic(i,n+1);
//		cout << '\n';
		assert(ans<=n-1-d[i]);
		if (ans==n-1-d[i]) {
			printf("Yes\n");
			printf("%d %d\n",i,d[i]);
			for (int j=0;j<size;j++) {
				int now=v[i][j],flag=0;
				for (int k=head[now];k!=-1;k=edge[k].pre) {  
					int to=edge[k].to;  
					if (edge[k].flow==0&&to!=i) {  
						flag=1;
						printf("%d %d\n",now,to);
						break;
					}  
				}  
				if (!flag) printf("%d -1\n",now);
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
