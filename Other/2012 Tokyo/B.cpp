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
int r1[maxn][maxn];
db r[maxn][maxn];
int v[maxn];
char s[maxn];

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
    for (i=0;i<size;i++) v[i]=round(r[i][size]);
    return true;  
}

int main() {
	int n,m,i,j,k,x,y,z;
	scanf("%d%d",&n,&m);
	while (n!=0||m!=0) {
		mem0(r);
		int cnt=-1;
		x=y=z=0;
		for (i=1;i<=n;i++) {
			scanf("%s",s);
			if (cnt>=2) continue;
			int len=strlen(s);
			j=0;
			while (s[j]=='.'&&j<len) j++;
			if (j!=0) {
				int flag=0;
				for (k=0;k<=cnt;k++) {
					if (x<r1[k][0]) {
						if (r1[k][0]%x==0&&r1[k][1]%y==0
						&&r1[k][2]%z==0&&r1[k][3]%j==0) {
							flag=1;break;
						}
					}
				}
				if (!flag) {
					cnt++;
					r1[cnt][3]=j;
					r1[cnt][0]=x;r1[cnt][1]=y;r1[cnt][2]=z;
				}
			}
			for (;j<len;j++) {
				if (s[j]=='(') x++;
				if (s[j]=='[') y++;
				if (s[j]=='{') z++;
				if (s[j]==')') x--;
				if (s[j]==']') y--;
				if (s[j]=='}') z--;
			}
		}
		if (cnt==2) {
			for (i=0;i<=2;i++) {
				for (j=0;j<=3;j++) r[i][j]=r1[i][j];
			}
			gauss(3);
		}
		else if (cnt==0) 
			for (i=0;i<=3;i++) v[i]=r1[0][i];
		printf("0\n");
		x=y=z=0;
		for (i=1;i<m;i++) {
			scanf("%s",s);
			int len=strlen(s);
			for (j=0;j<len;j++) {
				if (s[j]=='(') x++;
				if (s[j]=='[') y++;
				if (s[j]=='{') z++;
				if (s[j]==')') x--;
				if (s[j]==']') y--;
				if (s[j]=='}') z--;
			}
			int ans;
			if (cnt==2) {
				ans=x*v[0]+y*v[1]+z*v[2];
				printf("%d\n",ans);
			} else if (cnt==1) {
				r[0][0]=r1[0][0];r[0][1]=r1[1][0];r[0][2]=x;
				r[1][0]=r1[0][1];r[1][1]=r1[1][1];r[1][2]=y;
				if (!gauss(2)) {
					r[1][0]=r1[0][2];r[1][1]=r1[1][2];r[1][2]=z;
					if (!gauss(2)) {
						r[0][0]=r1[0][1];r[0][1]=r1[1][1];r[0][2]=y;
						if (!gauss(2)) {
							printf("-1\n");continue;
						}
					}
				}
				ans=round(r[0][2])*r1[0][3]+round(r[1][2])*r1[1][3];
				printf("%d\n",ans);
			} else if (cnt==0) {
				if (v[0]%x==0&&v[1]%y==0
				&&v[2]%z==0&&v[3]%(v[0]/x)==0)
					ans=v[3]/(x/v[0]);
				else if (x%v[0]==0&&y%v[1]==0&&z%v[2]==0) 
					ans=v[3]*(x/v[0]);
				else ans=-1;
				printf("%d\n",ans);
			} else printf("-1\n");
		}
		scanf("%s",s);
	}
	return 0;
}
