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
const int maxn = 400005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
char s[maxn], t[maxn];
int n1, n2, m;

struct complex
{
	double r, i;
	complex(double _r = 0, double _i = 0)
	{
		r = _r; i = _i;
	}
	complex operator +(const complex &b)
	{
		return complex(r + b.r, i + b.i);
	}
	complex operator -(const complex &b)
	{
		return complex(r - b.r, i - b.i);
	}
	complex operator *(const complex &b)
	{
		return complex(r*b.r - i * b.i, r*b.i + i * b.r);
	}
};
complex conj(complex a) {
	return complex(a.r, -a.i);
}
complex a[maxn], b[maxn];
int ans[maxn];

struct fff {
	int n, rev[maxn];
	complex o[maxn], oi[maxn];

	void init(int m) {
		n = 1;
		int k = 0;
		mem0(rev); mem0(o); mem0(oi);
		while (n < m) n <<= 1, k++;
		for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		for (k = 0; k < n; k++) {
			o[k] = complex(cos(2 * pi / n * k), sin(2 * pi / n * k));
			oi[k] = conj(o[k]);
		}
	}

	void fft(complex *a, complex *w) {
		for (int i = 0; i < n; i++)
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int l = 2; l <= n; l <<= 1) {
			int m = l >> 1;
			for (complex *p = a; p != a + n; p += l)
				for (int k = 0; k < m; k++) {
					complex t = w[n / l * k] * p[k + m];
					p[k + m] = p[k] - t;
					p[k] = p[k] + t;
				}
		}
	}

	void dft(complex *a, int f) {
		if (f == 1) fft(a, o); else {
			fft(a, oi);
			for (int i = 0; i < n; i++) a[i].r /= n;
		}
	}

	void mul(complex *a, complex *b, int m) {
		init(m);
		dft(a, 1); dft(b, 1);
		for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
		dft(a, -1);
	}
};
fff f;

void cal(char c) {
	mem0(a); mem0(b);
	for (int i = 0; i < n1; i++) if (s[i] == c) a[i].r = 1; else a[i].r = 0;
	for (int i = 0; i < n2; i++) if (t[i] == c) b[i].r = 1; else b[i].r = 0;
	f.mul(a, b, m);
	for (int i = 0; i < m; i++) ans[i] += floor(a[i].r + 0.5);
}

int main() {
	int i, j;
	scanf("%d%d", &n1, &n2);
	scanf("%s", s); scanf("%s", t);
	m = n1 + n2 - 1;
	for (i = 0; i < n1; i++) {
		if (s[i] == 'R') s[i] = 'P'; else
			if (s[i] == 'P') s[i] = 'S'; else s[i] = 'R';
	}
	strrev(t);
	cal('R'); cal('P'); cal('S');
	int ANS = -1;;
	for (i = n2-1; i < m; i++) ANS = max(ANS, ans[i]);
	printf("%d\n", ANS);
//	system("pause");
	return 0;
}
