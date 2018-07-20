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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1305,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int match[maxn],visit[maxn];
char s[maxn];
int n,m;

vector<int> v[maxn];

int num(int i,int j) {
	return (i-1)*m+j;
}

bool hungary(int now) {
	int size=v[now].size();
	int i,to;
	for (i=0;i<size;i++) {
		to=v[now][i];
		if (!visit[to]) {
			visit[to]=true;
			if (!match[to]||hungary(match[to])) {
				match[to]=now;
				match[now]=to;
				return true;
			}
		}
	}
	return false;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d%d",&n,&m);
    int q=n*m;
    for (i=1;i<=n;i++) {
    	scanf("%s",s+1); 
    	for (j=1;j<=m;j++) {
    		if (s[j]=='*') {
    			q++;
    			for (k=1;k<=n;k++) 
    				if (k!=i) {
    					v[q].push_back(num(k,j));
    					v[num(k,j)].push_back(q);
    				} 	
    			for (k=1;k<=m;k++) 
    				if (k!=j) {
    					v[q].push_back(num(i,k));
    					v[num(i,k)].push_back(q);
    				}
    		}
    	}
    }
    mem0(match);
    int ans=0;
    for (i=1;i<=q;i++) {
    	if (!match[i]) {
    		mem0(visit);
    		if (hungary(i)) ans++;
    	}
    }
    printf("%d\n",ans); 
	return 0;
}
