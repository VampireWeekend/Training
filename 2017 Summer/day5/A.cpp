#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;

struct node{
	ll val;
	char name[105];
	bool final;
	struct node *nxt[10]; 
	void init() {
		for (int i=0;i<10;i++) nxt[i]=NULL;
		final=0;  //???
	}
};

void insert(node *now,ll l,ll r) {
	
}

void dfs(node *now,ll sum) {
	
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		node *root;
		root->init();
		ll l,r;
		int i;
		char c[25];
		string name;
		for (i=1;i<=n;i++) {
			scanf("%lld%s%lld",&l,c,&r);
	    	cin >> name;
	      	int x=l,y=r,len=0;
	    	while (x&&y) {
	    		x/=10;y/=10;
	    		len++;
			}
			while (len--) {
				x*=10;
			}
			r+=x;
			insert(root,l,r);
		}
		dfs()
	}
	return 0;
}
