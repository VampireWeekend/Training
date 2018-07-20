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
int d[maxn][maxn];
int a[maxn][maxn];
bool visit[55][55];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; 
int n,m;
vector<int> v[55];
map<int,int> mp;

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

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int q,i,j,k,l,sx,sy,num=0;
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
				if (s[i][j]=='@') {
					mp[i*100+j]=num++;
					v[26].push_back(num-1);
				}
			}
		}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++) 
				if ((s[i][j]>='A'&&s[i][j]<='Z')||(s[i][j]=='@')) 
					bfs(i,j,mp[i*100+j]);
		scanf("%d",&q);
		int ans=inf;
		for (i=1;i<=q;i++) {
			scanf("%s",t+1);
			int len=strlen(t+1);
			meminf(a);int cnt=0;
			for (l=0;l<v[26].size();l++) {
				cnt=0;
				for (j=0;j<=26;j++)
				for (k=0;k<v[j].size();k++) {
					a[0][cnt]=min(a[0][cnt],d[v[26][l]][v[j][k]]);
					cnt++;
				}
			}
			cnt=0;
			for (j=0;j<=26;j++)
			for (k=0;k<v[j].size();k++) {
				for (l=0;l<v[t[1]-'A'].size();l++)
					a[1][l]=min(a[1][l],a[0][cnt]+d[v[j][k]][v[t[1]-'A'][l]]);
				cnt++;
			}
			t[0]=(char)('Z'+1);
			for (j=2;j<=len;j++)
				for (k=0;k<v[t[j]-'A'].size();k++)
					for (l=0;l<v[t[j-1]-'A'].size();l++)
						a[j][k]=min(a[j][k],a[j-1][l]+d[v[t[j-1]-'A'][l]][v[t[j]-'A'][k]]);
			for (k=0;k<v[t[len]-'A'].size();k++)
				ans=min(ans,a[len][k]);
		}
		if (ans==inf) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}

