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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
string a[maxn],b[maxn];
char s[maxn][maxn];

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for (j=1;j<=m;j++) b[j]="";
	for (i=1;i<=n;i++) {
		a[i]="";
		for (j=1;j<=m;j++) {
			scanf("%c",&s[i][j]);
			while(!(s[i][j]<='9'&&s[i][j]>='0')) scanf("%c",&s[i][j]);
			a[i]=a[i]+s[i][j];
			b[j]=b[j]+s[i][j];
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	string x,y,ans;
	x=y="";
	for (i=n;i>=1;i--) x=x+a[i];
	for (i=m;i>=1;i--) y=y+b[i];
	ans=x;
	for (i=1;i<=n;i++) {
		string now=x.substr(0,(n-i)*m)+x.substr((n-i+1)*m,n*m);
//		cout << now << endl;
		for (j=0;j<=m;j++) {
			string u=now;
			u=a[i].substr(j,m)+now+a[i].substr(0,j);
//			cout << u << endl;
			if (u>ans) ans=u;
		}
	}
	for (i=1;i<=m;i++) {
		string now=y.substr(0,(m-i)*n)+y.substr((m-i+1)*n,n*m);
		for (j=0;j<=n;j++) {
			string u=now;
			u=b[i].substr(j,n)+now+b[i].substr(0,j);
//			cout << u << endl;
			if (u>ans) ans=u;
		}
//		cout << b[i] << endl;
	}
	int f=0,len=ans.length();
	for (i=0;i<len;i++) {
		if (f==0&&ans[i]=='0') continue;
		f=1;
		cout << ans[i];
	}
	return 0;
}

