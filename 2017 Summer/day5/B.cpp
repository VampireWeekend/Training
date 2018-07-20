#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=8005;
int a[maxn],son[maxn];
vector<int> v[maxn];
priority_queue<int,vector<int>,greater<int> > q;

int main() {
	int n,i,sum,j,min;
//	n=1;
//	while (scanf("%d",&a[n])!=EOF) n++;
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d",&a[i]);
	mem(son);
	for (i=1;i<n;i++) {
		son[a[i]]++;
	}
	for (i=1;i<=n;i++) {
		if (!son[i]) q.push(i);
	}
	for (i=1;i<n;i++) {
		int now=q.top();
		v[a[i]].push_back(now);
		v[now].push_back(a[i]);
		q.pop();
		son[a[i]]--;
		if (!son[a[i]]) q.push(a[i]);
	}
	for (i=1;i<=n;i++) {
		sort(v[i].begin(),v[i].end());
		int size=v[i].size();
		printf("%d:",i);
		for (j=0;j<size;j++) {
			printf(" %d",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
