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
const int maxn=25,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
int r[maxn][maxn],c[maxn][maxn];
int x11[16]={1,1,1,1,5,5,5,5,9,9,9,9,13,13,13,13},
    x22[16]={4,4,4,4,8,8,8,8,12,12,12,12,16,16,16,16},
    y11[16]={1,5,9,13,1,5,9,13,1,5,9,13,1,5,9,13},
    y22[16]={4,8,12,16,4,8,12,16,4,8,12,16,4,8,12,16};
int a[maxn][maxn][4];
char s[maxn][maxn];
int ans;

void rotate(int id,int re) {
/*    for (int i=x11[id];i<=x22[id];i++) {
        for (int j=y11[id];j<=y22[id];j++) {
            cout << a[i][j][re] << ' ';
        }
        cout << '\n';
    }*/
    for (int i=x11[id];i<=x22[id];i++) {
        for (int j=y11[id];j<=y22[id];j++) {
//            a[x22[id]-(j-y11[id])][i-x11[id]+y11[id]][re+1]=a[i][j][re];
            a[j-y11[id]+x11[id]][x22[id]-i+y11[id]][re+1]=a[i][j][re];
        }
    }
/*    for (int i=x11[id];i<=x22[id];i++) {
        for (int j=y11[id];j<=y22[id];j++) {
            cout << a[i][j][re+1] << ' ';
        }
        cout << '\n';
    }*/
}

void dfs(int id,int cost) {
    if (id==16) {
        ans=min(ans,cost);
        return;
    }
    for (int k=0;k<4;k++) {
        int flag=1;
        if (cost+k>ans) continue;
        for (int i=x11[id];i<=x22[id];i++) {
            for (int j=y11[id];j<=y22[id];j++) {
                if (r[i][a[i][j][k]]) {
                    flag=0;break;
                }
                if (c[j][a[i][j][k]]) {
                    flag=0;break;
                }
            }
        }
        if (flag) {
            for (int i=x11[id];i<=x22[id];i++) 
                for (int j=y11[id];j<=y22[id];j++) 
                    r[i][a[i][j][k]]=c[j][a[i][j][k]]=1;
            dfs(id+1,cost+k);
            for (int i=x11[id];i<=x22[id];i++) 
                for (int j=y11[id];j<=y22[id];j++) 
                    r[i][a[i][j][k]]=c[j][a[i][j][k]]=0;
        }
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        for (int i=1;i<=16;i++) {
            scanf("%s",s[i]+1);
            for (int j=1;j<=16;j++) {
                if (s[i][j]>='A'&&s[i][j]<='Z') {
                    a[i][j][0]=s[i][j]-'A'+10;
                } else a[i][j][0]=s[i][j]-'0';
            }
        }
        for (int j=0;j<=2;j++) {
            for (int k=0;k<16;k++) 
                rotate(k,j);
        }
    /*    for (int k=0;k<4;k++){
        for (int i=1;i<=16;i++) {
            for (int j=1;j<=16;j++) {
                cout << a[i][j][k] << ' ';
                if (a[i][j][k]<=9) cout << ' '; 
            }
            cout << '\n';
        }
        cout << '\n';}*/
        ans=inf;
        mem0(r);mem0(c);
        dfs(0,0);
        assert(ans!=inf);
        printf("%d\n",ans);
    }
    return 0;
}
