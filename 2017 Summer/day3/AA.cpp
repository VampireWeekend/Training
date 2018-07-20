//((a+b)+(c+d))a
#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2005;
char s[maxn];
int st[maxn];
int plu[maxn],mul[maxn],beg[maxn],f[maxn];

int main () {
	int i;
	while (scanf("%s",s)!=EOF) {
		memset(mul,0,sizeof(mul));
		memset(plu,0,sizeof(plu));
		memset(f,0,sizeof(f));
		int len=strlen(s),top=0,sttop=0;
		i=-1;
		while (i<len) {
			i++;
			if (s[i]=='(') {
				sttop++;
				st[sttop]=top;
				beg[sttop]=i;
				int k=i;
				while (k>=0&&(s[k]=='('||s[k]==')')) k--;
				if (k>=0&&s[k]>='a'&&s[k]<='z') {
					mul[i]=1;
				}
			} else if (s[i]==')') {
				int k=i;
				while (k<len&&(s[k]=='('||s[k]==')')) {
					k++;
				}
				if (mul[beg[sttop]]) mul[i]=1;
				if (k<len&&s[k]>='a'&&s[k]<='z') {
					mul[beg[sttop]]=mul[i]=1;
				}
				top=st[sttop];
				if (!mul[i]||(mul[i]&&!plu[sttop])) f[beg[sttop]]=f[i]=1;
				mul[sttop]=0;
				plu[sttop]=0;
				sttop--;
			} else {
				if (s[i]=='+') plu[sttop]++;
			}
		}
		for (i=0;i<len;i++) {
			if (s[i]=='('||s[i]==')') 
				if (f[i]) continue;
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
