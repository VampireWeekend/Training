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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define P1 39916801
#define P2 4987657
#define INF 100000007
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn],cntx[maxn],id[maxn];
char s[maxn];
vector<int> vl[maxn],vr[maxn];

const int N = 500005;
struct node{
    int v,rnd,size;
    node *ch[2],*pa;       
}pool[N];
int cnt;

int rr=0x34ab4;
int Getrnd(){ 
	rr=((ll)rr*P1)%P2;
    return rr; 
}

struct treap{
    node *root,*rf;
    int size(node *p){
        return p?p->size:0;    
    }
    void update(node *p){
        p->size=size(p->ch[0])+size(p->ch[1])+1;     
    }
    void rotate(node *p,int t){
        node *son=p->ch[!t],*pa=p->pa,*gp=p->pa->pa;
        pa->ch[t]=son;
        if(son) son->pa=pa;
        p->ch[!t]=pa;
        pa->pa=p;
        p->pa=gp;
        gp->ch[pa==gp->ch[1]]=p;
        if(root==pa) root=p;
        update(pa);update(p); 
    }
    void insert(node *p,node *nd){
        int f=p->v<nd->v?1:0;
        if(!p->ch[f]){
            p->ch[f]=nd;
            nd->pa=p;              
        }
        else insert(p->ch[f],nd);
        update(p);
        if(p->ch[f]->rnd>p->rnd) rotate(p->ch[f],f);
    }
    void Ins(int v){
        node *nd=&pool[++cnt];
        nd->v=v;nd->size=1;nd->rnd=Getrnd();
        nd->pa=nd->ch[0]=nd->ch[1]=NULL;
        if(root) insert(root,nd);
        else{
            root=nd;
            root->pa=rf;
            rf->ch[1]=root;
        }
    }
    void del(node *p,int v){ //删除 注意向上更新处容易写错
        if(p->v==v){
            if(!p->ch[0] || !p->ch[1]){
                node *pa=p->pa,*son=p->ch[p->ch[0]?0:1];
                pa->ch[p==pa->ch[1]]=son;
                if(son) son->pa=pa;
                if(p==root) root=son;
                while(pa)
                    update(pa),pa=pa->pa;
            }
            else{
                int f=p->ch[1]->rnd>p->ch[0]->rnd?1:0;
                rotate(p->ch[f],f);del(p,v);
            }
        }
        else del(p->ch[v>p->v],v);
    }
    int rank(node *p,int v){ //比v小的节点个数
        if(!p) return 0;
        if(p->v<v) return 1+size(p->ch[0])+rank(p->ch[1],v);
        else return rank(p->ch[0],v);
    }
    int find(node *p,int k){ //询问排名第k的节点值
        if(size(p->ch[0])>=k) return find(p->ch[0],k);
        if(size(p->ch[0])==k-1) return p->v;
        return find(p->ch[1],k-size(p->ch[0])-1);
    }
    int pre(node *p,int v){//前驱
        if(!p) return -INF;
        if(v>p->v) return max(p->v,pre(p->ch[1],v));
        else return pre(p->ch[0],v);
    }
    int sub(node *p,int v){//后继
        if(!p) return INF;
        if(v<p->v) return min(p->v,sub(p->ch[0],v));
        else return sub(p->ch[1],v);
    }
    void inorder(node *p){
        if(p->ch[0]) inorder(p->ch[0]);
        printf("%d ",p->v);
        if(p->ch[1]) inorder(p->ch[1]);     
    }
}tr;
queue<int> qq[maxn];
struct edge{
	int l, r, stu = 1;
}rem[maxn];

int sumv[maxn]; //
int lowbit(int x){ return x &(-x) ;} 

void addvc(int x){
	for(int i = x; i < maxn; i += lowbit(i))
		sumv[i] += 1;
}

int sum(int x){
	int ans = 0;
	for(int i = x; i > 0; i -= lowbit(i))
		ans += sumv[i];
	return ans; 
}

int main() {
	int n,qn;
	tr.rf=&pool[++cnt];
	while (scanf("%d%d",&n,&qn)!=EOF) {
		for (int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
		}
		int l,r,m=0;
		for (int i=1;i<=qn;i++) {
			scanf("%s",s);
			scanf("%d%d",&l,&r);
			if (s[0]=='q') {
				rem[i].l = l;
				rem[i].r = r;
				rem[i].stu = 1;
			} else {
				rem[i].stu = 0;
				vl[l].pb(i);
				vr[r].pb(i);
			}
		}
		for (int i=1;i<=n;i++) {
			int size=vl[i].size();
			for (int j=0;j<size;j++) {
				tr.Ins(vl[i][j]);
			}
			size=tr.size(tr.root);
			for (int j=a[i];j<=size;j+=a[i]) {
				int nid=tr.find(tr.root,j);
				qq[nid].push(i);
			}
			size=vr[i].size();
			for (int j=0;j<size;j++) {
				tr.del(tr.root,vr[i][j]);
			}
		}
		
		for(int i = 1; i <= qn; i ++){
			if(rem[i].stu){
				printf("%d\n", sum(rem[i].r)-sum(rem[i].l-1));
			}
			else{
				while(!qq[i].empty()){
					addvc(qq[i].front()); 
					qq[i].pop(); 
				}
			}
		}
		for(int i = 0; i <= n; i ++) {
			vl[i].clear();vr[i].clear();
			sumv[i] = 0;
		}
	}
	return 0;
}
