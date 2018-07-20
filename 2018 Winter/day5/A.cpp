#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
map<string,char> mp;
string s,t;

int main() {
	mp[".-"]='A';mp["-..."]='B';mp["-.-."]='C';mp["-.."]='D';
	mp["."]='E';mp["..-."]='F';mp["--."]='G';mp["...."]='H';
	mp[".."]='I';mp[".---"]='J';mp["-.-"]='K';mp[".-.."]='L';
	mp["--"]='M';mp["-."]='N';
	mp["---"]='O';mp[".--."]='P';mp["--.-"]='Q';mp[".-."]='R';
	mp["..."]='S';mp["-"]='T';mp["..-"]='U';mp["...-"]='V';
	mp[".--"]='W';mp["-..-"]='X';mp["-.--"]='Y';mp["--.."]='Z';
//	cin >> s;
	while (getline(cin,s)) {
		int pos=s.find("/");
		while (pos!=-1) {
			int len=s.length();
			t=s.substr(0,pos);s=s.substr(pos+1,len);
//			cout << t << endl;cout << s << endl;
			if (pos==0) {
				printf(" ");pos=s.find("/");continue;
			}
			char c=mp[t];printf("%c",c);
			pos=s.find("/");
		}
		char c=mp[s];printf("%c\n",c);
//		cin >> s;
	}
	return 0;
}
