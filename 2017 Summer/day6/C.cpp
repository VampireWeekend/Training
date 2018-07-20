#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <string> 
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const char space=(char)32;
char s[1005][305];
int head[1005][205],tail[1005][205];
int num[1005];
int word[305];

int main() {
	int i,j,n,k;
	mem(head);mem(tail);
	int maxnum=0;
	freopen("alignment.in","r",stdin);
	freopen("alignment.out","w",stdout);
	string o;
	i=0;
	while (getline(cin,o)!=0) {
		i++;
	    int len=o.length();
	    k=0;
	    for (j=0;j<len;j++) {
	    	if ((int)o[j]>=32&&(int)o[j]<=126) {
	    		s[i][k++]=o[j];
	    	}
	    }
	    len=k;
		num[i]=0;
		head[i][1]=0;
		while (s[i][head[i][1]]==space) head[i][1]++;
		while (head[i][num[i]+1]<len) {
			num[i]++;
			tail[i][num[i]]=head[i][num[i]];
			while (s[i][tail[i][num[i]]]!=space&&tail[i][num[i]]<len) 
				tail[i][num[i]]++;
			head[i][num[i]+1]=tail[i][num[i]];
			tail[i][num[i]]--;
			while (s[i][head[i][num[i]+1]]==space&&head[i][num[i]+1]<len)
			    head[i][num[i]+1]++;
		}
		head[i][num[i]+1]=0;
		maxnum=max(maxnum,num[i]);
    }
    n=i;
	word[1]=0;
	for (i=2;i<=maxnum;i++) {
		word[i]=0;
		for (j=1;j<=n;j++) {
			if (num[j]>=i-1)
			word[i]=max(word[i],tail[j][i-1]-head[j][i-1]+1);
		}
		word[i]+=word[i-1]+1;
	}
	for (i=1;i<=n;i++) {
		int cnt=0;
		for (j=1;j<=num[i];j++) {
			for (k=head[i][j];k<=tail[i][j];k++) {
				printf("%c",s[i][k]);
				cnt++;
			}
			if (j!=num[i]) {
				while (cnt<word[j+1]) {
					printf("%c",space);
					cnt++;
				}
			}
		}
		if (i!=n) printf("\n");
	}
	return 0;
}
