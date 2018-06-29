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
set<int> st;
char s[maxn],t[maxn],pos[maxn],seq[maxn];
bool visit[maxn];
vector<int> vs[35],vt[35],v[maxn];

int shuffle(int pos,int n) {
	if (pos%2) return (pos+1)/2; else return pos/2+n/2;
}

int main() {
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n=strlen(s+1)-2,m;
	for (int i=1;i<=n+2;i++) {
		vs[s[i]-'a'].pb(i);
		vt[t[i]-'a'].pb(i);
	}
	for (int i=1;i<=n;i++) {
		if (visit[i]) continue;
		int now=i+1;
		pos[now]=1;seq[now]=++m;
		v[m].pb(now);
		now=shuffle(now,n);
		while (now!=i+1) {
			pos[now]=1;seq[now]=++m;
			v[m].pb(now);
			now=shuffle(now,n);
		}
	}
	for (int i=1;i<=n;i++) st.insert(i);
	for (int i=1;i<=n;i++) {
		int size=vt[t[i]-'a'].size(),sz=v[seq[i]].size();
		for (int j=0;j<sz;j++) {
			if (s[v[seq[i][pos[j]]]==t[i]) continue;			
			st.erase(v[seq[i]][pos[j]]]);
		}
	}
	if (st.size()>0) printf("%d",*st.begin()); else printf("-1\n");
	return 0;
}
