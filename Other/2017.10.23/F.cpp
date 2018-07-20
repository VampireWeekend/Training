#include <cstdio>
#include <iostream>
#include <string.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=250005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;
int w[maxn*2],r[maxn*2];
char s[maxn];

class SAM {
    public:  
    void init() {  
        num=last=0;  
        a[0].len=0;a[0].fa=-1;a[0].flag=1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c,int pos) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;
		a[now].flag=0;a[now].pos=pos;
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
				a[ne].flag=0;a[ne].pos=a[p].pos;  
                memcpy(a[ne].son,a[q].son,sizeof(a[q].son));  
                a[ne].fa=a[q].fa;  
                for (;p!=-1&&a[p].son[c]==q;p=a[p].fa)   
                    a[p].son[c]=ne;  
                a[q].fa=a[now].fa=ne;  
            }  
        }  
        last=now;  
    }
    int dfs(int now) {
    	if (!a[now].flag) return now;
    	int q;
    	for (int i=0;i<maxk;i++) {
    		if (a[now].son[i]!=-1) 
    		    if (q=dfs(a[now].son[i])) return q;
    	}
    	return 0;
    }
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
    int getfa(int n) {
    	return a[n].fa;
    }
    int getlen(int n) {
    	return a[n].len;
    }
    int getflag(int n) {
    	return a[n].flag;
    }
    int getpos(int n) {
    	return a[n].pos;
    }
    void setflag(int n) {
    	a[n].flag=1;
    }
    private:  
    int num,last;  
    struct node{  
        int len,fa,flag,pos;  
        int son[maxk];  
    } a[maxn*2];  
};  
SAM sa;  

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		int n,i,j,m,len;
		scanf("%d",&n);
		scanf("%s",s);
		len=strlen(s);
		sa.init();
		for (i=0;i<len;i++) sa.update(s[i]-'a',i);
		for (i=2;i<=n;i++) {
			scanf("%s",s);len=strlen(s);
			int now=0;
			for (j=0;j<len;j++) {
				now=sa.getson(now,s[j]-'a');
				sa.setflag(now);
			}
		}
		m=sa.getnum();
    	mem0(w);
    	for (i=0;i<=m;i++) w[sa.getlen(i)]++;  
    	for (i=0;i<=len;i++) w[i]+=w[i-1];  
	    for (i=m;i>=0;i--) r[--w[sa.getlen(i)]]=i;  
 	    for (i=m;i>0;i--) {
			int to=sa.getfa(r[i]);
			if (sa.getflag(i)) sa.setflag(to); 
    	}
    	int ans=sa.dfs(0);
    	printf("Case #%d: ",cnt);
    	if (ans==0) printf("Impossible\n"); else {
    		int endpos=sa.getpos(ans);
    		for (i=endpos-sa.getlen(sa.getfa(ans));i<=endpos;i++)
    			printf("%c",s[i]);
    		printf("\n");
    	}
	}
	return 0;
}
