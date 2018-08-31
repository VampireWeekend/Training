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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn][6],b[maxn][6];
ll mx[32];

int main() {
	int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        for (int i=0;i<32;i++) mx[i]=-llinf;
        for (int i=1;i<=n;i++) {
            for (int j=0;j<=l;j++) {
                scanf("%lld",&a[i][j]);
            }
            for (int k=0;k<(1<<l);k++) {
                ll sum=0;
                for (int q=0;q<l;q++) {
                    if ((k>>q)&1) sum+=a[i][q+1]; else sum-=a[i][q+1];
                }
                sum+=a[i][0];
                mx[k]=max(mx[k],sum);
            }
        }
 //       for (int k=0;k<(1<<l);k++) cout << mx[k] << endl;
        ll ans=-llinf;
        for (int i=1;i<=m;i++) {
            for (int j=0;j<=l;j++) {
                scanf("%lld",&b[i][j]);
            }
            for (int k=0;k<(1<<l);k++) {
                ll sum=0;
                for (int q=0;q<l;q++) {
                    if ((k>>q)&1) sum-=b[i][q+1]; else sum+=b[i][q+1];
                }
                sum+=b[i][0];
                sum+=mx[k];
//                cout << sum << endl;
                ans=max(ans,sum);
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
