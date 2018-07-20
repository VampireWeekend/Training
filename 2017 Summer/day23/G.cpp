#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=16777216,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int q[maxn],step[maxn];
//int pr[maxn];
int b[7];
char s[25][25];
bool hash[maxn];
int x[3],y[3];
int p,h,t,n,m;
int ax,ay,bx,by,cx,cy,flag,f;

int hashv(int i,int j,int o) {
	return i*b[o*2]+j*b[o*2+1];
}

void solve(int state) {
	for (int i=0;i<p;i++) {
		x[i]=state%16;
		state/=16;
		y[i]=state%16;
		state/=16;
	}
}

bool check(int i,int j) {
	return i>=0&&i<n&&j>=0&&j<m&&s[i][j]!='#';
}

bool cover(int i,int j,int x,int y) {
	return !(i==x&&y==j);
}

void proceed(int val,int pre) {
	hash[val]=1;
	q[++t]=val;
	step[t]=step[pre]+1;
//	pr[t]=pre;
}

int main() {
    freopen("G.in","r",stdin); 
	int k,i,j;
	scanf("%d%d%d",&m,&n,&p);
	getchar();
	int dir[5][2]={{0,1},{0,-1},{1,0},{-1,0},{0,0}};
	b[0]=1;
	for (i=1;i<7;i++) {
		b[i]=b[i-1]*16;
	}
	while (n!=0||m!=0||p!=0) {
		mem0(hash);
		int state=0,final=0;
		for (i=0;i<n;i++) {
			cin.getline(s[i],20);
			for (j=0;j<m;j++) {
				if (s[i][j]>='A'&&s[i][j]<='Z') {
					final+=hashv(i,j,s[i][j]-'A');
				}
				if (s[i][j]>='a'&&s[i][j]<='z') {
					state+=hashv(i,j,s[i][j]-'a');
				}
			}
		}
		h=-1,t=0;q[0]=state;hash[state]=1;step[0]=0;
		flag=0;
		int ans=-1;
		while (h<t) {
			h++;
			solve(q[h]);
	/*		for (i=0;i<p;i++) {
				cout << x[i] << " " << y[i] << "   ";
			}
			cout << h << ' ' << step[h] << ' ' << pr[h] << '\n';*/
			for (i=0;i<5;i++) {
				ax=x[0]+dir[i][0];ay=y[0]+dir[i][1];
				if (check(ax,ay))
				if (p==1) {
					if (!hash[f=(hashv(ax,ay,0))]) {
						if (f==final) {
							flag=1;
							ans=step[h]+1;
							break;
						}
						proceed(f,h);	
					}	
				} else
				for (j=0;j<5;j++) {
					bx=x[1]+dir[j][0];by=y[1]+dir[j][1];
					if (check(bx,by))
					if (cover(ax,ay,bx,by))
					if (cover(ax,ay,x[1],y[1])||cover(bx,by,x[0],y[0]))
					if (p==2) {
						if (!hash[f=(hashv(ax,ay,0)+hashv(bx,by,1))]) {
							if (f==final) {
								flag=1;
								ans=step[h]+1;
								break;
							}
							proceed(f,h);	
						}	
					} else
					for (k=0;k<5;k++) {
						cx=x[2]+dir[k][0];cy=y[2]+dir[k][1];
						if (check(cx,cy))
						if (cover(ax,ay,cx,cy))
						if (cover(bx,by,cx,cy))
						if (cover(ax,ay,x[2],y[2])||cover(cx,cy,x[0],y[0]))
						if (cover(bx,by,x[2],y[2])||cover(cx,cy,x[1],y[1]))
						if (!hash[f=(hashv(ax,ay,0)+hashv(bx,by,1)+hashv(cx,cy,2))]) {
							if (f==final) {
								flag=1;
								ans=step[h]+1;
								break;
							}
							proceed(f,h);	
						}	
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
		int now=h;
		printf("%d\n",ans);
		scanf("%d%d%d",&m,&n,&p);
		getchar();
	}
	return 0;
}
/*
5 5 2
#####
#A#B#
#   #
#b#a#
#####
16 4 3
################
## ########## ##
#    ABCcba    #
################
16 16 3
################
### ##    #   ##
##  #  ##   # c#
#  ## ########b#
# ##  # #   #  #
#  # ##   # # ##
##  a#  # # #  #
### ## #### ## #
##   #   #  #  #
#  ##### # ## ##
####   #B# #   #
##  C#   #   ###
#  # # ####### #
# ######  A##  #
#        #    ##
################
0 0 0
*/
