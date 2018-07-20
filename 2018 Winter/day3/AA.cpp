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
#include <sstream>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],p[55];
int num=1;

struct Tree{   
    int son[10];   
    void init() {  
        for (int i=0;i<10;i++) son[i]=-1;  
    }
};  
Tree tree[20000005];   
  
void insert(int now,int n,ll val) {  
    if (n==-1) return;  
    ll pos=(val/p[n])%10;
    if (tree[now].son[pos]==-1) {  
        tree[now].son[pos]=num++; 
        tree[tree[now].son[pos]].init();
    }
    insert(tree[now].son[pos],n-1,val);  
}  
  
ll findmax(int now,int n,ll val) {
	if (n==-1) return 0;
	ll pos=(val/p[n])%10,ans=0;
	for (int i=9-pos;i>=0;i--)
		if (tree[now].son[i]!=-1) 
				return ((i+pos)%10)*p[n]+findmax(tree[now].son[i],n-1,val);
	for (int i=9;i>9-pos;i--)
		if (tree[now].son[i]!=-1) 
				return ((i+pos)%10)*p[n]+findmax(tree[now].son[i],n-1,val);
}

ll findmin(int now,int n,ll val) {
	if (n==-1) return 0;
	ll pos=(val/p[n])%10,ans=0;
	for (int i=10-pos;i<=9;i++)
		if (tree[now].son[i]!=-1) 
				return ((i+pos)%10)*p[n]+findmin(tree[now].son[i],n-1,val);
	for (int i=0;i<10-pos;i++)
		if (tree[now].son[i]!=-1) 
				return ((i+pos)%10)*p[n]+findmin(tree[now].son[i],n-1,val);
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	p[0]=1;
	for (i=1;i<=18;i++) p[i]=p[i-1]*10;
	tree[0].init();num=1;
	ll mn,mx;mn=llinf;mx=-llinf;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		if (i!=1) {
			mn=min(mn,findmin(0,18,a[i]));
			if (mn==3144) {
				printf("%d\n",i);
			}
			mx=max(mx,findmax(0,18,a[i]));
		}
		insert(0,18,a[i]);
	}
	printf("%I64d %I64d",mn,mx);
	return 0;
}

