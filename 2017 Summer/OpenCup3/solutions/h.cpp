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

#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

vector<LL> a, sa;

struct str {
  int x, y;
  LL t, b;
  
  LL eval(int i, LL T) const {
    return a[i] * (T - t) + b;
  }
  LL above(LL B, LL T) const {
    return (sa[y] - (x > 0 ? sa[x - 1] : 0)) * (T - t) + (b - B) * (y - x + 1);
  }

  pair<str, str> split(LL B, LL T) const {
    int res = int(lower_bound(ALL(a), (B - b) / (T - t) + 1) - a.begin());
    assert(res > x && res <= y);
    return {{x, res - 1, t, b}, {res, y, t, b}};
  }
};

struct garden {
  vector<str> S;
  garden(int n) {
    a = sa = vector<LL>(n);
    for (int i = 0; i < n; ++i) {
      scanf(INT64, &a[i]);
    }
    sort(ALL(a));
    for (int i = 0; i < n; ++i) {
      sa[i] = a[i];
      if (i > 0) {
        sa[i] += sa[i - 1];
      }
    }
    S.push_back({0, n - 1, 0, 0});
  }

  LL cut(LL T, LL B) {
    LL res = 0LL;
    while (!S.empty()) {
      str e = S.back();
      if (e.eval(e.y, T) <= B) {
        break;
      }
      S.pop_back();
      if (e.eval(e.x, T) > B) {
        res += e.above(B, T);
      } else {
        auto tmp = e.split(B, T);
        S.push_back(tmp.first);
        S.push_back(tmp.second);
      }
    }
    int z = S.empty() ? 0 : S.back().y + 1;
    if (z < SZ(a)) {
      S.push_back({z, SZ(a) - 1, T, B});
    }
    return res;
  }
};

int main(void) {
  int n, m; scanf("%d%d", &n, &m);
  garden G(n);
  for (int i = 0; i < m; ++i) {
    LL t, B; scanf(INT64 "" INT64, &t, &B);
    printf(INT64 "\n", G.cut(t, B));
  }
  return 0;
}
