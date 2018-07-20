#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int big=-1000000001,sig,a,b,c;
  //  cout << big << endl;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a>big){
            big = a;
            sig = i;
        }
    }
    b = sig - 1;
    if(b==0)b=n;
    c = sig+1;
    if(c==n+1)c = 1;
    printf("%d %d %d",b,sig,c);
    return 0;
}
