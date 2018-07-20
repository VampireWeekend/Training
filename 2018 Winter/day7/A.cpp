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
const int maxn=405,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
char s[55][55];
char t[1005];
int d[maxn][maxn],dist[maxn];
bool inque[maxn];
bool visit[55][55];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; 
int n,m;
vector<int> v[55];
map<int,int> mp;

struct node {
	int id,last,len;
	node(int id,int last,int len):id(id),last(last),len(len) {}
};

void bfs(int sx,int sy,int st) {
	queue<int> qx;
	queue<int> qy;
	queue<int> step;
	mem0(visit);
	d[st][st]=0;
	qx.push(sx);qy.push(sy);step.push(0);
	visit[sx][sy]=1;
	while (!qx.empty()) {
		int x=qx.front(),y=qy.front(),ns=step.front();
//		cout << x << ' ' << y << ' ' << ns << endl;
		qx.pop();qy.pop();step.pop();
		for (int i=0;i<4;i++) {
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if (nx>0&&ny>0&&nx<=n&&ny<=m&&!visit[nx][ny]&&s[nx][ny]!='#') {
				visit[nx][ny]=1;
				if (s[nx][ny]>='A'&&s[nx][ny]<='Z') {
					int to=mp[nx*100+ny];
					d[st][to]=min(ns+1,d[st][to]);
				} else {
					qx.push(nx);qy.push(ny);step.push(ns+1);
				}
			}
		}
	}
}

ll spfa(int st){
	int i;
    memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
	inque[st]=1;
	queue<node> q;
	q.push_back(node(st,0));
	dist[st]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (j=0;j<v[t[now.id]-'A'].size();j++) {
			int fuck=v[t[now.id]-'A'][j];
			fuck=d[now.last][fuck];
			if (fuck!=inf)
				pq.push(node(now.id+1,now.dist+fuck,v[t[now.id]-'A'][j]));
		}
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[edge[i].from]+edge[i].dist<dist[to]) {
				if (!inque[to]) q.push_back(to);
				dist[to]=dist[edge[i].from]+edge[i].dist;
			}
		}
	}
	return dist[des];
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int q,i,j,sx,sy,num=0,start;
		mp.clear();
		scanf("%d%d",&n,&m);
		meminf(d);
		for (i=0;i<=26;i++) v[i].clear();
		for (i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for (j=1;j<=m;j++) {
				if (s[i][j]>='A'&&s[i][j]<='Z') {
					mp[i*100+j]=num++;
					v[s[i][j]-'A'].push_back(num-1); 
				}
				if (s[i][j]=='@') start=mp[i*100+j]=num++;
			}
		}
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (s[i][j]>='A'&&s[i][j]<='Z') {
					bfs(i,j,mp[i*100+j]);
				}
				if (s[i][j]=='@') bfs(i,j,start);
			}
		}
		scanf("%d",&q);
		int ans=inf;
		for (i=1;i<=q;i++) {
			scanf("%s",t);
			int len=strlen(t);
			sum=spfa(start);
			ans=min(ans,sum);
		}
		if (ans==inf) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
