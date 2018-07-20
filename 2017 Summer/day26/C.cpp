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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f; 
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
char s[maxn][105];
int step[maxn],pre[maxn],move[maxn],lca[maxn];
int a[15][85];

ull seed1=26,seed2=1e9+7;  
  
ull hash(char *s,int len) {  
    ull sum=seed1;  
    for (int i=0;i<len;i++) {  
        sum*=seed2;  
        sum+=s[i];  
    }
    return sum;  
}  

int main() {
	freopen("general.in","r",stdin);
	freopen("general.out","w",stdout);
	map<ull,int> mp;
	map<ull,int> mp2;
	int n,m,i,j,h,t;
	ull f;
	scanf("%d%d",&n,&m);
	scanf("%s",s[1]);
	scanf("%s",s[2]);
	f=hash(s[1],n);
	mp[f]=1;step[1]=0;
	mp2[f=hash(s[2],n)]=2;step[2]=0;
	pre[2]=pre[1]=move[2]=move[1]=-1;
	h=0;t=2;lca[1]=1;lca[2]=2;
	for (i=1;i<=m;i++) {
		scanf("%d",&a[i][0]);
		for (j=1;j<=a[i][0];j++) {
			scanf("%d",&a[i][j]);
			a[i][j]--;
		}
	}
	ll ans=llinf;
	while (h<t) {
		h++;
	/*	cout << h << " ";
		for (j=0;j<n;j++) cout << s[h][j];
		cout << "   " << pre[h] << " " << move[h] << " " << lca[h] << endl;*/
		if (step[h]>=5) continue;
		for (i=1;i<=m;i++) {
			memcpy(s[t+1],s[h],sizeof(s[t+1]));
			if (lca[h]==1) {
				char c=s[t+1][a[i][a[i][0]]];
		    	for (j=a[i][0];j>=2;j--) {
		    		s[t+1][a[i][j]]=s[t+1][a[i][j-1]];
		    	}
		    	s[t+1][a[i][1]]=c;
			} else {
				char c=s[t+1][a[i][1]];
		    	for (j=1;j<a[i][0];j++) {
		    		s[t+1][a[i][j]]=s[t+1][a[i][j+1]];
		    	}
		    	s[t+1][a[i][a[i][0]]]=c;
			}
			f=hash(s[t+1],n);
			int pos;
			if (lca[h]==1) pos=mp2[f]; else pos=mp[f];
//			for (j=0;j<n;j++) cout << s[t][j];
//				cout << '\n';
			if (!pos) {
				t++;
				if (lca[h]==1) mp[f]=t; else mp2[f]=t;
				step[t]=step[h]+1;
				move[t]=i;
				pre[t]=h;
				lca[t]=lca[h];
			} else {
				int nowx,nowy=h;
				nowx=pos;
				ll state=0;
				if (lca[nowx]==lca[nowy]) continue;
				stack<int> sx,sy;
				queue<int> qx,qy; 
				while (pre[nowx]!=-1) {
					qx.push(move[nowx]);
					sx.push(move[nowx]);
					nowx=pre[nowx];
				}
				while (pre[nowy]!=-1) {
					qy.push(move[nowy]);
					sy.push(move[nowy]);
					nowy=pre[nowy];
				}
				if (nowx==1) {
					while (!sx.empty()) {
						state*=11;
						state+=(ll)sx.top();
						sx.pop();
					}
					state*=11;
					state+=(ll)i;
					while (!qy.empty()) {
						state*=11;
						state+=(ll)qy.front();
						qy.pop();
					}
				} else {
					while (!sy.empty()) {
						state*=11;
						state+=(ll)sy.top();
						sy.pop();
					}
					state*=11;
					state+=(ll)i;
					while (!qx.empty()) {
						state*=11;
						state+=(ll)qx.front();
						qx.pop();
					}
				}
				ans=min(ans,state);
			}
		}
	}
	if (ans==llinf) printf("IMPOSSIBLE\n"); else {
		stack<int> o;
		while (ans) {
			o.push(ans%11);
			ans/=11;
		}
		while (!o.empty()) {
			printf("%d ",o.top());
			o.pop();
		}
	}
	return 0;
}

