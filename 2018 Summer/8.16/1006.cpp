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
const int maxn=100005,maxk=26,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn];
int q[maxn],path[maxn];
bool vis[maxn];
int num;

struct node{
	int fail,next[maxk]; 
	int mind;
	void init() {
		fail=-1;
		for (int i=0;i<maxk;i++) next[i]=-1;
		mind=inf;
	}
};
node a[maxn];

void insert(string s,int root,int len) {
	int now=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=s[i]-'a';
		if (a[now].next[pos]==-1) {
	    	a[now].next[pos]=++num;
	    	a[num].init();
    	}
    	now=a[now].next[pos];
		a[now].mind=min(a[now].mind,len-i-1);
	}
}
//²¹È«trieÍ¼
void buildfail(int root) {
	int p=root;
	int front=0,tail=0,i;
	for (i=0;i<maxk;i++) {
		if (a[p].next[i]!=-1) {
			a[a[p].next[i]].fail=root;
			q[tail++]=a[p].next[i];
		} else a[p].next[i]=root;
	}
	while (front<tail) {
		p=q[front];
		for (i=0;i<maxk;i++) {
			if (a[p].next[i]==-1) 
			    a[p].next[i]=a[a[p].fail].next[i];
			else {
				int x=a[p].fail;
				while (x!=-1) {
					if (a[x].next[i]!=-1) {
						a[a[p].next[i]].fail=a[x].next[i];
						break;
					}
					x=a[x].fail;
				}
				q[tail++]=a[p].next[i];
			}
		}
		front++;
	}
}

void bfs() {
	queue<int> q;
	q.push(0);vis[0]=1;
	while (!q.empty()) {
		int now=q.front();q.pop();
		a[now].mind=min(a[now].mind,a[a[now].fail].mind);
		for (int i=0;i<maxk;i++) {
            if (!vis[a[now].next[i]]) {
				vis[a[now].next[i]]=1;
				q.push(a[now].next[i]);
			}
        }
	}
}

int main() {
	int n,i,len;
	scanf("%d",&n);
	num=0;a[0].init();
	for (int i=1;i<=n;i++) {
		scanf("%s",s);
		len=strlen(s);
        a[0].mind=min(a[0].mind,len);
		insert(s,0,len);
	}
    a[0].fail=0;
    buildfail(0);
    bfs();
	scanf("%s",s);
	n=strlen(s);
	path[0]=0;
	int m=0,now=0;
	printf("%d\n",a[now].mind);
	for (int i=0;i<n;i++) {
		if (s[i]=='-') {
			m=max(m-1,0);
			now=path[m];
		} else {
			now=a[now].next[s[i]-'a'];
			path[++m]=now;
		}
 //       cout << now << ' ' << a[now].fail << ' ';
		printf("%d\n",a[now].mind);
	}
	return 0;
}