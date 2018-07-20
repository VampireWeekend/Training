#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=100000;
int n;
ull b[20];
struct node{
	ull v;
	int sum[20];
	bool operator<(node&a){
		int sum1[40],sum2[40];
		sum1[0]=sum2[0]=0;
		for (int i=sum[0];i;i--)sum1[++sum1[0]]=sum[i];
		for (int i=a.sum[0];i;i--)sum1[++sum1[0]]=a.sum[i];
		for (int i=a.sum[0];i;i--)sum2[++sum2[0]]=a.sum[i];
		for (int i=sum[0];i;i--)sum2[++sum2[0]]=sum[i];
		for (int i=1;i<=sum1[0];i++)
			if (sum1[i]!=sum2[i])
				return sum1[i]>sum2[i];
		return 0;
	}
	void getsum(){
		ull vv=v;
		while (vv)sum[++sum[0]]=vv%10,vv/=10;
	}
}a[N];
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	b[0]=1;
	
	for (int i=1;i<20;i++)b[i]=b[i-1]*10;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i].v);
		a[i].getsum();
	}
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (a[j]<a[i]) swap(a[i],a[j]);
		}
	}
	for (int i=1;i<=n;i++)
		printf("%I64d",a[i].v);
	return 0;
}
