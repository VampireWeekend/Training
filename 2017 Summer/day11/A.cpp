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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int main() {
	freopen("bulls.in","r",stdin);
	freopen("bulls.out","w",stdout);
    int a,b,i,j;
    string l,r;
    a=b=0;
    cin >> l >> r;
    map<char,int> mp;
    for (i=0;i<=3;i++) {
    	if (l[i]==r[i]) a++;
    	mp[l[i]]=i+1;
    }
    for (i=0;i<=3;i++) {
    	if (mp[r[i]]!=0&&mp[r[i]]!=i+1) b++;
    }
    cout << a << ' ' << b << endl;
	return 0;
}
