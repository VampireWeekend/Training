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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
bool visit[100][100][6][2];
char s[maxn][maxn];
int d[4][2];
int sx,sy,tx,ty,n,m;

struct node {
	int x,y,o,t;
	bool p;
	node(int x,int y,int o,bool p,int t):x(x),y(y),o(o),p(p),t(t) {}
	bool operator <(const node &x)const {
	    return t>x.t;
	}
};

int dij() {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
    pq.push(node(sx,sy,0,0,0));
	while (!pq.empty()) {
        node now=pq.top();
//		cout << now.x << ' ' << now.y << ' ' << now.o << ' ' << now.p << ' ' << now.t << endl;
		if (now.x==tx&&now.y==ty) return now.t;
		if (visit[now.x][now.y][now.o][now.p]) {
            pq.pop();continue;
        }
        visit[now.x][now.y][now.o][now.p]=1;
        pq.pop();
		for (int i=0;i<4;i++) {
			int nx=now.x+d[i][0],ny=now.y+d[i][1],no=now.o,nt=now.t;
			bool np=now.p;
			if (nx<0||nx>=n||ny<0||ny>=m) continue;
			if (s[nx][ny]=='B') {
				no=min(no+1,5);
			}
			if (np==1) {
				np=0;
			} else nt++;
			if (s[nx][ny]=='#') nt++,no--;
			if (s[nx][ny]=='P') {
				np=1;
			}
			if (no<0) continue;
			if (!visit[nx][ny][no][np]) pq.push(node(nx,ny,no,np,nt));
		}
	}
	return -1;
}

int main() {
	scanf("%d%d",&n,&m);
	d[0][0]=0;d[0][1]=1;
	d[1][0]=0;d[1][1]=-1;
	d[2][1]=0;d[2][0]=1;
	d[3][1]=0;d[3][0]=-1;
	while (n&&m) {
		for (int i=0;i<n;i++) {
			scanf("%s",s[i]);
			for (int j=0;j<m;j++) {
				if (s[i][j]=='S') sx=i,sy=j;
				if (s[i][j]=='T') tx=i,ty=j;
			}
		}
		int ans=dij();
		printf("%d\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
