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

int main() {
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	int n,m,ax,ay,bx,by;
	scanf("%d%d%d%d%d%d",&n,&m,&ax,&ay,&bx,&by);
	if (ay!=by) printf("%d %d %d %d",0,ay,n,by); 
	    else printf("%d %d %d %d",ax,0,bx,m); 
	return 0;
}

