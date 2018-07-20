#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const int maxn = 1<<16;
LD rem[maxn], dp[maxn], a[maxn];
vector<int> v[maxn];
bool cmp(LD x, LD y) { return x > y;}

void build(int o, int l, int r){
    for(int i = l; i <= r; i ++)
        v[o].push_back(i);
    if(l == r)
        return ;
    int m = (l + r) / 2;
    build(o*2, l, m);
    build(o*2+1, m+1, r);
}

void find(int o, int l, int r){
    
    if(l == r) return ;
    
    int lo = o * 2, ro = o*2 + 1, m = (l + r) / 2;
    int lk = v[lo].size(), rk = v[ro].size();
    find(lo, l, m);
    find(ro, m+1, r);
    for(int i = 0; i < lk; i ++){
        for(int j = 0; j < rk; j ++){
            int x = v[lo][i], y = v[ro][j];
            rem[x] += a[x] * dp[y] * dp[x] / (a[x] + a[y]);
            rem[y] += a[y] * dp[y] * dp[x] / (a[x] + a[y]);
        }
    }
    
    for(int i = l; i <= r; i ++){
        dp[i] = rem[i];
        rem[i] = 0;
    }
}

int main(){
    int n;
    cin >> n >> a[0];
    for(int i = 1; i < n; i ++)
        cin >> a[i];
    for(int i = 1; i <= n; i ++)
        dp[i] = 1;
    sort(a+1, a+n, cmp);
    a[n] = a[0];
    build(1, 1, n);
    
    find(1, 1, n);
    
    printf("%.8Lf", dp[n]);
}
