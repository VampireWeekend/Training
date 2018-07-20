#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <bits/stdc++.h>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

struct point {
  int x, y;
  point operator-(const point &a) const {
    return {x - a.x, y - a.y};
  }
  point rot90() const {
    return {-y, x};
  }
  LL mag() const {
    return LL(x) * x + LL(y) * y;
  }
  bool operator<(const point &a) const {
    return x == a.x ? (y < a.y) : (x < a.x);
  }
  point norm() {
    int d = __gcd(abs(x), abs(y));
    return {x / d, y / d};
  }
};

LL area(const point &a, const point &b) {
  return LL(a.x) * b.y - LL(b.x) * a.y;
}

int comp(vector<point> P, LL A, LL B) {
  int res = 0;
  for (int i = 0; i < SZ(P); ++i) {
    map<point, vector<point>> Q;
    for (int j = 0; j < SZ(P); ++j) {
      if (i == j) {
        continue;
      }
      point t = P[j] - P[i];
      Q[t.norm()].push_back(t);
    }
    for (auto &e : Q) {
      sort(ALL(e.second), [](const point &a, const point &b) -> bool { return a.mag() < b.mag(); });
    }
    for (const auto &e : Q) {
      if (!Q.count(e.first.rot90())) {
        continue;
      }
      const auto &a = e.second;
      const auto &b = Q[e.first.rot90()];
      int j = 0, k = SZ(b) - 1;
      for (; j < SZ(b) - 1 && area(a[0], b[j]) < A; ++j);
      for (const point &p : a) {
        for (; j >= 0 && area(p, b[j]) >= A; --j);
        for (; k >= 0 && area(p, b[k]) > B; --k);
        res += max(k - j, 0);
      }
    }
  }
  return res;
}

int main(void) {
  int n; LL a, b;
  scanf("%d" INT64 "" INT64, &n, &a, &b);
  a *= 2; b *= 2;
  vector<point> P(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  printf("%d\n", comp(P, a, b));
  return 0;
}
