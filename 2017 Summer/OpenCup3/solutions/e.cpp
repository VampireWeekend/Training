#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef double LD;

const int MOD = 1000 * 1000 * 1000 + 7;
string w, s;

void amod(int &a, int b) {
  a = (a + b) % MOD;
}

void smod(int &a, int b) {
  a = (a - b + MOD) % MOD;
}

int comp(int k) {
  int m = SZ(s);
  vector<VI> d(m, VI(m));
  auto push_back = [&](char x) -> void {
    for (int delta = m - 1; delta >= 0; --delta) {
      for (int a = 0; a + delta < m; ++a) {
        int b = a + delta;
        if (s[b] == x) {
          amod(d[a][b], a == b ? 1 : d[a][b - 1]);
        }
      }
    }
  };
  auto pop_front = [&](char x) -> void {
    for (int delta = 0; delta < m; ++delta) {
      for (int a = 0; a + delta < m; ++a) {
        int b = a + delta;
        if (s[a] == x) {
          smod(d[a][b], a == b ? 1 : d[a + 1][b]);
        }
      }
    }
  };
  for (int i = 0; i < min(SZ(w), k); ++i) {
    push_back(w[i]);
  }
  int res = d[0][m - 1];
  for (int i = k; i < SZ(w); ++i) {
    pop_front(w[i - k]);
    smod(res, d[0][m - 1]);
    push_back(w[i]);
    amod(res, d[0][m - 1]);
  }
  return res;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  int K;
  cin >> K >> K >> K >> w >> s;
  int res = comp(SZ(w));
  smod(res, comp(K));
  cout << res << endl;
  return 0;
}
