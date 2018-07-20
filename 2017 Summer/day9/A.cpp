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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int down[maxn],sum[maxn],fa[maxn],head[maxn];
bool visit[maxn];
int num;

vector<int> v[maxn]; 

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from],0};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],1};
	head[to]=num++;
}

void dfs(int now) {
	down[now]=0;
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to);
			fa[to]=now;
			down[now]+=edge[i].dist+down[to];
		}
	}
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int n,i,x,y;
    num=0;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for (i=1;i<n;i++) {
    	scanf("%d%d",&x,&y);
    	addedge(x,y);
    }
    mem0(visit);
    dfs(1);
    queue<int> q;
    mem0(visit);
    q.push(1);
    visit[1]=1;
    mem0(sum);
    sum[1]=down[1];
    v[sum[1]].push_back(1);
    int ans=sum[1];
    while (!q.empty()) {
    	int now=q.front();
    	q.pop();
    	if (now!=1) {
    		sum[now]+=down[now];
    		sum[now]+=sum[fa[now]]-down[now];
    		v[sum[now]].push_back(now);
    		ans=min(ans,sum[now]);
    	}
    	for (i=head[now];i!=-1;i=edge[i].pre) {
    		int to=edge[i].to;
    		if (!visit[to]) {
    			visit[to]=1;
    			q.push(to);
    			if (edge[i].dist==0) sum[to]=1;
    			else sum[to]=-1;
    		}
    	}
    }
    printf("%d\n",ans);
    sort(v[ans].begin(),v[ans].end());
    int size=v[ans].size();
    for (i=0;i<size-1;i++) {
    	printf("%d ",v[ans][i]);
    }
    printf("%d\n",v[ans][size-1]);
	return 0;
}
