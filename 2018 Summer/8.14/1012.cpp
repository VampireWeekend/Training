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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int sums[maxn],sumt[maxn];
int nexts[maxn],nextt[maxn];
char s[maxn],t[maxn],a[maxn];

void buildnext(char s[]) {
	int len=strlen(s);
	int j=0;
	nexts[0]=nexts[1]=0;
	for (int i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=nexts[j];
		if (s[i]==s[j]) j++;
		nexts[i+1]=j;
	}
}

void buildnextt(char s[]) {
	int len=strlen(s);
	int j=0;
	nextt[0]=nextt[1]=0;
	for (int i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=nextt[j];
		if (s[i]==s[j]) j++;
		nextt[i+1]=j;
	}
}

int main() {
    int cas;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%s%s%s",a,s,t);
		buildnext(s);
		buildnextt(t);
		int lena=strlen(a),lens,lent,i,j;
		lens=strlen(s);lent=strlen(t);
		for (i=0;i<=lena;i++) {
			sums[i]=sumt[i]=0;
		}
        j=0;
		for (i=0;i<lena;i++) {
	    	while (j>0&&s[j]!=a[i]) 
	     	   j=nexts[j];
			if (s[j]==a[i]) j++;
			if (j==lens) {
				sums[i+1]++;j=nexts[j];
			}
		}
        j=0;
		for (i=0;i<lena;i++) {
	    	while (j>0&&t[j]!=a[i]) 
	     	   j=nextt[j];
			if (t[j]==a[i]) j++;
			if (j==lent) {
				sumt[i+1]++;j=nextt[j];
			}
		}
		for (i=1;i<=lena;i++) {
			sums[i]+=sums[i-1];
			sumt[i]+=sumt[i-1];
		}
		int flag=0;
		for (i=1;i<=lena;i++) {
			if (sums[i]>sums[i-1]) {
				if (sumt[i-lens]>0) flag=1;
				if (sumt[lena]-sumt[i+lent-1]>0&&lena>i+lent-1) flag=1;
			}
		}
		if (flag) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
