#include <stdlib.h>
#include <string.h>
/*
   Rozwiazanie wzorcowe, dzialajace w czasie O(n*log(n))
   Do wyznaczenia pierwszej chwili, gdy koniecznie musimy obsluzyc zlecenie, wykorzystujemy drzewko licznikowe
   Obslugujemy zawsze zlecenie, ktore najwczesniej sie konczy (z juz rozpoczetych)
   Zlozonosc pamieciowa O(n)
   Autor: Pawel Parys
*/

#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(a,n) for (int a = 0; a<(n); ++a)
#define FOR(a,b,c) for (int a = (b); a<=(c); ++a)
#define FORD(a,b,c) for (int a = (b); a>=(c); --a)
#define INIT(i,v) __typeof(v) i = (v)
#define FOREACH(i,v) for (INIT(i, (v).begin()); i!=(v).end(); ++i)

#define MP make_pair

typedef pair<int, int> pii;

///////////////////

#define MAXN (1000*1000)
#define INF (1000*1000*1000+5) // wiecej niz maksymalny czas

pii duza_tablica[4*MAXN]; // w tej tablicy beda znajdowac sie drzewa licznikowe

pii *drzewo_licz[MAXN]; // wskazniki na drzewa licznikowe, dla kazdego przyrzadu
// liscie to momenty, w ktorych jest jakis koniec przedzialu
// wartosc w lisciu to: (ilosc przedzialow konczacych sie w tym momencie)-(odleglosc do poprzedniego liscia)
// w kazdym wezle jest para: suma, maksimum_z_sum_prefiksow
// korzen w 1, dziecmi x jest 2*x i 2*x+1

int N, ile_prz = 0;

pair<pii, pii> zlecenia[MAXN]; 
// posortowane czworki: ((nr_przyrzadu, koniec_czasu), (poczatek_czasu, oryginalny_nr_zlecenia))
// po inicjalizacji zamiast koniec_czasu mamy numer_wezla_w_drzewie
#define NR_PRZYRZ first.first
#define KON_CZASU first.second
#define POCZ_CZASU second.first
#define ORYG_NR_ZLEC second.second

pii poczatki_zlecen[MAXN]; // (poczatek_czasu, pozycja_w_tablicy_zlecenia), posortowane po (nr_przyrzadu, poczatek_czasu)

priority_queue<pii, vector<pii>, greater<pii> > musze_zaczac; // pary: (pierwszy_moment_kiedy_musze_skorzystac_z_przyrzadu, nr_przyrzadu)

priority_queue<pii, vector<pii>, greater<pii> > pierwszy_poczatek; // pary: (pierwszy_poczatek_nieobsluzonego_zlecenia, nr_przyrzadu)

priority_queue<pii, vector<pii>, greater<pii> > konce[MAXN]; // dla kazdego przyrzadu pary: (numer_wezla_w_drzewie, nr_zlecenia)

int niewstawiony_poczatek[MAXN]; // dla kazdego przyrzadu: pozycja_w_tablicy_poczatki_zlecen dla pierwszego zlecenia niewstawionego do "konce"

int wyniki[MAXN]; // dla kazdego oryginalnego numeru zlecenia jest to czas realizacji zlecenia

//

inline int kiedy_musze_zaczac(int nr_prz) { // pierwszy moment kiedy koniecznie musze skorzystac z danego przyrzadu
  return -drzewo_licz[nr_prz][1].second; // jesli nie ma nieobsluzonych zlecen, to powinno wyjsc INF
}

inline void wstaw_do_musze_zaczac(int nr_prz) {
  int kiedy = kiedy_musze_zaczac(nr_prz);
  if (kiedy<INF)
    musze_zaczac.push(MP(kiedy, nr_prz));
}

inline bool jest_niewstawiony_poczatek(int nr_prz) {
    if (niewstawiony_poczatek[nr_prz]>=N)
      return false; // wszystko obsluzone (ostatni przyrzad)
    int nr_zlec = poczatki_zlecen[niewstawiony_poczatek[nr_prz]].second;
    return zlecenia[nr_zlec].NR_PRZYRZ==nr_prz; // nie wyszlismy na nastepny przyrzad
}

inline void wstaw_do_kol_poczatkow(int nr_prz) {
  if (!konce[nr_prz].empty())
    pierwszy_poczatek.push(MP(0, nr_prz)); // mozemy wstawic 0 zamiast konkretnej wartosci, bo wiemy ze jakis nieobsluzony przedzal zaczal sie wczesniej od aktualnego czasu
  else 
  if (jest_niewstawiony_poczatek(nr_prz))
    pierwszy_poczatek.push(MP(poczatki_zlecen[niewstawiony_poczatek[nr_prz]].first, nr_prz));
}

int zwieksz_do_pot2(int val) { // zwraca najmniejsza potege dwojki >=val
  int x = 1;
  while (x<val)
    x *= 2;
  return x;
}

inline void aktualizuj_drzewo(int nr_prz, int wezel) { // aktualizuje wezel na podstawie dzieci
  pii *drz = drzewo_licz[nr_prz];
  drz[wezel].first = drz[wezel*2].first+drz[wezel*2+1].first;
  drz[wezel].second = max(drz[wezel*2].second, drz[wezel*2].first+drz[wezel*2+1].second);
}

