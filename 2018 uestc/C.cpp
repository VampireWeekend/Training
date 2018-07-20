#include <cstdio>
#include <iostream>
#include <string.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;
ll dp[maxn*2];
char s[maxn],b[maxn];
int vis[maxn];

struct SAM {  
	int num,last,maxlen;  
    struct node{  
        int len,fa;  
        int son[maxk];  
    } a[maxn*2];  
    void init() {  
        num=last=maxlen=0;  
        a[0].len=0;a[0].fa=-1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;
		maxlen=max(maxlen,a[now].len);
        memset(a[now].son,-1,sizeof(a[now].son));  
        for (p=last;p!=-1&&a[p].son[c]==-1;p=a[p].fa)  
            a[p].son[c]=now;  
        if (p==-1) a[now].fa=0; else {  
            int q=a[p].son[c];  
            if (a[p].len+1==a[q].len) {  
                a[now].fa=q;  
            } else {  
                int ne=++num;  
                a[ne].len=a[p].len+1;
				maxlen=max(maxlen,a[ne].len);  
                memcpy(a[ne].son,a[q].son,sizeof(a[q].son));  
                a[ne].fa=a[q].fa;  
                for (;p!=-1&&a[p].son[c]==q;p=a[p].fa)   
                    a[p].son[c]=ne;  
                a[q].fa=a[now].fa=ne;  
            }  
        }  
        last=now;  
    }  
    int getfa(int n) {
    	return a[n].fa;
    }
    int getlen(int n) {
    	return a[n].len;
    }
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
};  
SAM sa;
//��right���ϴ�С
int w[maxn*2],r[maxn*2];
void topsort() {
    int m=sa.getnum(),i;
    mem0(w);
    for(i=0;i<=m;i++) w[sa.getlen(i)]++;  
    for(i=0;i<=len;i++) w[i]+=w[i-1];  
    for(i=m;i>=0;i--) r[--w[sa.getlen(i)]]=i;  
    int now=0; 
    for (i=0;i<len;i++) {
		now=sa.getson(now,s[i]-'a');
		dp[now]++;
    }
    for (i=m;i>0;i--) {
    	int to=sa.getfa(r[i]);
    	if (to!=-1) dp[to]+=dp[r[i]]; 
    }
}
	
int main() {
	int len,n,i,q,m;
	sa.init();
	scanf("%s",s+1);
	len=strlen(s+1);
	for (i=1;i<=len;i++) {
		sa.update(s[i]-'a');
	}
	m=sa.getnum();
	int now=0;
	for (i=1;i<=len;i++) {
		now=sa.getson(s[i]-'a');
		dp[now]++;
	}
	scanf("%d",&q);
	int cnt=0;
	mem0(vis);
	for (i=1;i<=q;i++) {
		scanf("%s",b+1);
		n=strlen(b+1);
		queue<int> q[2];
		q[0].push(0);
		for (j=1;j<=n;j++) {
			cnt++;
			while (!q.empty()) {
				
			}
		}
	}
	return 0;
}
