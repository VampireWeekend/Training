#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef int ll;
const int N=1000010;
int n,i,j,p[N],vis[N],q[N];
char a[N],b[N],c[N],S[N],T[N];
int nxt[N],w[N*4];
int ans=1;
int _a[N],_b[N],tot;
namespace NT{
int flag=1;
ll k=1,m,a,r,d,x,y;
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(!b)return x=1,y=0,a;
    ll d=exgcd(b,a%b,x,y),t=x;
    return x=y,y=t-a/b*y,d;
}
inline void add(ll a,ll r){
    if(r>=a)while(1);
    r%=a;
    if(!flag)return;
    d=exgcd(k,a,x,y);
    if((r-m)%d){flag=0;return;}
    x=(x*(r-m)/d+a/d)%(a/d),y=k/d*a,m=((x*k+m)%y)%y;
    if(m<0)m+=y;
    k=y;
}
void write(ll x){
    if(x>=10)write(x/10);
    int t=x%10;
    printf("%d",t);
}
void show(){
    if(flag)write(m);
    else puts("-1");
}
}
inline void solve(int len){
    int i,j,k,cnt=0;
    for(i=1;i<=len;i++)T[i]=b[q[i]],S[i]=a[q[i]];
    //printf("len=%d\n",len);
    //for(i=1;i<=len;i++)putchar(T[i]);puts("");
    //for(i=1;i<=len;i++)putchar(S[i]);puts("");
    for(nxt[1]=j=0,i=2;i<=len;nxt[i++]=j){
        while(j&&S[j+1]!=S[i])j=nxt[j];
        if(S[j+1]==S[i])j++;
    }
    //for(i=1;i<=len;i++)printf("nxt[%d]=%d\n",i,nxt[i]);
    for(i=1,j=0,k=1;i<=len*3;i++){
        while(j&&S[j+1]!=T[k])j=nxt[j];
        if(S[j+1]==T[k]){
            j++;
            if(j==len){
                w[++cnt]=i-len;
                j=nxt[j];
                //printf("find %d\n",i);
            }
        }
        k++;
        if(k>len)k=1;
    }
    if(!cnt){
        puts("-1");
        exit(0);
    }
//    if(cnt<2)while(1);
 //   for(i=2;i<=cnt;i++)if(w[i]-w[i-1]!=w[2]-w[1])while(1);
    //printf("per=%d occ=%d\n",w[2]-w[1],w[1]);
    NT::add(w[2]-w[1],w[1]);
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1);
    for(i=1;i<=n;i++){
        int x;
        if(i<=n/2)x=i*2-1;
        else x=i*2-n;
        //printf("! %d %d\n",i,x);
        p[x]=i;
    }
    for(i=1;i<=n;i++)if(!vis[i]){
        int cnt=0;
        for(j=i;!vis[j];j=p[j])vis[j]=1,q[++cnt]=j;
        //for(j=1;j<=cnt;j++)printf("%d ",q[j]);puts("");
        solve(cnt);
    }
    NT::show();
}
/*
aaababbbbbbabbbbab
aabbabbababbbabbbb
 
 
babaaabbaa
bbaaaababa
*/
