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
const int maxn=10,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535898L;
string a[5][5][15];
int l[5];
char c[55];
int h[5];

int main() {
	int n,i,j,k,p;
	scanf("%d\n",&n);
	for (i=1;i<=4;i++) {
		h[i]=1;
		l[i]=1;
		for (j=1;j<=3;j++) {
			for (k=1;k<=15;k++) {
				a[i][j][k]="";
			}
		}
	}
	map<string,int> mp;
	string s,t;
	int q,pos;
	mp["Tuesday"]=1;mp["Thursday"]=2;mp["Saturday"]=3;
	for (i=1;i<=n;i++) {
		getline(cin,s);
		cin >> t;
		if (i!=n) scanf("%d\n",&q); else scanf("%d",&q);
		int line=1,last=0;
		while ((pos=s.find(" "))!=-1) {
			if (last+pos+(last==0?0:1)<=10) {
				if (last!=0) 
				    a[q][mp[t]][line]+=" ";
				a[q][mp[t]][line]+=s.substr(0,pos);
				last+=pos+(last==0?0:1);
			} else {
				line++;
				a[q][mp[t]][line]=s.substr(0,pos);
				last=pos;
			}
			s=s.substr(pos+1,s.length());
		}
		pos=s.length();
		if (last+pos+(last==0?0:1)<=10) {
			if (last!=0) a[q][mp[t]][line]+=" ";
			a[q][mp[t]][line]+=s;
		} else {
			line++;
			a[q][mp[t]][line]=s;
		}
		l[q]=max(l[q],line);
	}
	for (i=1;i<=4;i++) {
		printf("+----------+----------+----------+\n");
		for (k=1;k<=l[i];k++) {
			for (j=1;j<=3;j++) {
				printf("|");
				cout << a[i][j][k];
				int len=a[i][j][k].length();
				for (p=len+1;p<=10;p++) printf(" ");
			}
			printf("|\n");
		}
	}
	printf("+----------+----------+----------+\n");
	return 0;
}

