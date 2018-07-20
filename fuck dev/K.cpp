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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dfn[maxn],low[maxn],color[maxn],val[maxn],head[maxn],a[maxn],d[maxn];
bool inst[maxn];
stack<int> st;
int num,cnum;

struct Edge{
	int from,to,pre;
};
Edge e[maxn];

void addedge(int from,int to) {
	e[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	for (int i=head[now];i!=-1;i=e[i].pre) {
		int to=e[i].to;
		if (!dfn[to]) {
			tarjan(to);low[now]=min(low[now],low[to]);
		} else if (inst[to]) low[now]=min(low[now],dfn[to]);
	}
	if (dfn[now]==low[now]) {
		inst[now]=0;
		color[now]=++cnum;
		val[cnum]=now;
		while (st.top()!=now) {
			color[st.top()]=cnum;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

int main() {
	num=0;memset(head,-1,sizeof(head));
	int n,i,j;
	scanf("%d",&n);
	n*=2;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		addedge(i,a[i]); 
	}
	mem0(color);mem0(dfn);mem0(low);
	mem0(inst);num=0;
	for (i=1;i<=n;i++) {
		if (!dfn[i]) tarjan(i);
	}
	num=0;memset(head,-1,sizeof(head));
	for (i=1;i<=n;i++) {
		if (color[i]!=color[a[i]]) addedge(color[i],color[a[i]]);
	}
	
	return 0;
}
