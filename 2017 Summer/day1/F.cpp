#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int a[105][105];

int main() {
	int n,k;	
    cin >> n >> k;
    if ((n+1)%k==0) cout << "yes\n"; else cout << "no\n";	
	return 0;
}
