#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Frac
{
	ll p,q;	//  p/q
	Frac(ll _p=0,ll _q=1):p(_p),q(_q){simplify();}
	void simplify()
	{
		ll f=1;
		if(p<0)	p=-p,f=-f;
		if(q<0)	q=-q,f=-f;
		if(p==0){
			q=1;
			return;
		}
		ll g=__gcd(p,q);
		p/=g;
		q/=g;
		p=f*p;
	}
};
	Frac operator * (Frac y,Frac x)
	{
		return Frac(y.p*x.p,y.q*x.q);
	}
	Frac operator - (const Frac x)
	{
		return Frac(-x.p,x.q);
	}
	Frac operator + (Frac y,Frac x)
	{
		return Frac(y.p*x.q+y.q*x.p,y.q*x.q);
	}
	Frac operator -	(Frac const y,Frac const x)
	{
		return y+(-x);
	}
	bool operator < (Frac x,Frac y)
	{
		return (x-y).p<0;
	}
	bool operator <= (Frac x,Frac y)
	{
		return (x-y).p<=0;
	}

const int MAXN = 1<<20;
//typedef vector<Frac> VEC;
//VEC arr1,arr2;
Frac arr1[MAXN],arr2[MAXN];
int cnt1=0,cnt2=0;

int LB(Frac x)
{
	int l=0,r=cnt2,m;
	while(l<r)
	{
		m=(l+r)>>1; 
		if(arr2[m]<x)	l=m+1;
		else r=m;
	}
	return l;
}

int UB(Frac x)
{
	int l=0,r=cnt2,m;
	while(l<r)
	{
		m=(l+r)>>1;
		if(arr2[m]<=x)	l=m+1;
		else r=m;
	}
	return l;
}

ll a[100],b[100];
#define pb push_back
int main()
{
	int n;
	ll A,B;
	scanf("%d%lld%lld",&n,&A,&B);
	Frac k=Frac(A,B);
	int m1=n/2,m2=n-m1;
	for(int i=0;i<m1;++i)
	{
		scanf("%lld%lld",a+i,b+i);
	}
	Frac tmp;
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
			if(ti&1)	tmp=tmp+(a[j]-k*b[j]);
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
			if(ti&1)	tmp=tmp+(a[j]-k*b[j]);
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
		//lb=lower_bound(arr2,arr2+cnt2,-arr1[i])-arr2;
		//ub=upper_bound(arr2,arr2+cnt2,-arr1[i])-arr2;
		ub=UB(-arr1[i]);
		lb=LB(-arr1[i]);
		ans=ans+(ub-lb);
	}
	printf("%lld",ans-1);
	return 0;
}
