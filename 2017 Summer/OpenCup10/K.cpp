#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
string s[15],t[10],a[10];
int ans[10];

int main() {
	int cas,i,j;
	scanf("%d",&cas);
	a[0]=".XX.X..XX..X....X..XX..X.XX.";
	a[1]=".......X...X.......X...X....";
	a[2]=".XX....X...X.XX.X...X....XX.";
	a[3]=".XX....X...X.XX....X...X.XX.";
	a[4]="....X..XX..X.XX....X...X....";
	a[5]=".XX.X...X....XX....X...X.XX.";
	a[6]=".XX.X...X....XXX...XX..X.XX.";
	a[7]=".XX....X...X.......X...X....";
	a[8]=".XX.X..XX..X.XX.X..XX..X.XX.";
	a[9]=".XX.X..XX..X.XX....X...X.XX.";
	while (cas--) {
		for (i=1;i<=4;i++) t[i]="";
		for (i=1;i<=7;i++) {
			cin >> s[i];
			t[1]=t[1]+s[i].substr(0,4);
			t[2]=t[2]+s[i].substr(5,4);
			t[3]=t[3]+s[i].substr(12,4);
			t[4]=t[4]+s[i].substr(17,4);
		}
		for (i=1;i<=4;i++) {
			for (j=0;j<=9;j++) {
				if (a[j]==t[i]) ans[i]=j;
			}
		}
		printf("%d%d:%d%d\n",ans[1],ans[2],ans[3],ans[4]);
	}
	return 0;
}
