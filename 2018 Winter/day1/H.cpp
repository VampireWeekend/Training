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
const int maxn=15,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
bool v[maxn];

int main() {
	int cas;
	scanf("%d",&cas);getchar();
	while (cas--) {
		char ch,op;
		ll a,b,c,aq,bq,cq,t,ad,bd,cd,p[3],i;
		bool la,lb,lc;la=lb=lc=false;
		aq=bq=cq=1;a=b=c=ad=bd=cd=0;t=1;
		mem0(v);
		scanf("%c",&ch);
		if (ch=='?'&&t==1) la=true,ad++;
		if (ch=='-') aq=-1; else  if (ch!='?') a=ch-'0',t*=10,v[ch-'0']=true;
		scanf("%c",&ch);
		while (ch!='+'&&ch!='-'&&ch!='*') {
			a*=10;ad*=10;
			if (ch=='?') ad=ad+1; else a=a+ch-'0',v[ch-'0']=true;
			if (ch=='?'&&t==1) la=true;
			t*=10;
			scanf("%c",&ch);
		}
		p[0]=t;
		op=ch;t=1;
		scanf("%c",&ch);
		if (ch=='?'&&t==1) lb=true,bd++;
		if (ch=='-') bq=-1; else  if (ch!='?') b=ch-'0',t*=10,v[ch-'0']=true;
		scanf("%c",&ch);
		while (ch!='=') {
			b*=10;bd*=10;
			if (ch=='?') bd=bd+1; else b+=ch-'0',v[ch-'0']=true;
			if (ch=='?'&&t==1) lb=true;
			t*=10;
			scanf("%c",&ch);
		}
		p[1]=t;
		t=1;
		scanf("%c",&ch);
		if (ch=='?'&&t==1) lc=true,cd++;
		if (ch=='-') cq=-1; else if (ch!='?') c=ch-'0',t*=10,v[ch-'0']=true;
		scanf("%c",&ch);
		while ((ch>='0'&&ch<='9')||ch=='?') {
			c*=10;cd*=10;
			if (ch=='?') cd=cd+1; else c+=ch-'0',v[ch-'0']=true;
			if (ch=='?'&&t==1) lc=true;
			t*=10;
			scanf("%c",&ch);
		}
		p[2]=t;ll ans=inf;
		for (i=0;i<=9;i++) {
			if (v[i]) continue;
			if (i==0) {
				if (la)
					if (p[0]>1||aq==-1) continue;
				if (lb)
					if (p[1]>1||bq==-1) continue;
				if (lc)
					if (p[2]>1||cq==-1) continue;
			}
			ll na,nb,nc;
			na=(a+ad*i)*aq;
			nb=(b+bd*i)*bq;
			nc=(c+cd*i)*cq;
			cout << na << ' ' << nb << ' ' << nc << endl;
			if (op=='+') {
				if (na+nb==nc) ans=min(i,ans);
			} else
			if (op=='-') {
				if (na-nb==nc) ans=min(i,ans);
			} else
			if (op=='*') {
				if (na*nb==nc) ans=min(i,ans);
			}
		}
		if (ans==inf) printf("-1\n"); else printf("%lld\n",ans);
	}
	return 0;
}
