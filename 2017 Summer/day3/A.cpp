#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[1005],stack[1005];
int a[1005],b[1005],mul[1005];

int main () {
	int i;
	while (scanf("%s",s)!=EOF) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(mul,0,sizeof(mul));
		int len=strlen(s),top=0;
		for (i=0;i<len;i++) {
			if (s[i]=='(') {
				top++;
				b[i]=top;
				if (i>0) 
				    if (s[i-1]>='a'&&s[i-1]<='z') mul[top]=1;
			} else if (s[i]==')') {
				b[i]=top;
				if (i!=len-1) 
				    if (s[i+1]>='a'&&s[i+1]<='z') mul[top]=1;
				top--;
			} else {
				b[i]=top;
				if (s[i]=='+') a[top]++;
			}
		}
		for (i=0;i<len;i++) {
			if (s[i]=='('||s[i]==')') 
				if (!a[b[i]]&&!mul[b[i]]) continue;
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
