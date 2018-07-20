#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0x3f,sizeof(a))
using namespace std;
const int maxn=20005;
typedef long long ll;
int dist[maxn],mark[maxn];

struct Edge {
	int from,to,dist,cost;
};

struct node {
	int id,dist,cost;
	node(int id,int dist,int cost):id(id),dist(dist),cost(cost){}
	bool operator <(const node &x)const {
		return dist>x.dist || (dist==x.dist&&cost>x.cost);
	}
};

priority_queue<node> pq;

void dijestra(int s) {
	mem(dist);
	dist[s]=0;
	
}

int main() {
	
	return 0;
} 
