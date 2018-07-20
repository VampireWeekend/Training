#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
/* Rozwiazanie wzorcowe zadania Roboty
   Autor: Bartosz Tarnawski
   Zlozonosc czasowa: O(n^4 / 32 + f(n) n^2),
    gdzie f(n) = O((sqrt n)!), ale to bardzo zgrubne ograniczenie
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>

using namespace std;

const int N = 200 + 1;
const int M = 27720; // == 8 * 9 * 5 * 7 * 11
// jesli m <= N, to m / gcd(m, M) ma co najwyzej jeden dzielnik pierwszy
// M = f(N)

int n, b, r;

// ================= Bitset ================================================ //

const int MS = 32; // 32-bit architektura na PA
struct Bitset {
  vector<int> bytes;
  int size;
  Bitset(int sz = 0, bool fill = false) : size(sz) {
    int bytes_num = (sz + MS - 1) / MS; // == ceil(sz / MS)
    bytes.resize(bytes_num, fill ? 0xffffffff : 0);
  }

  bool get (int x) const {
    return bytes[x / MS] & (1 << (x % MS));
  }

  void set(int x, bool b) {
    int px = x / MS, bx = 1 << (x % MS);
    if (b) {
      bytes[px] |= bx;
    } else {
      bytes[px] &= ~bx;
    }
  }

  Bitset neg() const {
    Bitset res(size);
    for (size_t i = 0; i < bytes.size(); i++) {
      res.bytes[i] = ~bytes[i];
    }
    return res;
  } 

  Bitset or_with(const Bitset &other) const {
    Bitset res(size);
    for (size_t i = 0; i < bytes.size(); i++) {
      res.bytes[i] = bytes[i] | other.bytes[i];
    }
    return res;
  }
  
  void or_in_place(const Bitset &other) {
    for (size_t i = 0; i < bytes.size(); i++) {
      bytes[i] |= other.bytes[i];
    }
  }
  
  Bitset and_with(const Bitset &other) const {
    Bitset res(size);
    for (size_t i = 0; i < bytes.size(); i++) {
      res.bytes[i] = bytes[i] & other.bytes[i];
    }
    return res;
  }
  
  void and_in_place(const Bitset &other) {
    for (size_t i = 0; i < bytes.size(); i++) {
      bytes[i] &= other.bytes[i];
    }
  }

  // zalozenie m != 0
  // zwraca numer ostatniego zapalonego bitu
  static inline int last_set(int m) {
    return __builtin_ctz(m);
  }

  // zwraca indeksy zapalonych bitow
  vector<int> ones() const {
    vector<int> res;
    for (size_t i = 0; i < bytes.size(); i++) {
      int m = bytes[i];
      while (m != 0) {
        int b = last_set(m);
        m ^= (1 << b);
        int re = i * MS + b;
        if (re < size) {
          res.push_back(re);
        }
      }
    }
    return res;
  }

  // zwraca indeks pierwszego zapalonego bitu lub -1, gdy nie ma takiego
  int first_one() const {
    for (size_t i = 0; i < bytes.size(); i++) {
      int m = bytes[i];
      if (m != 0) {
        int b = last_set(m);
        int re = i * MS + b;
        if (re < size) {
          return re;
        }
      }
    }
    return -1;
  }
};


// =================== BigNumy ============================================= //

const int BASE = 10; // mozna dac wiecej, ale po co?
struct Number {
  int dig[N];

  Number() {
    for(int i = 0; i < N; i++) dig[i] = 0;
    dig[0] = 1;
  }

  void write() {
    bool nonzero = false;
    for (int i = N - 1; i >= 0; i--) {
      if (dig[i] || nonzero) {
        nonzero = true;
        cout << dig[i];
      }
    }
  }

  void add(Number &other) {
    int rem = 0;
    for (int i = 0; i < N; i++) {
      int c = rem + dig[i] + other.dig[i];
      rem = c / BASE;
      dig[i] = c % BASE;
    }
  }

  void mul(int x) {
    int rem = 0;
    for (int i = 0; i < N; i++) {
      int c = rem + dig[i] * x;
      rem = c / BASE;
      dig[i] = c % BASE;
    }
  }

  int mod(int div) {
    int re = 0;
    for (int i = N - 1; i >= 0; i--) {
      re = (re * BASE + dig[i]) % div;
    }
    return re;
  }
};

// Zalozenie : congs sa postaci (m_i, a_i), m_i -- parami wzglednie pierwsze
// Wynik: X taki, ze X = a_i mod m_i dla kazdej pary (m_i, a_i)
// Zlozonosc: O(n^3)
Number solve_congs(vector<pair<int, int>> congs) {
  Number r; // = 1
  Number m; // = 1

  for (auto pr : congs) {
    int m1, r1;
    tie(m1, r1) = pr;

    while (r.mod(m1) != r1) {
      r.add(m);
    }

    m.mul(m1);
  }

  return r; // X = r mod m
}

// ================= CRT + brut ============================================ //

int gcd(int x, int y) {
  while (y != 0) {
    int my = y;
    y = x % y;
    x = my;
  }
  return x;
}


// Szukamy takiego X, ze zachodzi:
// bad_rems_mod[i][j] = true <=> ~(X = j mod i)
// Zwracamy wektor par (m_i, a_i) okreslajacych szukanego X przez
// X = a_i mod m_i, gdize m_i -- parami wzglednie pierwsze
// Zwraca pusty wektor w razie niepowodzenia
// Zalozenie: n > 1
// Zlozonosc: O(M * (n^2 / 32 + L)),
// gdzie L -- suma poteg liczb pierwszych <= n
vector<pair<int, int>> find_good_congs(vector<vector<bool>> bad_rems_mod) {

  vector<int> primes; // lb. pierwsze <= n
  vector<int> prime_pows; // (pot lb. pierwszych) <= n
  vector<int> max_powers; // (max pot lb. pierwszych) <= n
  vector<int> prime_div(n + 1); // p dla p^k, dla reszty nieokreslone
  vector<int> good_prime_pow(n + 1); // jesli m / gcd(m, M) = p^l,
  // to good_prime_pow[m] = p^k, gdzie k jest max takie, ze p^k | m

  for (int i = 2; i <= n; i++) {
    bool prime = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      primes.push_back(i);
    }
  }

  prime_pows.push_back(1);

  for (int p : primes) {
    int pp = 1;
    while (pp * p <= n) {
      pp *= p;
      prime_div[pp] = p;
      prime_pows.push_back(pp);
    }
    max_powers.push_back(pp);
  }

  for (int m = 1; m <= n; m++) {
    int d = gcd(M, m);
    if (d == m) {
      good_prime_pow[m] = 1;
      continue;
    }
    int p = prime_div[m / d];
    int pp = 1;
    while (m % (pp * p) == 0) {
      pp *= p;
    }
    good_prime_pow[m] = pp;
  }
    
  vector<vector<Bitset>> precomp_and_rests(n + 1);

  // precomputing masek bitowych, zeby pozniej szybciej wykonywac sprawdzenia
  for (int m = 1; m <= n; m++) { // popatrz na zle kong. mod m

    int d = gcd(M, m);
    int pp = good_prime_pow[m];
    int l = m / d;

    precomp_and_rests[m].resize(d);

    for (int r1 = 0; r1 < d; r1++) { // X = r1 mod d
      precomp_and_rests[m][r1] = Bitset(pp, true);
      for (int i = 0; i < l; i++) {
        int c = (r1 + i * d) % m;
        if (bad_rems_mod[m][c]) {
          precomp_and_rests[m][r1].set(c % pp, false);
          // (X = r1 mod d) i (X = c mod pp) =>
          // X = c mod m, bo m = lcm(d, pp)
        }
      }
    }
  }

  for (int r = 0; r < M; r++) { // X = r mod M
    
    // interesuja nas tylko reszty modulo potega liczby pierwszej
    vector<Bitset> allowed_rests(n + 1);

    for (int pp : prime_pows) {
      if (M % pp == 0) {
        allowed_rests[pp] = Bitset(pp, false);
        allowed_rests[pp].set(r % pp, true);
      } else {
        allowed_rests[pp] = Bitset(pp, true);
      }
    }

    for (int m = 1; m <= n; m++) { // popatrz na zle kong. mod m
      int d = gcd(M, m);
      int r1 = r % d;
      int pp = good_prime_pow[m];
      allowed_rests[pp].and_in_place(precomp_and_rests[m][r1]);
    }

    for (int p : primes) {
      int c = 1;
      while (c * p <= n) {
        int nc = c * p;
          for (int i = 0; i < nc; i++) {
            if (!allowed_rests[c].get(i % c)) {
              allowed_rests[nc].set(i, false);
            }
            // X = i mod p^(k + 1) => X = i mod p^k
          }
        c = nc;
      }
    }
  
    bool good = true;
    vector<pair<int, int>> res;

    for (int pp : max_powers) {
      int i = allowed_rests[pp].first_one();
      if (i == -1) {
        good = false;
        break;
      }
      res.push_back({pp, i});
    }

    if (good) {
      return res;
    }
  }
  return vector<pair<int, int>>();
}

// ================= Czytanie wejscia ====================================== //

vector<Bitset> edge;

// Dodaje superzrodlo (wierzcholek 0) polaczony z poz. startowymi robotow
void read_input() {
  cin >> n >> b >> r;

  edge.resize(n + 1, Bitset(n + 1));
  for (int i = 1; i <= n; i++) {
    char edge_str[n + 1];
    cin >> edge_str;
    for (int j = 1; j <= n; j++) {
      edge[i].set(j, edge_str[j - 1] == '1');
    }
  }

  for (int i = 0; i < r; i++) {
    int x;
    cin >> x;
    edge[0].set(x, true);
  }
}

// ================= Algorytmy grafowe ===================================== //

// on_cycle[i][j] = true <=> wierzcholek j lezy na cyklu o dl. i
// O(n^4 / 32)
vector<vector<bool>> find_on_cycle() {
  vector<vector<bool>> on_cycle(n + 1, vector<bool>(n + 1, false));

  for (int i = 1; i <= n; i++) { // 0 nie lezy na zadnym cyklu, zaczynamy od 1
    Bitset visited(n + 1);
    visited.set(i, true);
    
    for (int j = 1; j <= n; j++) {
      Bitset new_visited(n + 1);

      for (int l = 0; l <= n; l++) {
        if (visited.get(l)) {
          new_visited.or_in_place(edge[l]);
        }
      }

      swap(new_visited.bytes, visited.bytes);
      if (visited.get(i)) {
        on_cycle[j][i] = true;
      }
    }
  }

  return on_cycle;
}

// (czy przeszedl przez cykl o dl. len?, reszta mod len, nr wierzcholka)
typedef tuple<int, int, int> Position;

// O(n^3 / 32)
// zwraca wszystkie zle reszty mod len
// bad_rems[i] = true <=>
// robot moze byc poza baza po (k = t * len + i) ruchach,
// dla kazdego takiego t, ze k >= 2 * n + 1
// Zalozenie: on_cycle - wierzcholki na cyklach o dl. len
vector<bool> find_bad_rems(int len, vector<bool>& on_cycle) {

  vector<bool> bad_rems(len);
  
  Bitset visited[2][len];

  for (int t = 0; t < 2; t++) {
    for (int r = 0; r < len; r++) {
      visited[t][r] = Bitset(n + 1);
    }
  }
  
  vector<Position> qu;
  qu.push_back(Position(0, len - 1, 0));
  // chcemy Position(0, 0, v) dla v -- pozycji startowej robotow
  visited[0][len - 1].set(0, true);

  // Przeszukanie grafu
  while (!qu.empty()) {
    int t, r, v;
    tie(t, r, v) = qu.back();
    qu.pop_back();
   
    // przechodzi przez cykl
    if (t == 0 && on_cycle[v] && !visited[1][r].get(v)) {
      visited[1][r].set(v, true);
      qu.push_back(Position(1, r, v));
    }
    
    int r2 = (r + 1) % len;

    Bitset new_visits = edge[v].and_with(visited[t][r2].neg());
    visited[t][r2].or_in_place(edge[v]);

    for (int v2 : new_visits.ones()) {
      qu.push_back(Position(t, r2, v2));
    }
  }

  for (int r = 0; r < len; r++) {
    for (int v = b + 1; v <= n; v++) {
      if (visited[1][r].get(v)) {
        bad_rems[r] = true;
      }
    }
  }

  return bad_rems;
}

// znajduje k pod warunkiem, ze k <= step_num
// O(n^2 * step_num / 32)
int find_small_res(int step_num) {
  Bitset visited(n + 1);
  visited.set(0, true);

  for (int i = 0; i <= step_num; i++) {
    bool good = (i != 0);
    for (int j = b + 1; j <= n; j++) {
      if (visited.get(j)) {
        good = false;
        break;
      }
    }
    if (good) {
      return i - 1;
    } // else robot poza baza po i ruchach

    Bitset new_visited(n + 1);

    for (int j = 0; j <= n; j++) {
      if (visited.get(j)) {
        new_visited.or_in_place(edge[j]);
      }
    }
    swap(visited.bytes, new_visited.bytes);
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);

  read_input();

  int res = find_small_res(2 * n * n + 1);
  
  if (res != -1) {
    cout << res << "\n";
    return 0;
  }

  vector<vector<bool>> on_cycle = find_on_cycle();

  vector<vector<bool>> bad_rems_mod(n + 1);

  for (int i = 1; i <= n; i++) {
    bad_rems_mod[i] = find_bad_rems(i, on_cycle[i]);
  }
  vector<pair<int, int>> congs = find_good_congs(bad_rems_mod);

  if (congs.empty()) {
    cout << "-1\n";
  } else {
    Number res = solve_congs(congs);
    res.write();
    cout << "\n";
  }

  return 0;
}
