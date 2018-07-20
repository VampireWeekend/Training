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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=3e7;   
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];
int next[maxn];
int lena,lenb;

void buildnext(char s[]) {
	int j=0;
	next[0]=next[1]=0;
	for (int i=1;i<lenb;i++) {
		while (j>0&&s[i]!=s[j])
		    j=next[j];
		if (s[i]==s[j]) j++;
		next[i+1]=j;
	}
}

int check(int len) {
	int j=0,ans=0;
	for (int i=0;i<lena;i++) {
	    while (j>0&&t[j]!=s[i]) 
	   	    j=next[j];
	   	if (t[j]==s[i]) j++;
	   	if (j==len) {
	   		ans++;
	   		j=next[j];
	   	}
	}
	return ans;
}

int main() {
	int i,k;
	cin.getline(s,maxn);
	cin.getline(t,maxn);
	scanf("%d",&k);
	lena=strlen(s);lenb=strlen(t);
	buildnext(t);
	int l,r,ans=-1;
	l=1,r=lenb;
	while (l<=r) {
		int mid=(l+r)/2;
		int p=check(mid);
		if (p>=k) ans=mid,l=mid+1; else r=mid-1;
	}
	if (ans==-1) printf("IMPOSSIBLE"); else
		for (i=0;i<ans;i++) printf("%c",t[i]);
	return 0;
}
