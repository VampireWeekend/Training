#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map> 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1005,maxk=2,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db r[maxn][maxn],ans[maxn];
int b[maxn][maxn];
char s[maxn],t[maxn];
int num;
 
struct node{
	struct node *fail;
	struct node *next[maxk];
	int cnt,id,l;
	void init() {
		fail=NULL;
		for (int i=0;i<maxk;i++) next[i]=NULL;
		cnt=l=0;
		id=++num;
	}
};
node *a[maxn],*q[maxn];
 
void insert(int h,node *root,int len) {
	node *now=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=b[h][i];
		if (now->next[pos]==NULL) {
	    	now->next[pos]=new node;
	    	now->next[pos]->init();
	    	a[num]=now->next[pos];
    	}
    	now=now->next[pos];
	}
	now->cnt++;now->l=h;
}
 
void buildfail(node *root) {
	node *p=root;
	int front=0,tail=0,i;
	for (i=0;i<maxk;i++) {
		if (p->next[i]!=NULL) {
			p->next[i]->fail=root;
			q[tail++]=p->next[i];
		} else p->next[i]=root;
	}
	while (front<tail) {
		p=q[front];
		for (i=0;i<maxk;i++) {
			if (p->next[i]==NULL) 
			    p->next[i]=p->fail->next[i];
			else {
				node *x=p->fail;
				while (x!=NULL) {
					if (x->next[i]!=NULL) {
						p->next[i]->fail=x->next[i];
						break;
					}
					x=x->fail;
				}
				if (p->fail->next[i]->cnt) p->next[i]->cnt++;
				q[tail++]=p->next[i];
			}
		}
		front++;
	}
}
 
bool gauss(int size) {  
    int i,j,k;  
    for (i=0;i<size;i++) {  
        k=i;  
        for (j=i+1;j<size;j++) {  
            if (fabs(r[j][i])>fabs(r[k][i])) k=j;  
        }  
 //       if (fabs(r[k][i])<1e-9) return false;    //fail  
        for (j=i;j<=size;j++) 
            swap(r[k][j],r[i][j]);
        db t=r[i][i];
		for (j=i;j<=size;j++) 
            r[i][j]/=t;
        for (j=0;j<size;j++) {  
            if (i==j) continue;  
			db t=r[j][i]; 
            for (k=i;k<=size;k++) {  
                r[j][k]-=t*r[i][k];  
            }  
        }  
    }
//    for (i=size-1;i>=0;i--)
//       r[i][size]=r[i][size]/r[i][i];  
    return true;
}  
 
int main() {
	map<char,int> mp;
	mp['H']=0;mp['T']=1;
		int n,i,j,k;
		scanf("%s",s);
		scanf("%s",t);
		int l1=strlen(s),l2=strlen(t);
		node *root=new node;
		num=-1;
		root->init();
		a[0]=root;
			for (j=0;j<l1;j++) {
				b[1][j]=mp[s[j]];
			}
			insert(1,root,l1);
			for (j=0;j<l2;j++) {
				b[2][j]=mp[t[j]];
			}
			insert(2,root,l2);
		buildfail(root);
		mem0(r);
		for (j=0;j<=num;j++) {
			r[j][j]+=1.0;
			if (a[j]->cnt!=0) continue;
			for (k=0;k<2;k++) 
				r[a[j]->next[k]->id][j]-=1.0/2.0;
		}
		r[0][num+1]=1.0;
		db tot=0.0;
		gauss(num+1);
		node *n1,*n2;
		n1=n2=root;
		for (i=0;i<l1;i++) {
			n1=n1->next[b[1][i]];
		}
		for (i=0;i<l2;i++) {
			n2=n2->next[b[2][i]];
		}
		int flag=1;
		if (l1<l2) {
			for (i=0;i<l1;i++) {
				if (s[i]!=t[i+l2-l1]) flag=0;
			} 
		} else {
			for (i=0;i<l2;i++) {
				if (t[i]!=s[i+l1-l2]) flag=0;
			} 
		}
		if (flag) {
			if (l1<l2) {
				printf("%.10lf\n",1-r[n2->id][num+1]);
				printf("0.0000000000\n");
				printf("%.10lf\n",r[n2->id][num+1]);
			} else {
				printf("0.0000000000\n");
				printf("%.10lf\n",1-r[n1->id][num+1]);
				printf("%.10lf\n",r[n1->id][num+1]);
			}
		} else {
			tot=r[n1->id][num+1]+r[n2->id][num+1];
			printf("%.10lf\n",r[n1->id][num+1]/tot);
			printf("%.10lf\n",r[n2->id][num+1]/tot);
			printf("0.0000000000\n");
		}
	return 0;
}
