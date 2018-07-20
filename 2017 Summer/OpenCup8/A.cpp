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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int last['z'+1],ne[maxn],nxt[maxn],ansl[maxn],st[maxn],pre[maxn];
char s[maxn];
char pr['z'+1];

int main() {
	scanf("%s",s+1);
	int len=strlen(s+1),i,j,q,l,r,ans;
	pr['e']='y';pr['a']='e';pr['s']='a';pr['y']='s';
	mem0(last);
	nxt[0]=ansl[0]=0;
	for (i=1;i<=len;i++) {
		if (s[i]=='e') {
			for (j=last['e']+1;j<=i;j++) ne[j]=i;
			nxt[i]=nxt[last['y']];
		} else if (s[i]=='y') {
			nxt[i]=nxt[last['s']]+1;
			st[i]=pre[pre[pre[i]]];
		}else nxt[i]=nxt[last[pr[s[i]]]];
		pre[i]=last[pr[s[i]]];
		ansl[i]=max(nxt[i],ansl[i-1]);
		last[s[i]]=i;
	}
	nxt[len+1]=nxt[len];
	for (j=last['e']+1;j<=len;j++) ne[j]=len+1;
	scanf("%d",&q);
	for (i=1;i<=q;i++) {
		scanf("%d%d",&l,&r);
		ans=ansl[r]-ansl[ne[l]];
		if (st[i]<l) ans--;
		printf("%d\n",ans);
	}
	return 0;
}

