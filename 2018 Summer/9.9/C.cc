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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll sum[362888][9],cnt[362888];
ll a[5][5];
ll p[50],po[50],path[50],q[50],cal[50];
bool v[50];
char s[5][5];
ll m=0;

int myhash(int step) {
	int hsh=0;
	for (int i=1;i<step;i++) {
		if (!cal[i]) continue;
		int sma=0;
		for (int j=i+1;j<step;j++) {
			if (path[j]<path[i]) sma++;
		}
		hsh+=sma*po[step-i-1];
	}
	return hsh;
}

void dfs(int x,int y,int step) {
	if (x==4) {
		int hsh=myhash(step);
		cnt[hsh]++;
		for (int i=1;i<=3;i++) {
			int pp=0;
			for (int j=1;j<=3;j++)
				pp+=a[i][j];
			sum[hsh][i]+=q[pp];
		}
		for (int i=1;i<=3;i++) {
			int pp=0;
			for (int j=1;j<=3;j++)
				pp+=a[j][i];
			sum[hsh][i+3]+=q[pp];
		}
		int pp=a[1][1]+a[2][2]+a[3][3];
		sum[hsh][7]+=q[pp];
		pp=a[1][3]+a[2][2]+a[3][1];sum[hsh][8]+=q[pp];
		return;
	}
	int nx,ny;
	if (y==3) nx=x+1,ny=1; else nx=x,ny=y+1;
	if (s[x][y]>='0'&&s[x][y]<='9') {
		a[x][y]=s[x][y]-'0';
		dfs(nx,ny,step);
		return;
	}
	int ns=step;
	for (int i=1;i<=m;i++) {
		if (v[i]) continue;
		v[i]=1;a[x][y]=p[i];
		path[step]=i,ns=step+1;
		if (s[x][y]=='*') cal[step]=1;
		dfs(nx,ny,ns);
		v[i]=0;
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	q[6]=10000;q[7]=36;q[8]=720;q[9]=360;q[10]=80;
    q[11]=252;q[12]=108;q[13]=72;q[14]=54;q[15]=180;
    q[16]=72;q[17]=180;q[18]=119;q[19]=36;q[20]=360;
    q[21]=1080;q[22]=144;q[23]=1800;q[24]=3600;
	po[0]=1;
	for (ll i=1;i<=9;i++) po[i]=po[i-1]*i;
	while (cas--) {
		mem0(p);
		for (int i=1;i<=3;i++) {
			scanf("%s",s[i]+1);
			for (int j=1;j<=3;j++)
				if (s[i][j]>='0'&&s[i][j]<='9') p[s[i][j]-'0']=1;
		}
		m=0;
		for (int i=1;i<=9;i++) {
			if (p[i]==0) p[++m]=i;
			v[i]=0;
		}
		mem0(cnt);
		mem0(sum);
		dfs(1,1,1);
		ll ans,tot;
		ans=tot=0;
		for (int i=0;i<362880;i++) {
			if (!cnt[i]) continue;
			ll be=0;
			for (int j=1;j<=8;j++) {
				be=max(be,sum[i][j]);
			}
			ans+=be;
			tot+=cnt[i];
		}
		db ol=(db)ans/(db)tot;
		printf("%.7lf\n",ol);
	}
	return 0;
}
