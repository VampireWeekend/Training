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
#define N 300
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=305,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
using namespace std;
bool ax[1000][1000];

int main()
{
    int a,b,c,d,res=0;
    mem0(ax);
    for(a=0;a<N;a++){
        for(b=0;b<N;b++){
            for(c=0;c<N;c++){
                for(d=0;d<N;d++){
                    if((a*a+b*b)*(c*c+d*d)>20000)break;
                    if (abs(a)+abs(b)==1) continue;
					if (abs(c)+abs(d)==1) continue;
                    ax[a*c+b*d][abs(a*d-b*c)]=1;
                    res++;
                }
                if((a*a+b*b)*(c*c)>20000)break;
            }
            if((a*a+b*b)>20000)break;
        }
    }
    for(a=0;a>=-N;a--){
        for(b=0;b>=-N;b--){
            for(c=0;c>=-N;c--){
                for(d=0;d>=-N;d--){
                    if((a*a+b*b)*(c*c+d*d)>20000)break;
                    if (abs(a)+abs(b)==1) continue;
					if (abs(c)+abs(d)==1) continue;
                    ax[a*c+b*d][abs(a*d-b*c)]=1;
                    res++;
                }
                if((a*a+b*b)*(c*c)>20000)break;
            }
            if((a*a+b*b)>20000)break;
        }
    }
    int n,i,j,x,y;
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
    	scanf("%d%d",&x,&y);
    	if (x<0) x=-x;
    	if (y<0) y=-y;
    	if (x*x+y*y<=1) printf("C\n"); else
    	if (ax[x][y]) printf("C\n"); else printf("P\n");
    }
    return 0;
}
