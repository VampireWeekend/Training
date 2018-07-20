//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<map>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
const   int oo=1e9;
const   int mm=12000;
const   int mn=3000;
int node,src,dest,edge;
int ver[mm],flow[mm],cost[mm],nex[mm];
int head[mn],dis[mn],p[mn],q[mn],vis[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; i++)head[i]=-1,vis[i]=0;
    edge=0;
}
void addedge(int u,int v,int f,int c)///起点，终点，流量，费用
{
    ver[edge]=v,flow[edge]=f,cost[edge]=c,nex[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,nex[edge]=head[v],head[v]=edge++;
}
bool spfa()/**spfa 求最短路，并用 p 记录最短路上的边*/
{
    int i,u,v,l,r=0,tmp;
    for(i=0; i<node; ++i)dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for(l=0; l!=r; (++l>=mn)?l=0:l)
        for(i=head[u=q[l]],vis[u]=0; i>=0; i=nex[i])
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v]) continue;
                vis[q[r++]=v]=1;
                if(r>=mn)r=0;
            }
    return p[dest]>-1;
}
void SpfaFlow(int k)/**源点到汇点的一条最短路即可行流，不断的找这样的可行流*/
{
    int i,delta,ans=oo,res=k,last_path_len=0,pessnum_per_sec=0;
    while(spfa())
    {
        for(i=p[dest],delta=oo; i>=0; i=p[ver[i]])
            if(flow[i^1]<delta)delta=flow[i^1];
        for(i=p[dest]; i>=0; i=p[ver[i]])
            flow[i]+=delta,flow[i^1]-=delta;
        //cout<<"长度:"<<dis[dest]<<"    容量:"<<delta<<endl;
        res-=(dis[dest]-last_path_len)*pessnum_per_sec+delta;///该路径跑满时之前所有路径包括该路径跑过的总人数
        //cout<<"res="<<res<<endl;
        last_path_len=dis[dest];
        pessnum_per_sec+=delta;
        int temp=res;
        if(temp<0)temp=0;
        int n_ans=last_path_len+(int)ceil(1.0*temp/pessnum_per_sec);///res个人跑满该路径及之前所有路径所需最短时间
        if(n_ans<ans) ans=n_ans;
        if(res<=0) break;///没有跑满流就完成了
        //cout<<"ans="<<ans<<endl;
    }
    if(ans==oo)puts("No solution");
    else printf("%d\n",ans);
}
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        prepare(n,0,n-1);
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c,1);
        }
        if(!k)
            puts("0");
        else
            SpfaFlow(k);
    }
    return 0;
}

