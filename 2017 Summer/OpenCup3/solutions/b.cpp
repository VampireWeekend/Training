/*/
  Zadanie Kolorowania
  Rozwiazanie wzorcowe
  Zlozonosc: O(n)
  autor: Bartek Kostka
/*/

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1000*1000+7;
int lad[MAXN], mad[MAXN], kol[MAXN];
bool nap[MAXN];

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<m; i++)
  {
    int a, b;
    cin >> a >> b;
    //nie przejmujemy sie krawedziami :)
  }
  for(int i=1; i<=n; i++)
    cin >> lad[i];
  for(int i=1; i<=n; i++)
    cin >> mad[i];
  vector <vector <int>> L(k+1), M(n+1);
  for(int i=1; i<=n; i++)
    L[lad[i]].push_back(i);
  for(int i=1; i<=n; i++)
    M[mad[i]].push_back(i);
  for(int i=1; i<=n; i++)
    kol[lad[i]]++;
  vector <int> ZLE;
  for(int i=1; i<=k; i++)
    if(kol[i] == 1)
    {
      ZLE.emplace_back(i);
      nap[i] = true;
    }
  for(size_t i=0; i<ZLE.size(); i++)
  {
    int e = ZLE[i];
    if(kol[e] != 1)
      continue;
    int f = L[e].front();
    int wsk = 0;
    while(lad[f] != e)
      f = L[e][++wsk];
    vector <int> PRE;
    for(auto v : M[mad[f]])
    {
      kol[lad[v]]--;
      PRE.push_back(lad[v]);
      lad[v] = e;
      kol[lad[v]]++;
    }
    for(auto g : PRE)
      if(nap[g] == false and kol[g] == 1)
      {
        nap[g] = true;
        ZLE.emplace_back(g);
      }
  }
  puts("TAK");
  for(int i=1; i<=n; i++)
    cout << lad[i] << " ";
  return 0;
}
