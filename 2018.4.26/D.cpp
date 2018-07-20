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
const int maxn=1000005,maxk=35,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];
bool z[maxk][maxk];
bool p[maxk];

int main() {
	scanf("%s",s+1);
	int i,ans=0,n,j,k;
	int last=-1;
	n=strlen(s+1);
	mem0(z);mem0(p);
	for (i=1;i<=n;i++) {
		if (last==-1) {
			last=i;
			ans++;
			p[s[i]-'a']=1;
		} else {
			if (!z[s[i-1]-'a'][s[i]-'a']) {
				for (k=last;k<i;k++){
					for (j=0;j<26;j++) {
						if (p[j]) z[j][s[k]-'a']=1;
					} 
					p[s[k]-'a']=1;
				}
				last=-1;
				ans++;
			} else if (i==n) ans++;
		}
		cout << ans << ' ' << i << endl;
	}
	printf("%d\n",ans);
	return 0;
}
