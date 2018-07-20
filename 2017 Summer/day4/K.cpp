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

struct Node {
	string name;
	int depth,num;
	int son[105],hash[105];
};

bool cmp(Node x,Node y) {
	return x.depth<y.depth || x.depth<y.depth&&x.name<y.name;
}

int main() {
	char c;
	while(scanf("%c",&c)!=EOF) {
		Node node[205];
		map<string,int> my;
		string s="";
		int n=1,i,d=0;
		string pre="";
		c='@';
		while (c!='\n') {
			scanf("%c",&c);
			if (c=='\n') break;
			if (c!='/') {
				s=s+c;
			} else {
				d++;
				int son=my[s];
				if (son==0) {
					my[s]=++n;
					son=n;
					node[n].name=s;
					node[n].num=0;
					node[n].depth=d;
					for (i=1;i<=100;i++) node[n].hash[i]=0;
				}
				if (d!=1) {
					int father=my[pre];
					if (node[father].hash[son]!=0) {
						node[father].num++;
						node[father].hash[son]=1;
						node[father].son[node[father].num]=son;
					}
				} else {
					node[1].num++;
					node[1].hash[son]=1;
					node[1].son[node[1].num]=son;
				}
				pre=s;
				s="";
			}
		}
		scanf("%c",&c);
		if (c!='0') continue;
		
		sort(node+1,node+n+1,cmp);
		
	}
	return 0;
}
