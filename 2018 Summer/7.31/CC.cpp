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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int x[maxn],y[maxn],head[maxn];
bool del[maxn];
int dfn[maxn],low[maxn];
bool inst[maxn];
map<ll,int> mp;
int num=0;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
//	cout << num-1 << ' ' << from << ' ' << to << endl;
}

stack<int> st;
void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	int rem=-1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!dfn[to]) {
			tarjan(to);
			del[i]=1;
			low[now]=min(low[now],low[to]);
		}
		else if (inst[to]) {
			if (low[now]>low[to]) rem=i; 
			low[now]=min(low[now],dfn[to]); 
		}
	}
	if (rem!=-1) del[rem]=1;
	if (dfn[now]==low[now]) {
		inst[now]=0;
		while (st.top()!=now) {
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	memset(head,-1,sizeof(head));
	while (cas--) {
		int n,m;
		scanf("%d%d",&n,&m);
		mem0(dfn);mem0(low);mem0(inst);
		num=1;
		for (int i=1;i<=m;i++) {
			scanf("%d%d",&x[i],&y[i]);
			addedge(x[i],y[i]);
			del[i]=0;
		}
		tarjan(1);
		int cnt=0;
		for (int i=1;i<=m;i++) {
			if (!del[i]) {
				printf("%d %d\n",x[i],y[i]);
				cnt++;
			}
			if (m-cnt==2*n) break;
		}
		assert(m-cnt==2*n);
		for (int i=1;i<=n;i++) head[i]=-1;
	}
	return 0;
}
