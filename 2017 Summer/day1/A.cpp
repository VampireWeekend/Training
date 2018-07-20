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
    for (n=0;n<=100;n++) {
    	for (k=1;k<=100;k++) {
    	    if (k==n+1) a[n][k]=1; else a[n][k]=0;
    	}
    }
    cin >> n >> k;
    if (a[n][k]) cout << "yes\n"; else cout << "no\n";	
	return 0;
}
