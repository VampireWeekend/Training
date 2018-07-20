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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);

int main() {
	string s, t;
	ld a, b, a1, b1;
	cin >> s >> a1 >> a;
	cin >> t >> b1 >> b;
	if (s == "CD") a1 += 60;
	if (s == "DB") a1 += 120;
	if (t == "CD") b1 += 60;
	if (t == "DB") b1 += 120;
	a1 = a1 * pi / 180; b1 = b1 * pi / 180;
	ld x1, y1, x2, y2;
	x1 = a * cosl(a1); x2 = b * cosl(b1);
	y1 = a * sinl(a1); y2 = b * sinl(b1);
	ld X1, Y1, X2, Y2;
	X1 = x1 - y1 / sqrt(3); X2 = x2 - y2 / sqrt(3);
	Y1 = y1 *2.0L/ sqrt(3); Y2 = y2 * 2.0L/sqrt(3);
	int xx, yy, xxx, yyy;

	if ((int)floor(X1)%2 == (int)floor(X2)%2 && (int)floor(Y1)%2 == (int)floor(Y2)%2 && 
		(int)floor(X1+Y1)%2 == (int)floor(X2+Y2)%2) {
		printf("YES\n");
	}
	else printf("NO\n");
	system("pause");
	return 0;
}
