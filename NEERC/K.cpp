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
int j,k,l,ans;

void judge(int a,int b,int c,int i) {
	if ((a>j)||(a==j&&b>k)||(a==j&&b==k&&c>l)) 
	    j=a,k=b,l=c,ans=i;
}

int main() {
//	freopen("king.in","r",stdin);
//	freopen("king.out","w",stdout);
	int d,m,y,n,i,a,b,c;
	ans=0;
	scanf("%d%d%d",&d,&m,&y);
	scanf("%d",&n);
	j=k=l=-1;
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&c,&b,&a);
		if (y-a>18) judge(a,b,c,i); else 
		    if (y-a==18) {
		    	if (b<m||(b==m&&c<=d)) judge(a,b,c,i);
		    }
	}
	if (j==-1) ans=-1;
	printf("%d\n",ans); 
	return 0;
}

