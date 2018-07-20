#include<cstdio>
#include<algorithm>
#include <math.h>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 1010;
const long double eps=1e-15L;
struct node{
    long double x;
    friend bool operator < (node xx, node yy){
        return xx.x < yy.x;
    }
}a[MAXN][MAXN];
struct Way{
    int all, num;
    long double ok, peo;
    friend bool operator < (Way xx, Way yy){
        if(abs(xx.ok-yy.ok)<eps ){
            if(xx.all==yy.all)
            return xx.peo < yy.peo;
            return xx.all < yy.all;
        }
        return xx.ok > yy.ok;
    }
}b[MAXN];

int cnt[MAXN], p[MAXN], n;
long double rem = 1, ans;
int main(){
	ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> cnt[i];
        for(int j = 1; j <= cnt[i]; j ++){
            cin >> a[i][j].x;
        }
        b[i].all = cnt[i];
        b[i].num = i;
    }
    for(int i = 1; i <= n; i ++){
        sort(a[i]+1, a[i]+1+cnt[i]);
        long double tem = 1;
        for(int j = 1; j <= cnt[i]; j ++){
            b[i].peo += tem * (1.0L-a[i][j].x/1000.0L) * j;
            tem = tem * a[i][j].x / 1000.0L;
        }
        b[i].ok = tem;
    }
    
    sort(b+1, b+1+n);
    
    long double poss = 1;
    for(int i = 1; i <= n; i ++){
        ans += poss * b[i].ok * b[i].all;
        ans += poss * b[i].peo;
        poss *= (1.0L - b[i].ok);
    }
    cout << setiosflags(ios::fixed) << setprecision(10);
    cout << ans;
    return 0;
}


/*
 2
 3 900 900 900
 2 100 100
 */


