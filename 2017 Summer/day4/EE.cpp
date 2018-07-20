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
	int k,i,j;
while (scanf("%d",&k)!=EOF) {
	scanf("%s",s);
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	int len=strlen(s);
	for (i=0;i<len;i++) {
		if (s[i]=='1') {
			for (j=1;;j++) {
				if (i+j*k+1>=len) break; else {
					if (s[i+j*k+1]=='1') {
						printf("%d %d\n",i+1,i+j*k+2);
			//			return 0;
					}
				}
			}
		}
	}
	printf("0 0\n");
}
	return 0;
}
