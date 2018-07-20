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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
string a[1000000];
char c[5];
map<string,int> mp;
int num;

void dfs(int top,int pos,string s) {
//	cout << s << endl;
	if (pos==6) {
		a[num++]=s;
		return;
	}
	if (pos==5) {
		dfs(0,pos+1,s+((char)('a'+top)));
		return;
	}
	for (int i=top;i>=0;i--) {
		dfs(top-i,pos+1,s+((char)('a'+i)));
	}
}

int main() {
	int i,x;
	num=0;
	dfs(15,0,"");
	sort(a,a+num);
	for (i=0;i<num;i++) {
		mp[a[i]]=i;
	}
	scanf("%s",c);
	int cnt=0;
	while (c[0]!='e') {
		cnt++;
		printf("Case %d: ",cnt);
		if (c[0]=='m') {
			string p="";
			for (i=1;i<=6;i++) {
				scanf("%d",&x);
				p=p+((char)('a'+x));
			}
			printf("%d\n",mp[p]);
		} else {
			scanf("%d",&x);
			for (i=0;i<6;i++) {
				printf("%d ",a[x][i]-'a');
			}
			printf("\n");
		}
		scanf("%s",c);
	}
	return 0;
}

