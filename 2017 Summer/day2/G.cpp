#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
const int maxn=10005;
using namespace std;
int head[maxn],num;
struct Edge{
	int pre,from,to;
};
Edge edge[maxn];

void addedge(int from,int to) {
	edge[num]=(Edge){head[from],from,to};
	head[from]=num;
	num++;
}

int dfs(int now) {
	if (head[now]==-1) {
		return 1;
	} else {
		int ans,k;
		ans=dfs(edge[head[now]].to);
		if (edge[head[now]].pre!=-1) {
			k=dfs(edge[edge[head[now]].pre].to);
			if (ans==k) return k+1; else return max(ans,k);
		} else return ans;
	}
}

int main() {
	int n,i,x,ans;
	while (scanf("%d",&n)!=EOF) {
		num=0;
		memset(head,-1,sizeof(head));
		for (i=2;i<=n;i++) {
			scanf("%d",&x);
			addedge(x,i);
		}
		ans=dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
