#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
int num[10];
string s1[15],s[15],ans[15];

int main() {
	s1[0]="xxxxxx...xx...xx...xx...xx...xxxxxx";
	s1[1]="....x....x....x....x....x....x....x";
	s1[2]="xxxxx....x....xxxxxxx....x....xxxxx";
	s1[3]="xxxxx....x....xxxxxx....x....xxxxxx";
	s1[4]="x...xx...xx...xxxxxx....x....x....x";
	s1[5]="xxxxxx....x....xxxxx....x....xxxxxx";
	s1[6]="xxxxxx....x....xxxxxx...xx...xxxxxx";
	s1[7]="xxxxx....x....x....x....x....x....x";
	s1[8]="xxxxxx...xx...xxxxxxx...xx...xxxxxx";
	s1[9]="xxxxxx...xx...xxxxxx....x....xxxxxx";
	s1[10]=".......x....x..xxxxx..x....x......."; 
	int i,j,flag=0;
	ll a,b;
	a=b=0;
	for (i=0;i<7;i++) {
		cin >> s[i];
	}
	int len=s[0].length();
	len=(len+1)/6;
	for (i=1;i<=len;i++) {
		string d="";
		for (j=0;j<7;j++) {
			d=d+s[j].substr((i-1)*6,5);
		}
		int digit=-1;
		cout << d << endl;
		if (d==s1[10]) flag=1; else {
			for (j=0;j<=9;j++) 
			if (d==s1[j]) {
				digit=j;break;
			}
			if (flag) b=b*10+digit; else a=a*10+digit;
		}
	}
	ll k=a+b;
	for (i=0;i<7;i++) ans[i]="";
	while (k) {
		ll d=k%10;k/=10;
		for (j=0;j<7;j++) {
			ans[j]=s1[d].substr(j*6,5)+ans[j];
		}
		if (k) {
			for (j=0;j<7;j++) ans[j]=ans[j]+".";
		}
	}
	for (j=0;j<7;j++) cout << ans[j] << endl;
	return 0;
}
