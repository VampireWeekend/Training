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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=15,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db eps=1e-3;
db a[maxn],c[maxn][maxn],r[maxn][maxn];

bool gauss(int size) {    
    int i,j,k;    
    for (i=0;i<size;i++) {    
        k=i;    
        for (j=i+1;j<size;j++) 
            if (fabs(r[j][i])>fabs(r[k][i])) k=j;        
        if (fabs(r[k][i])<eps) return false;
        for (j=i;j<=size;j++)   
            swap(r[k][j],r[i][j]);  
        db t=r[i][i];  
        for (j=i;j<=size;j++)   
            r[i][j]/=t;  
        for (j=0;j<size;j++) {    
            if (i==j) continue;    
            db t=r[j][i];   
            for (k=i;k<=size;k++) {    
                r[j][k]-=t*r[i][k];    
            }
        }
    }
    return true;  
}

int main() {
	int i,j,k,n,ans;
	scanf("%d",&n);
	for (i=0;i<=7;i++) {
		c[i][0]=1.0;
		for (j=1;j<=5;j++) {
			c[i][j]=c[i][j-1]*(db)i;
		}
	}
	while (n) {
		ans=-1;
		for (i=0;i<n+3;i++) {
			scanf("%lf",&a[i]);
		}
		for (i=0;i<n+3;i++) {
			int cnt=-1,last=-1;
			for (j=0;j<n+3;j++) {
				if (i==j) continue;
				cnt++;
				if (cnt==n+1) {
					last=j;break;
				}
				r[cnt][n+1]=a[j];
				for (k=0;k<n+1;k++) {
					r[cnt][k]=c[j][k];
				}
			}
			if (gauss(n+1)) {
				db h=0;
				for (k=0;k<n+1;k++) {
					h+=r[k][n+1]*c[last][k];
				}
				if (fabs(h-a[last])<eps) {
					ans=i;break;
				}
			}
		}
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
