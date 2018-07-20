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
const int maxn=20005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

struct formula{
	int x,s;
	bool odd;
};
formula a[maxn*2];

bool cmp(formula a,formula b) {
	return a.x<b.x;
}

int main() {
	int k1,k2,b1,b2,s,i,j,p;
	scanf("%d%d%d",&k1,&b1,&s);
	a[0].s=0;a[0].x=b1-1;
	for (i=1;i<=k1;i++) {
		scanf("%d",&p);
		a[i].s=a[i-1].s+p;
		a[i].x=a[i-1].x+s;
	}
	scanf("%d%d%d",&k2,&b2,&s);
	a[k1+1].s=0;a[k1+1].x=b2-1;
	for (i=1;i<=k2;i++) {
		scanf("%d",&p);
		a[i+k1+1].s=a[i+k1].s+p;
		a[i+k1+1].x=a[i+k1].x+s;
	}
	if (b1 < b2) {
		for (i = 0; i <= k1; i++) a[i].odd = 1,a[i].s--;
	}
	else {
		for (i = k1+1; i <= k1+k2+1; i++) a[i].odd = 1,a[i].s--;
	}
	sort(a,a+k1+k2+2,cmp);
/*	for (j = 0; j<k1 + k2 + 2; j++) {
		cout << a[j].x << ' ' << a[j].s << ' ' << a[j].odd << endl;
	}*/
	for (i = 1; i<k1 + k2 + 2; i++) {
		if (a[i].odd != a[i - 1].odd) break;
		if (a[i].s != a[i - 1].s) {
			cout << "No";
			return 0;
		}
	}
	for (i = k1 + k2; i >= 0; i--) {
		if (a[i].odd != a[i + 1].odd) break;
		if (a[i].s != a[i + 1].s) {
			cout << "No";
			return 0;
		}
	}
	for (i=0;i<=20030;i++) {
		int flag=1;
		if (a[0].odd==1) a[0].s++;
		for (j=1;j<k1+k2+2;j++) {
			if (a[j].odd==1) a[j].s++;
			if ((a[j-1].s>a[j].s)||(a[j-1].s!=a[j].s&&a[j-1].x==a[j].x))
				flag=0;
		}
		if (flag) {
			cout << "Yes";
		/*	for (j = 0; j<k1 + k2 + 2; j++) {
				cout << a[j].x << ' ' << a[j].s << ' ' << a[j].odd << endl;
			}
			system("pause");*/
			return 0;
		}
	}
	for (j = 0; j < k1 + k2 + 2; j++) if (a[j].odd == 1) a[j].s -= 20030; else a[j].s--;
	for (i = 0; i <= 20030; i++) {
		int flag = 1;
		if (a[0].odd == 0) a[0].s++;
		for (j = 1; j<k1 + k2 + 2; j++) {
			if (a[j].odd == 0) a[j].s++;
			if ((a[j - 1].s>a[j].s) || (a[j - 1].s != a[j].s&&a[j - 1].x == a[j].x))
				flag = 0;
		}
		if (flag) {
			cout << "Yes";
		/*	for (j = 0; j<k1 + k2 + 2; j++) {
				cout << a[j].x << ' ' << a[j].s << ' ' << a[j].odd << endl;
			}
			system("pause");*/
			return 0;
		}
	}
	cout << "No";
//	system("pause");
	return 0;
}
