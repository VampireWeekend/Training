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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=15,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
vector<int> v;

int main() {
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	int pos=upper_bound(v.begin(),v.end(),8)-v.begin();
	cout << pos;
	return 0;
}
