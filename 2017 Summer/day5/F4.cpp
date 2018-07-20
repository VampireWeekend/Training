#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
int a[35];

int getsg(int sum) {
	bool visit[1005];
	int i,f;
	memset(visit,0,sizeof(visit));
	for (i=1;i<=a[0];i++) {
		if (sum-a[i]>=0) {
			visit[f=getsg(sum-a[i])]=1;
			if (!f) return 1;
		}
	}
	for (i=0;;i++)
    	if (!visit[i]) return i;
}

int main() {
	int n,k,i,f;
	for (k=1;k<=15;k++) {
		for (n=k;n<=30;n++) {
			ll l=k;
			a[0]=1;
			a[1]=1;
			if (k!=1)
	    	while (l<=100) {	
	    	    a[++a[0]]=l;
	    	    l*=k;
		    }
		    int flag=0;
		    for (f=1;f<=a[0];f++) {
		    	if (n-a[f]>=0)
		    	if (!getsg(n-a[f])) {
		    	    printf("%d %d   %d\n",n,k,a[f]);
		    	    flag=1;
		    	    break;
		        }
		    }
		    if (!flag) printf("%d %d   %d\n",n,k,0);
		}
	}
	return 0;
}
