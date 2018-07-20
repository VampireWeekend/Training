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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535898L;
char s[maxn];
bool p[128];
vector<char> v;

int main() {
	int n,k,len,i,j;
	scanf("%s",s+1);
	len=strlen(s+1);
	scanf("%d",&k);
	int cnt=0,l=0,odd=0,even=0,r;
	mem0(p);
	for (i=1;i<=len;i++) {
		if (s[i]=='?')  {
			cnt++;
			if (i%2) even++; else odd++;
		}else
		if (!p[s[i]]) l++,p[s[i]]=1;
	}
	if (l+cnt<k) {
		cout << -1;
		return 0;
	}
	char c;
	k-=l;
	if (k<=0) {
		for (i=1;i<=len;i++) {
			if (s[i]=='?') {
				if (i%2) printf("z"); else printf("a");
			} else printf("%c",s[i]);
		}
	} else {
		for (c='a';c<='z';c++) 
	    	if (!p[c]) v.push_back(c);
     	int size=v.size();
     	queue<char> q;
     	queue<char> p;
     	l=0;r=size-1;
     	for (i=1;i<=k;i++) 
     		if (abs('a'-v[l])<abs('z'-v[r])&&l<even) {
     			p.push(v[l]);
     			l++;
     		} else {
     			q.push(v[r]);
     			r--;
     		}
     	
     	for (i=1;i<=len;i++) 
     		if (s[i]=='?') {
		    	if (i%2) {
			   		if (!q.empty()) {
		    			printf("%c",q.front());
		    			q.pop();
		    		} else printf("z");
		    	} else {
		    		if (!p.empty()) {
		    			printf("%c",p.front());
		    			p.pop();
		    		} else printf("a");
		    	}
		   	} else printf("%c",s[i]);
	}
	return 0;
}
