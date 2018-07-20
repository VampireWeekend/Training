#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int n, T;
double E, ans[MAXN], arr[MAXN];
int maxp, minp;
int main(){
    scanf("%d", &T);
    while(T --){
        double maxv = -1, minv = 1001010;
        scanf("%d%lf", &n, &E);
        for(int i = 1; i <= n; i ++){
            scanf("%lf", &arr[i]);
            if(maxv < arr[i])
                maxp = i;
            if(minv > arr[i])
                minp = i;
            maxv = max(maxv, arr[i]);
            minv = min(minv, arr[i]);
        }
        //printf("test : %d %d\n", minp, maxp);
        if(minv == E && maxv == E){
            printf("1");
            for(int i = 2; i <= n; i ++)
                printf(" %d", 0);
            puts("");
            continue;
        }
        if(minv <= E && maxv >= E){
            ans[maxp] = (E - minv) / (maxv - minv);
            ans[minp] = 1 - ans[maxp];
            //ans[minp] = (E - maxv) / (minv - maxv);
            for(int i = 1; i <= n; i ++)
                printf("%.7lf ", ans[i]);
            puts("");
            ans[minp] = ans[maxp] = 0;
        }
        else
            puts("-1");
    }
    return 0;
}

