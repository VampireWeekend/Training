#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <math.h>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long double ld;
int a[256][25],b[20][25],pitch[10005];
char s[23];

int main() {
	int n,m,i,j,k;
	char c;
	scanf("%d",&m);
	map<char,int> my;
	my['A']=1;my['B']=2;my['C']=3;my['D']=4;my['E']=5;my['F']=6;my['G']=7;
	my['#']=7;my['b']=14;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (i=1;i<=m;i++) {
		for (j=1;j<=7;j++) {
			scanf("%s",s);
			if (strlen(s)==1) {
				b[i][my[s[0]]]=1;
			} else {
				b[i][my[s[0]]+my[s[1]]]=1;
			}
		}
	}
	int l=0;
	if (m!=1)
	for (i=1;i<=m;i++) {
		for (j=i+1;j<=m;j++) {
			l++;
			for (k=1;k<=21;k++) {
				a[l][k]=b[i][k]+b[j][k];
				if (a[l][k]) a[l][0]=a[l][0]|(1<<(k-1));
			}
		}
	}
	else {
			l=1;
			for (k=1;k<=21;k++) {
				a[l][k]=b[1][k];
				if (a[l][k]) a[l][0]=a[l][0]|(1<<(k-1));
			}
		}
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%s",s);
		if (strlen(s)==1) {
			pitch[i]=my[s[0]];
		} else {
			pitch[i]=my[s[0]]+my[s[1]];
		}
	}
	int maxlen=1,maxcondition,cnt=0;
	while (maxlen<=n) {
		cnt++;
		maxcondition=0;
		for (j=1;j<=l;j++) {
			if (maxcondition!=(maxcondition&a[j][0])) continue;
			while (a[j][pitch[maxlen]]&&maxlen<=n) {
				maxcondition=(maxcondition|(1<<(pitch[maxlen]-1)));
				maxlen++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
