#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
const ll mod=1e9+7;
char s[maxn],k[maxn],s1[maxn],k1[maxn];
int next[maxn];
ll match[maxn];

void buildnext(char s[]) {
	int len=strlen(s);
	int j=0;
	next[0]=next[1]=0;
	for (int i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=next[j];
		if (s[i]==s[j]) j++;
		next[i+1]=j;
	}
}

int main() {
	ll n,i,t,j;
	scanf("%lld",&n);
	for (t=1;t<=n;t++) {
		ll ans=0;
		scanf("%s",s1);
		scanf("%s",k1);
		int lenk=strlen(k1),lens=strlen(s1);
		for (j=0;j<lenk;j++) {
			k[j]=k1[lenk-j-1];
		}
		for (j=0;j<lens;j++) {
			s[j]=s1[lens-j-1];
		}
		ans=0;
		buildnext(k);
		j=0;
	    for (i=0;i<lens;i++) {
	    	while (j>0&&k[j]!=s[i]) 
	    	    j=next[j];
	    	if (k[j]==s[i]) j++;
	    	match[i]=j;
	    	if (i==0) ans+=j; else {
	    		if (match[i]==match[i-1]+1) ans+=j; else 
	    		    ans+=match[i]*(match[i]+1)/2;
	    	}
	    	ans%=mod;
	    	cout << ans << endl;
	    }
	    printf("%lld\n",ans);
	}
	return 0;
}
