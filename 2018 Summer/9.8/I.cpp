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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
string a[128];
string s,t,rem,let;
int num=0;

struct Tree{
	int l,r;
	bool leaf;
	char ans;
};
Tree tree[100005];
 
void insert(int now,int depth,int len,char ch) {
	if (t[depth]=='0') {
		if (tree[now].l==-1) {
			tree[now].l=++num;tree[num].leaf=0;
			tree[num].l=tree[num].r=-1;
		}
		if (depth==len-1) {
			tree[tree[now].l].leaf=1,tree[tree[now].l].ans=ch;return;
		}
		else insert(tree[now].l,depth+1,len,ch);
	} else {
		if (tree[now].r==-1) {
			tree[now].r=++num;tree[num].leaf=0;
			tree[num].l=tree[num].r=-1;
		}
		if (depth==len-1) {
			tree[tree[now].r].leaf=1,tree[tree[now].r].ans=ch;return;
		}
		else insert(tree[now].r,depth+1,len,ch);
	}
}

int main() {
	int cas;
	ios::sync_with_stdio(false);
	cin >> cas;
	a['0']="0000";a['1']="0001";a['2']="0010";a['3']="0011";
	a['4']="0100";a['5']="0101";a['6']="0110";a['7']="0111";
	a['8']="1000";a['9']="1001";a['A']="1010";a['B']="1011";
	a['C']="1100";a['D']="1101";a['E']="1110";a['F']="1111";
	while (cas--) {
		int n,m;
		cin >> m >> n;
		for (int i=0;i<=num;i++) {
			tree[i].l=tree[i].r=-1;
			tree[i].leaf=false;
		}
		num=0;
		for (int i=1;i<=n;i++) {
			int j;
			cin >> j >> t;
			int len=t.length();
			insert(0,0,len,(char)j);
		}
		cin >> s;
		int len=s.length(),rlen=0,now=0,p=0;
		rem="";
		for (int i=0;i<len;i++) {
			if (s[i]>='a'&&s[i]<='z') s[i]=(char)s[i]-'a'+'A';
			rem=rem+a[s[i]];rlen+=4;
			if (rlen>=9) {
				int cnt=0;
				for (int j=0;j<8;j++) if (rem[j]=='1') cnt++;
				if (cnt%2!=rem[8]-'0') {
					for (int j=0;j<8;j++) {
						if (rem[j]=='0') now=tree[now].l; else now=tree[now].r;
						if (tree[now].leaf) {
							cout << tree[now].ans;
							now=0;
							p++;
							if (p==m) {
								break;
							}
						}
					}
					if (p==m) break;
				}
				if (rlen==9) rem=""; else rem=rem.substr(9,rlen-9);
				rlen-=9;
			}
			if (p==m) break;
		}
		cout << '\n';
	}
	return 0;
}
