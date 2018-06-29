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
#define N 20
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=10005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],c[maxn],cnt;

bool check(int n) {
	for (int i=1;i<=n;i++) {
		if (a[i]!=i) return false;
	}
	return true;
}

void shuffle(int n) {
	int cnt=0;
	for (int i=1;i<=n;i+=2) {
		b[++cnt]=a[i];
	}
	for (int i=2;i<=n;i+=2) {
		b[++cnt]=a[i];
	}
	for (int i=1;i<=n;i++) {
		a[i]=b[i];
		if (a[i]==i) c[i]=min(c[i],cnt);
	}
}

void print(int n) {
	for (int i=1;i<=n;i++) {
		cout << (char)(a[i]+'A'-1);
	}
	cout << '\n';
}

int main() {
	for (int n=2;n<=N;n+=2) {
		meminf(c);
		for (int i=1;i<=n;i++) {
			a[i]=i;
		}
		print(n);
		shuffle(n);
		print(n);
		cnt=1;
		while (!check(n)) {
			shuffle(n);
			cnt++;
			print(n);
		}
		cout << n << ' ' << cnt << '\n';
	/*	for (int i=1;i<=n;i++) {
			cout << i << ' ' << c[i] << endl;
		}
		cout << '\n';*/
	}
	return 0;
}
