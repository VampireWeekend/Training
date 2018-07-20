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
char s[maxn];
string name[maxn],word[maxn];
bool f[maxn];
vector<int> v[maxn];
stack<int> st;

void dfs(int now) {
	for (int i=v[now].size()-1;i>=1;i--) {
		int to=v[now][i];
		if (!f[to]) {
			dfs(to);
		}
	}
	if (!f[now]) {
		st.push(now);
		f[now]=1;
	}
}

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int n,i,len;
	scanf("%d",&n);
	getchar();
	map<string,int> mp;
	string b;
	mem0(f);
	for (i=1;i<=n;i++) {
		scanf("%s",s);
		cin >> name[i];
		mp[name[i]]=i;
		scanf("%s",s);
		v[i].push_back(i);
		while (s[0]!='=') {
			cin >> b;
			v[i].push_back(mp[b]);
			scanf("%s",s);
		}
		getchar();
		getline(cin,word[i]);
	}
	cin >> b;
	int p=mp[b];
	dfs(p);
	while (!st.empty()) {
		int now=st.top();
		st.pop();
		cout << word[now] << ' '; 
	}
	return 0;
}

