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
const int maxn=65,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ld a[maxn][maxn];
ld x[maxn],y[maxn],z[maxn];
map<string,int> mp;

ld sqr(ld x) {
	return x*x;
}

int main() {
	int cas,cntcas=0;
	scanf("%d",&cas);
	string s,t;
	cout << setiosflags(ios::fixed) << setprecision(0);
	while (cas--) {
		cntcas++;
		int n,m,k,i,j,p;
		mp.clear();
		scanf("%d",&n);getchar();
		for (i=1;i<=n;i++) {
			char c;
			scanf("%c",&c);
			s="";
			while (c!=' ') {
				s=s+c;
				scanf("%c",&c);
			}
			mp[s]=i;
			cin >> x[i] >> y[i] >> z[i];
			a[i][i]=0;
			for (j=1;j<i;j++) {
				a[i][j]=a[j][i]=sqrtl(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]));
			}
			getchar();
		}
		scanf("%d",&m);getchar(); 
		for (i=1;i<=m;i++) {
			getline(cin,s);
			int p=s.find(" ");
			t=s.substr(p+1,s.length());
			s=s.substr(0,p);
			int ss,tt;
			ss=mp[s];tt=mp[t];a[ss][tt]=0;
		}
		printf("Case %d:\n",cntcas);
        for (i=1;i<=n;i++)   
            for (j=1;j<=n;j++) {  
                if (i==j) continue;  
                for (k=1;k<=n;k++) {  
                    if (i==k||j==k) continue;  
                    a[j][k]=min(a[j][k],a[j][i]+a[i][k]);  
                }
            }
        int q;scanf("%d",&q);getchar();
        for (i=1;i<=q;i++) {
        	getline(cin,s);
			int p=s.find(" ");
			t=s.substr(p+1,s.length());
			s=s.substr(0,p);
			int ss,tt;
			printf("The distance from ");
			cout << s;
			printf(" to ");cout << t;
			ss=mp[s];tt=mp[t];
			printf(" is ");
			cout << a[ss][tt];
			printf(" parsecs.\n");
        }
	}
	return 0;
}
