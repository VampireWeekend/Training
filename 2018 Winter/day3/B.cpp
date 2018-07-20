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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
bool f[135];
char c[maxn],s[maxn];

int main() {
	scanf("%s",c);
	int len=strlen(c),i,n,j,k;
	mem0(f);
	map<char,int> mp;
	for (i=0;i<len;i++) {
		mp[c[i]]=1;
	}
	scanf("%s",s);
	scanf("%d",&n);
	getchar();
	int pos=-1;
	int lens=strlen(s);
	for (j=0;j<lens;j++) 
		if (s[j]=='*') pos=j;
	for (i=1;i<=n;i++) {
		int flag=1;
		scanf("%s",c);
		len=strlen(c);
		if (pos==-1&&len==lens) {
		for (j=0;j<len;j++) {
			if (s[j]=='?') {
				if (!mp[c[j]]) flag=0;
			} else {
				if (s[j]!=c[j]) flag=0;
			}
			if (flag==0) break;
		}} else if (pos!=-1&&len-lens>=-1) {
			int p=len-lens;
			for (j=0;j<lens;j++) {
				if (j==pos) {
					for (k=j;k<=j+p;k++) {
						if (mp[c[k]]) flag=0;
					}
				} else if (j<pos) {
	           		if (s[j]=='?') {
		        		if (!mp[c[j]]) flag=0;
		        	} else {
		         		if (s[j]!=c[j]) flag=0;
		         	}
				} else {
					if (s[j]=='?') {
		        		if (!mp[c[j+p]]) flag=0;
		        	} else {
		         		if (s[j]!=c[j+p]) flag=0;
		         	}
				}
				if (flag==0) break;
			}
		} else flag=0;
		if (flag) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
