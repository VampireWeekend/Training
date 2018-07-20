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
typedef unsigned long long ull;
typedef long double ld;
const int maxn=5005,inf=0x3f3f3f3f;
char s[maxn],t[maxn];
int a[26];

ull seed1=26,seed2=1e9+7;

ull hash() {
	ull sum=seed1;
	for (int i=0;i<26;i++) {
		sum*=seed2;
		sum+=a[i];
	}
	return sum;
}

int main() {
	map<ull,int> HashTable;
	scanf("%s",s);
	scanf("%s",t);
	int lena,lenb,i,j,k,ans;
	lena=strlen(s),lenb=strlen(t);
	int len=min(lena,lenb);
	ans=0;
	for (i=1;i<=len;i++) {
		HashTable.clear();
		mem0(a);
		for (j=0;j<i;j++) a[s[j]-'a']++;
		for (j=0;j<lena-i;j++) {
			HashTable[hash()]++;
			a[s[j]-'a']--;
			a[s[j+i]-'a']++;
		}
	//	cout << hash() << endl;
		HashTable[hash()]++;
		mem0(a);
		for (j=0;j<i;j++) a[t[j]-'a']++;
		for (j=0;j<lenb-i;j++) {
	//		cout << hash() << endl;
			if (HashTable[hash()]) ans=max(ans,i);
			a[t[j]-'a']--;
			a[t[j+i]-'a']++;
		}
		if (HashTable[hash()]) ans=max(ans,i);
	}
	printf("%d\n",ans);
	return 0;
}