int main() {
  scanf("%d%*d", &N);
  REP(a, N) {
    scanf("%d%d%d", &zlecenia[a].POCZ_CZASU, &zlecenia[a].KON_CZASU, &zlecenia[a].NR_PRZYRZ);
    zlecenia[a].ORYG_NR_ZLEC = a;
  }
  sort(zlecenia, zlecenia+N);
  
  // INICJALIZACJA STRUKTUR DANYCH
  
  int zaj_tab = 0; // ile pol w duza_tablica juz zajete
  for (int nr_prz = 0, p = 0; p<N; ++nr_prz) {
    int k = p;
    int stary_nr_prz = zlecenia[p].NR_PRZYRZ;
    while (k<N && zlecenia[k].NR_PRZYRZ==stary_nr_prz) {
      zlecenia[k].NR_PRZYRZ = nr_prz;
      ++k;
    }
    // teraz zlecenia od p do k-1 sa na ten sam przyrzad (nadalismy mu nowy numer nr_prz)
    drzewo_licz[nr_prz] = duza_tablica+zaj_tab;
    int rozm = zwieksz_do_pot2(k-p);
    zaj_tab += 2*rozm;
    int poprz_cz = -1;
    int nr_wezla = rozm;
    for (int p_cz = p; p_cz<k; ++nr_wezla) {
      int czas_k = zlecenia[p_cz].KON_CZASU;
      int k_cz = p_cz;
      while (k_cz<k && zlecenia[k_cz].KON_CZASU==czas_k)
        ++k_cz;
      // teraz zlecenia od p_cz do k_cz-1 maja ten sam koniec czasu (=czas_k)
      int val = (k_cz-p_cz)-(czas_k-poprz_cz);
      drzewo_licz[nr_prz][nr_wezla] = MP(val, val);
      poprz_cz = czas_k;
      // zmieniamy tablice "zlecenia", tworzymy tablice "poczatki_zlecen"
      FOR(a, p_cz, k_cz-1) {
        zlecenia[a].KON_CZASU = nr_wezla;
        poczatki_zlecen[a] = MP(zlecenia[a].POCZ_CZASU, a);
      }
      p_cz = k_cz;
    }
    // ustalamy wartosci w pozostalych wezlach
    FOR(a, nr_wezla, 2*rozm-1)
      drzewo_licz[nr_prz][a].second = -INF;
    FORD(a, rozm-1, 1)
      aktualizuj_drzewo(nr_prz, a);
    // sortujemy po poczatkach (bylo po koncach)
    sort(poczatki_zlecen+p, poczatki_zlecen+k);
    niewstawiony_poczatek[nr_prz] = p;
    // wstawiamy do kolejek
    wstaw_do_musze_zaczac(nr_prz);
    wstaw_do_kol_poczatkow(nr_prz);
    p = k;
  }
  
  // GLOWNA PETLA
  
  int poprzedni_czas = -INF;
  int ile_czasow = 0;
  while (!musze_zaczac.empty()) {
    int czas = musze_zaczac.top().first;
    int nr_prz = musze_zaczac.top().second;
    musze_zaczac.pop();
    if (kiedy_musze_zaczac(nr_prz)!=czas) {
      // byc moze wartosc w kopcu nieaktualna, bo w miedzyczasie juz skorzystalismy z tego przyrzadu
      wstaw_do_musze_zaczac(nr_prz);
      continue;
    }
    if (czas==poprzedni_czas) {
      printf("NIE\n");
      return 0;
    }
    poprzedni_czas = czas;
    vector<int> obsl_prz;
    while (!pierwszy_poczatek.empty() && pierwszy_poczatek.top().first<=czas) {
      // przechodzimy po wszystkich przyrzadach, w ktorych jakies zlecenie zaczyna sie w chwili <=czas
      int nr_prz = pierwszy_poczatek.top().second;
      pierwszy_poczatek.pop();      
      obsl_prz.push_back(nr_prz);
      // do "konce" wstawiam wszystkie zlecenia zaczynajace sie w chwili <=czas
      while (jest_niewstawiony_poczatek(nr_prz) && poczatki_zlecen[niewstawiony_poczatek[nr_prz]].first<=czas) {
        int nr_zlec = poczatki_zlecen[niewstawiony_poczatek[nr_prz]].second;
        konce[nr_prz].push(MP(zlecenia[nr_zlec].KON_CZASU, nr_zlec));
        ++niewstawiony_poczatek[nr_prz];
      }
      // obsluguje najwczesniejszy koniec
      int nr_zlec = konce[nr_prz].top().second;
      konce[nr_prz].pop();
      wyniki[zlecenia[nr_zlec].ORYG_NR_ZLEC] = czas;
      int wezel = zlecenia[nr_zlec].KON_CZASU;
      --drzewo_licz[nr_prz][wezel].first;
      if (nr_zlec+1<N && zlecenia[nr_zlec+1].NR_PRZYRZ==nr_prz && zlecenia[nr_zlec+1].KON_CZASU==wezel)
        --drzewo_licz[nr_prz][wezel].second; // sa jeszcze zlecenia majace ten sam koniec (wazne, ze zlecenia z tym samym koncem sa zawsze obslugiwane w kolejnosci od najwczesniejszych poczatkow)
      else
        drzewo_licz[nr_prz][wezel].second = -INF;
      while (wezel>1) {
        wezel /= 2;
        aktualizuj_drzewo(nr_prz, wezel);
      } 
    }
    FOREACH(it, obsl_prz)
      wstaw_do_kol_poczatkow(*it);
    wstaw_do_musze_zaczac(nr_prz);
    ++ile_czasow;
  }
  printf("%d\n", ile_czasow);
  REP(a, N)
    printf("%d\n", wyniki[a]);
}
