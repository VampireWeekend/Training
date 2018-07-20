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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[maxn][maxn];
string s;
int lenb[maxn],p[100005],mod[15]; 
bool z[1000005];

int main() {
	int cas,pppp=0;
	scanf("%d",&cas);
	mod[0]=1;
	for (int i=1;i<=8;i++) mod[i]=mod[i-1]*10;
	while (cas--) {
		pppp++;
		int i,j,l,w,n,len,num=0,maxlen=1,ans=0;
		scanf("%d%d",&n,&w);
		getchar();
		mem0(z);
		for (i=1;i<=n;i++) {
			getline(cin,s);
			len=s.length();
			int ns=0,cnt=0,flag=0;
			mem0(lenb);
			for (j=0;j<len;j++) {
				if (s[j]>='0'&&s[j]<='9') {
					if (!flag) ns++,flag=1;
					a[ns][lenb[ns]++]=s[j]-'0';
				} else if (flag) {
					flag=0;
				}
			}
			int u;
			for (len=maxlen;len<=maxlen+2;len++) {
			for (j=1;j<=ns;j++) {
				int now=0;
				for (l=0;l<len-1;l++) {
					now=now*10+a[j][l];
				}
				for (l=len-1;l<lenb[j];l++) {
					now=(now*10+a[j][l])%mod[len];
					if (now>num) p[++cnt]=now; 
				}
			}
		    }
		    sort(p+1,p+cnt+1);
		    j=1;
		    while (p[j]==num+1&&j<=cnt) {
		    	z[p[j]]=1;num++;
		    	while (z[num+1]) num++;
		    	ans=max(ans,p[j]);
		    	if (num>=mod[maxlen]-1) maxlen++;
		    	j++;
		    	while (p[j]<=num&&j<=cnt) j++;
		    }
		    while (p[j]<=num+w&&j<=cnt) {
		    	z[p[j]]=1;
		    	ans=max(ans,p[j]);
		    	j++;
		    }
		}
		printf("Case %d: %d %d\n",pppp,num,ans);
	}
	return 0;
}
