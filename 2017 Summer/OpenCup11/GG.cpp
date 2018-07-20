#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1<<20;
//typedef vector<ll> VEC;
ll arr1[MAXN],arr2[MAXN];
//Frac arr1[MAXN],arr2[MAXN];
int cnt1=0,cnt2=0;

ll a[100],b[100];
#define pb push_back
int main()
{
	int n;
	ll A,B;
	scanf("%d%lld%lld",&n,&A,&B);
	//Frac k=Frac(A,B);
	int m1=n/2,m2=n-m1;
	for(int i=0;i<m1;++i)
	{
		scanf("%lld%lld",a+i,b+i);
	}
	//Frac tmp;
	ll tmp;
	int ti;
	int j;
	for(int i=0;i<(1<<m1);++i)
	{
		tmp=0;
		/*for(int j=0;j<m1;++j)
		{
			if(i&(1<<j))	tmp=tmp+(a[j]-k*b[j]);
		}*/
		ti=i;
		j=0;
		while(ti)
		{
			if(ti&1)	tmp=tmp+(B*a[j]-A*b[j]);
			ti>>=1;
			j++;
		} 
		//arr1.pb(tmp);
		arr1[cnt1++]=tmp;
	}
	for(int i=0;i<m2;++i)
	{
		scanf("%lld%lld",a+i,b+i);
	}
	for(int i=0;i<(1<<m2);++i)
	{
		tmp=0;
		/*for(int j=0;j<m2;++j)
		{
			if(i&(1<<j))	tmp=tmp+(a[j]-k*b[j]);
		}*/
		//arr2.pb(tmp);
		ti=i;
		j=0;
		while(ti)
		{
			if(ti&1)	tmp=tmp+(B*a[j]-A*b[j]);
			ti>>=1;
			j++;
		}
		arr2[cnt2++]=tmp;
	}
	sort(arr2,arr2+cnt2);
	ll ans=0;
	//VEC::iterator lb,ub;
	int lb,ub;
	for(int i=0;i<cnt1;++i)
	{
		lb=lower_bound(arr2,arr2+cnt2,-arr1[i])-arr2;
		ub=upper_bound(arr2,arr2+cnt2,-arr1[i])-arr2;
		//ub=UB(-arr1[i]);
		//lb=LB(-arr1[i]);
		ans=ans+(ub-lb);
	}
	printf("%lld",ans-1);
	return 0;
}
