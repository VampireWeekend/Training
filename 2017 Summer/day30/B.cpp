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
const int maxn=55,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int dp[maxn][maxn][maxn];
int mp['Z'+1];
char a[maxn][maxn],s[maxn];
int n,m;

struct node {
	int x,y,pos;
	node (int x,int y,int pos):x(x),y(y),pos(pos){}
};

bool check(int i,int j) {
	return i>0&&i<=n&&j>0&&j<=m&&a[i][j]!='#';
}

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int i,j,sx,sy,tx,ty;
	int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}}; 
	mp['R']=0;mp['L']=1;mp['U']=2;mp['D']=3;
	queue<node> q;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",a[i]+1);
		for (j=1;j<=m;j++) {
			if (a[i][j]=='R') sx=i,sy=j;
			if (a[i][j]=='E') tx=i,ty=j;
		}
	}
	scanf("%s",s+1);
	int len=strlen(s+1);
	meminf(dp);
	dp[sx][sy][0]=0;
	q.push(node(sx,sy,0));
	while (!q.empty()) {
		node now=q.front();
//		cout << now.x << ' ' << now.y << ' ' << now.pos << " " <<
//		dp[now.x][now.y][now.pos] << endl;
		q.pop();
		//在pos处添加一个字符 
		for (i=0;i<4;i++) {
			int nowx=now.x+dir[i][0],nowy=now.y+dir[i][1];
			if (check(nowx,nowy))
			if (dp[nowx][nowy][now.pos]>dp[now.x][now.y][now.pos]+1) {
				dp[nowx][nowy][now.pos]=dp[now.x][now.y][now.pos]+1;
				q.push(node(nowx,nowy,now.pos));
			}
		} 
		if (now.pos<len) {
			//在pos处删除一个字符 
			if (dp[now.x][now.y][now.pos+1]>dp[now.x][now.y][now.pos]+1) {
				dp[now.x][now.y][now.pos+1]=dp[now.x][now.y][now.pos]+1;
				q.push(node(now.x,now.y,now.pos+1));
			}
			//按照原字符串pos位的字符行走 
			int nowx=now.x+dir[mp[s[now.pos+1]]][0],
			nowy=now.y+dir[mp[s[now.pos+1]]][1];
			if (!check(nowx,nowy)) nowx=now.x,nowy=now.y;
			if (dp[nowx][nowy][now.pos+1]>dp[now.x][now.y][now.pos]) {
				dp[nowx][nowy][now.pos+1]=dp[now.x][now.y][now.pos];
				q.push(node(nowx,nowy,now.pos+1));
			}
		}
	}
	int ans=inf;
	for (i=0;i<=len;i++) {
		ans=min(ans,dp[tx][ty][i]);
	}
	printf("%d\n",ans);
	return 0;
}

