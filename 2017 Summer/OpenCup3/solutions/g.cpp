#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
long long tmp, dz, w, k, a, b, ma, wyn;
int main()
{
    cin >> k >> a >> b;
    ios_base::sync_with_stdio(false);
    wyn = 0;
    if (1e18 / k >= 1458)
        ma = k * 1458;
    else
        ma = 1e18;
    for (long long i = k; i <= ma; i += k) {
        tmp = i;
        dz = 0;
        while (tmp > 0) {
            w = (tmp % 10);
            dz += w * w;
            tmp /= 10;
        }
        if (i == dz * k && a <= i && i <= b) {
            wyn++;
        }
    }
    cout << wyn << "\n";
}
