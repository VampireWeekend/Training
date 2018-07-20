#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[100],b[100],c[100];

int main() {
	ll l,r,p,sum;
	int i,j,t,q;
	scanf("%d",&t);
	for (q=1;q<=t;q++) {
	scanf("%lld%lld",&l,&r); 
	p=1;
	sum=0;
		int lena=0,lenb=0;
		ll i=l;
		while (i) {
			lena++;
			i/=2;
		}
		for (i=1;i<=lena;i++) {
			a[i]=l%2;
			l/=2;
		}
		i=r;
		while (i) {
			lenb++;
			i/=2;
		}
		for (i=1;i<=lenb;i++) {
			b[i]=r%2;
			c[i]=b[i];
			r/=2;
		}
		if (lena==lenb) {
			int k=lena;
		while (a[k]==b[k]&&k>0)
			k--;
		for(i=k;i>=1;i--) {
			c[i]=1;
		}
		for (i=1;i<lenb;i++) {
			sum+=p*c[i];
			p*=2;
		}
		sum+=p*c[lenb];
		} else {
			for (i=1;i<lenb;i++) {
			sum+=p;
			p*=2;
		}
		sum+=p;
		}
		printf("%lld\n",sum);
	}
}
