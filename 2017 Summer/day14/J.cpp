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
const int size=9;
const int inf=0x3f3f3f3f;
const ll mod=10007;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

struct Matrix {
	ll a[size][size];
};

Matrix operator*(const Matrix &x,const Matrix &y) {
	int i,j,k;
	Matrix ans;
	for (i=0;i<size;i++) {
		for (j=0;j<size;j++) {
			ans.a[i][j]=0;
			for (k=0;k<size;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
				ans.a[i][j]%=mod;
			}
		}
	} 
	return ans;
}

Matrix fastpower(Matrix base,ll index) {
	Matrix ans,now;
	int i,j;
	for (i=0;i<size;i++) {
		for (j=0;j<size;j++) {
			if (i==j) ans.a[i][j]=1; else ans.a[i][j]=0;
		}
	}
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		now=now*now;
		k/=2;
	}
	return ans;
}


int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas,i,j;
	scanf("%d",&cas);
	Matrix x;
	ll a[9][9]=
	     {{2,1,1,0,0,0,0,1,0},{1,2,0,1,0,0,0,0,0},{1,0,2,1,1,0,1,0,0},
	     {0,1,1,2,0,1,0,0,0},{0,0,0,0,2,1,0,0,1},{0,0,0,0,1,2,0,0,0},
		 {0,0,0,0,0,0,2,1,1},{0,0,0,0,0,0,1,2,0},{0,0,0,0,0,0,0,0,2}};
	for (i=0;i<size;i++) {
		for (j=0;j<size;j++) {
			x.a[i][j]=a[i][j];
		}
	}
	ll b[9]={0,0,0,0,1,0,1,0,2};
	while (cas--) {
		ll n,sum=0;
		scanf("%lld",&n);
		Matrix ans=fastpower(x,n-1);
		for (i=0;i<9;i++) {
			sum+=(ans.a[1][i]+ans.a[5][i]+ans.a[7][i]+ans.a[8][i])*b[i];
			sum%=mod;
	//		cout << sum << endl;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

