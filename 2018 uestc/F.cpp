#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL mod1 = 1e9+7;
const LL mod2 = 1e9+9;
const LL r2 = 4116649;
const LL r3 = 1696021;
LL qpow(LL x, int p, LL mod){
    LL ans = 1;
    while(p){
        if(p & 1)
            ans = ans * x % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}
int n, m;
map<int, int> mp;
char ch[1010][1010];
LL tem1[1010][1010];
LL rem1[1010][1010];
LL pow2[1010], pow3[1010];

LL cal(int x1, int y1, int x2, int y2){
    LL ans = rem1[x2+1][y2+1];
    //printf("x2+1 :%d  y2+1: %d \t %lld\n", x2+1, y2+1, ans);
    ans = (ans + mod1 - rem1[x1][y2+1]) % mod1;
    ans = (ans + mod1 - rem1[x2+1][y1]) % mod1;
    ans = (ans + rem1[x1][y1]) % mod1;
    //printf("sum = %d\n", ans);
    ans = ans * qpow(pow2[y1], mod1-2, mod1) % mod1;
    ans = ans * qpow(pow3[x1], mod1-2, mod1) % mod1;
    return ans;
}

int divide(int u1,int l1,int d1,int r1,int u2,int l2,int d2,int r2) {
	if (u1==d1&&l1==r1)
		return ch[u1][l1]!=ch[u2][l2];
	if (abs(u1-d1)<=1&&abs(l1-r1)<=1) return 0;
	LL h11,h21,h12,h13,h14,h22,h23,h24;
	h11=cal(u1,l1,(u1+d1)/2,(r1+l1)/2);
	h21=cal(u2,l2,(u2+d2)/2,(r2+l2)/2);
	h12=cal(u1,(l1+r1)/2+1,(u1+d1)/2,r1);
	h22=cal(u2,(l2+r2)/2+1,(u2+d2)/2,r2);
	h13=cal((u1+d1)/2+1,l1,d1,(r1+l1)/2);
	h23=cal((u2+d2)/2+1,l2,d2,(r2+l2)/2);
	h14=cal((u1+d1)/2+1,(l1+r1)/2+1,d1,r1);
	h24=cal((u2+d2)/2+1,(l2+r2)/2+1,d2,r2);
	int cnt=(h11!=h21)+(h12!=h22)+(h13!=h23)+(h14!=h24);
	if (cnt>1) return cnt;
//	if (cnt==0) return 0;
	if (h11!=h21) return divide(u,l,(u+d)/2,(r+l)/2);
	if (h12!=h22) return divide(u,(l+r)/2+1,(u+d)/2,r);
	if (h13!=h23) return divide((u+d)/2+1,l,d,(r+l)/2);
	return divide((u+d)/2+1,(l+r)/2+1,d,r);
}

void proc(){
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &a1, &b1, &a2, &b2);
    LL val1 = cal(x1, y1, x2, y2);
    LL val2 = cal(a1, b1, a2, b2);
    
    if(val1 == val2){
        printf("Perfect\n");
        return ;
    }
    else {
    	int p=mp[(val1-val2+mod1)%mod1];
    	int i=p/1e4,j=p%1e4; 
    	if ()
    }if(mp.find(abs(val1-val2)) != mp.end() || mp.find(abs((val1+mod1-val2) %mod1)) != mp.end())
        printf("One difference\n");
    else
        printf("Wrong\n");
    
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%s", ch[i] + 1);
    LL rec = 1;
    pow2[0] = pow3[0] = 1;
    for(int i = 0; i <= 1000; i ++){
        pow2[i+1] = pow2[i] * r2 % mod1;
        pow3[i+1] = pow3[i] * r3 % mod1;
        LL tmp = rec;
        for(int j = 0; j <= 1000; j ++){
            mp[tmp] = i*1e4+j;
            tmp = tmp * r2 % mod1;
        }
        rec = rec * r3 % mod1;
    }
        
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            tem1[i][j] = (tem1[i][j-1] + (ch[i][j] - '0') * pow2[j-1]) % mod1;
        }
    }
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
           rem1[i][j] = (rem1[i-1][j] + tem1[i][j] * pow3[i-1]) % mod1;
        }
    }
    
    int T;
    scanf("%d", &T);
    while(T--){
        proc();
    }
}

/*

3 3
010
010
110
2
0 1 1 2 1 1 2 2
0 0 1 1 1 0 2 1



3 3
110
010
110
2
0 1 1 2 1 1 2 2
0 0 1 1 1 0 2 1

*/
