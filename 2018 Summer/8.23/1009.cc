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
multiset<int> st;

int main() {
	int n,k,x,sum=0;;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;i++) {
        scanf("%d",&x);
        st.insert(x);
        sum+=x;
    }
    printf("%d ",sum);
    for (int i=k+1;i<=n;i++) {
        scanf("%d",&x);
        multiset<int>::iterator it;
        it=st.begin();
        if (x>=*it) {
            sum=sum-*it+x;
            st.erase(it);
            st.insert(x);
        }
        printf("%d ",sum);
    }
	return 0;
}
