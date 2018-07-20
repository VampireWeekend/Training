#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
string s,pre,word,best,phrase;

int main() {
	char c;
	int i,len,j,ans,flag;
	while (scanf("%c",&c)!=EOF) {
		map<string,int> my;
		ans=0;
		if (c=='\n') scanf("%c",&c);
	while (c!='#') {
		i=-1;
		pre="";
		s="";
		flag=0;
		while ((!(c>='a'&&c<='z'))&&(!(c=='\n'))) 
			scanf("%c",&c);
		if (c=='\n') continue;
		while (c!='\n') {
			if (c>='a'&&c<='z') {
				s=s+c;
				scanf("%c",&c);
			} else {
				if (flag) {
					phrase=pre+" "+s;
					my[phrase]++;
					int y=my[phrase];
					if ((y>ans)||(y==ans&&phrase<best)) {
						ans=y;
						best=phrase;
					}
				}
				pre=s;
				s="";
				i=-1;
				flag=1;
				if (c!=' ') flag=0;
				scanf("%c",&c);
				while ((!(c>='a'&&c<='z'))&&(!(c=='\n'))) {
					if (c!=' ') flag=0;
					scanf("%c",&c);
				}
			}
		} 
		if (flag) {
			phrase=pre+" "+s;
			my[phrase]++;
			int y=my[phrase];
			if ((y>ans)||(y==ans&&phrase<best)) {
				ans=y;
				best=phrase;
			}
		}
		scanf("%c",&c);
	}
	scanf("%c",&c);
	scanf("%c",&c);
	scanf("%c",&c);
	cout << best;
	printf(":%d\n",ans);
	}
	return 0;
}
