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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int main() {
	int n,i,j,t;
	scanf("%d",&n);
	string s,last;
	t=0;
	char c;
	scanf("%c",&c);
	while (n) {
		getline(cin,s);
		if (s=="END OF CASE") {
			n--;
			t=0;
			last="";
			continue;
		}
		t++;
		int len=s.length(),pos;
		for (i=0;i<len;i++) {
			if (s[i]==';') {
				cout << t << ": ";
				if ((pos=last.find("Zombies:"))>=0) {
					int l=last.length();
					for (j=0;j<l;j++) {
						printf("%c",last[j]);
						if (last[j]==':') printf(" ");
					}
					printf(";\n");
				} else if ((pos=last.find("No"))>=0){
					int l=last.length();
					for (j=0;j<l-1;j++) {
						printf("%c",last[j]);
						if (last[j+1]=='Z') printf(" ");
					}
					printf("s;\n");
				} else cout << last << ";" << endl;
				last="";
			} else if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||
			(s[i]>='0'&&s[i]<='9')||s[i]==':') 
			last=last+s[i];
		}
	}
	return 0;
}
