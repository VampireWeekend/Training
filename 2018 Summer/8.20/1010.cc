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
int a[5],b[5];

int main() {
  int cas;
  scanf("%d",&cas);
  while (cas--) {
    int lena,lenb;
    scanf("%d%d",&lena,&lenb);
    int ans;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    int flag=1;
    if (lena<lenb) {
      flag=-1;
      swap(lena,lenb);swap(a,b);
    }
    if (lena==1&&lenb==1) {
      if (a[1]>b[1]) ans=-1 else if (b[1]>a[1]) ans=1; else ans=0;
    }
    if (lena==2&&lenb==2) {
      if (min(a[1]+2,a[2]+1)>min(b[1]+2,b[2]+1)) ans=-1; else
        if (min(a[1]+2,a[2]+1)<min(b[1]+2,b[2]+1))  ans=1; else
          if (max(a[1]+2,a[2]+1)>max(b[1]+2,b[2]+1)) ans=-1; else
            if (max(a[1]+2,a[2]+1)<max(b[1]+2,b[2]+1)) ans=1;  else ans=0;
    }
    if (lena==1&&lenb==2) {
      if (a[1]+2>min(b[1]+2,b[2]+1)) ans=-1; else
        if (a[1]+2<min(b[1]+2,b[2]+1)) ans=1;
          else ans=0;    //need to note
    }
    if (lena==1&&lenb==3) {
      if (a[1]+2>min(b[1]+2,min(b[2]+1,b[3]))) ans=-1; else
        if (a[1]+2<min(b[1]+2,min(b[2]+1,b[3]))) ans=1; else ans=0;  //ans=0 need to note
    }
/*    if (lena==2&&lenb==3) {
      if (min(a[1]+2,a[2]+1)>min(b[1]+2,min(b[2]+1,b[3]))) ans=-1; else
        if (min(a[1]+2,a[2]+1)<min(b[1]+2,min(b[2]+1,b[3]))) ans=1; else {
          if (a[1]+2<=a[2]+1&&b[1]+2<=min(b[2]+1,b[3])) {
            if (a[2]+1>min(b[2]+1,b[3])) ans=-1; else if (a[2]+1<min(b[2]+1,b[3])) ans=1; else ans=0;
          }
          if (a[1]+2>a[2]+1&&b[1]+2<=min(b[2]+1,b[3])) {
            if (a[1]+2>min(b[2]+1,b[3])) ans=-1; else if (a[1]+2<min(b[2]+1,b[3])) ans=1; else ans=0;
          }
          if (a[1]+2<=a[2]+1&&b[1]+2>min(b[2]+1,b[3])) {
            if (a[2]+1>b[1]+2) ans=-1; else if (a[2]+1<b[1]+2) ans=1; else ans=0;
          }
          if (a[1]+2>a[2]+1&&b[1]+2>min(b[2]+1,b[3])) {
            if (a[1]>b[1]) ans=-1; else if (b[1]>a[1]) ans=1; else ans=0;
          }
        }
    }*/
    if (lena==3&&lenb==3) {
      if (min(a[1]+2,min(a[2]+1,a[3]))>min(b[1]+2,min(b[2]+1,b[3]))) ans=-1; else
        if (min(a[1]+2,min(a[2]+1,a[3]))<min(b[1]+2,min(b[2]+1,b[3]))) ans=1; else {
          if (a[1]+2<=min(a[2]+1,a[3])&&b[1]+2<=min(b[2]+1,b[3])) {
            if (min(a[2]+1,a[3])>min(b[2]+1,b[3])) ans=-1; else if (min(a[2]+1,a[3])<min(b[2]+1,b[3])) ans=1; else ans=0;
          }
          if (a[1]+2>min(a[2]+1,a[3])&&b[1]+2<=min(b[2]+1,b[3])) {
            if (a[1]+2>min(b[2]+1,b[3])) ans=-1; else if (a[1]+2<min(b[2]+1,b[3])) ans=1; else ans=0;
          }
          if (a[1]+2<=min(a[2]+1,a[3])&&b[1]+2>min(b[2]+1,b[3])) {
            if (min(a[2]+1,a[3])>b[1]+2) ans=-1; else if (min(a[2]+1,a[3])<b[1]+2) ans=1; else ans=0;
          }
          if (a[1]+2>min(a[2]+1,a[3])&&b[1]+2>min(b[2]+1,b[3])) {
            if (a[1]>b[1]) ans=-1; else if (b[1]>a[1]) ans=1; else ans=0;
          }
        }
    }
    ans*=flag;
    printf("%d\n",ans);
  }
	return 0;
}
