#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
char s[100005];
int a[100005],b[100005];

int main() {
	int k,i;
while (scanf("%d",&k)!=EOF) {
	scanf("%s",s);
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	int len=strlen(s);
	for (i=0;i<len;i++) {
		if (s[i]=='1') {
			int l=i%k,pos;
			if (l==0) pos=k-1; else pos=l-1;
			if (a[pos]!=-1) {
				printf("%d %d\n",a[pos]+1,i+1);
				return 0;
			} else if (b[pos]!=-1) {
				printf("%d %d\n",b[pos]+1,i+1);
				return 0;
			}else {
				b[l]=a[l];
				a[l]=i;
			}
		}
	}
	printf("0 0\n");
}
	return 0;
}
