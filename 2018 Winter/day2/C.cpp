#include <cstdio>
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
//����ֿ� 
//���http://blog.csdn.net/aozil_yang/article/details/62396346
using namespace std;
typedef long long ll;
vector<int> v[200001];
int a[200001],l[200001],r[200001],kuai[200001];
int n,q,i,j,k,block,num,x,y;
ll ans;

void divide (int n) {                   //���� 
	block=sqrt(n);
	num=(n/block)+(n%block!=0);
	for (i=1;i<=num;i++){               //��i�������硢�ҽ� 
		l[i]=(i-1)*block+1;
		r[i]=i*block;
	}
	r[num]=n;
	for (i=1;i<=n;i++){                 //��i��Ԫ�����ڵ�kuai[i]���� 
		kuai[i]=(i-1)/block+1;
	}
    for (i=1;i<=num;i++) {              //vector����
    	for (j=l[i];j<=r[i];j++) {
    		v[i].push_back(a[j]);
    	}
    } 
}

int query(int lc,int rc,int value) {     //����[l,r]��С��value��Ԫ�ظ��� 
	int sum=0;
	if (lc>rc) return 0;
	if (kuai[lc]==kuai[rc]) {           //ͬ��ֱ�ӱ�������ͬ���������鱩�����м���� 
		for (i=lc;i<=rc;i++) {
			if (a[i]<value) sum++;
		}
		return sum;
	} else {
		for (i=lc;i<=r[kuai[lc]];i++) {
			if (a[i]<value) sum++;
		}
		for (i=l[kuai[rc]];i<=rc;i++) {
			if (a[i]<value) sum++;
		}
		for (i=kuai[lc]+1;i<=kuai[rc]-1;i++) {
			int lwb=lower_bound(v[i].begin(),v[i].end(),value)-v[i].begin();
			sum+=lwb;
		} 
		return sum;
	}
}

void update(int lc,int rc) {
	if (kuai[lc]!=kuai[rc]) {
		int mark=kuai[lc];
		v[mark].erase(lower_bound(v[mark].begin(),v[mark].end(),a[lc]));
		v[mark].insert(lower_bound(v[mark].begin(),v[mark].end(),a[rc]),a[rc]);
		mark=kuai[rc];
		v[mark].erase(lower_bound(v[mark].begin(),v[mark].end(),a[rc]));
		v[mark].insert(lower_bound(v[mark].begin(),v[mark].end(),a[lc]),a[lc]);
	}
}

int main () {
	cin >> n >> q;
	for (i=1;i<=n;i++) a[i]=i;
	divide(n); 
	ans=0;
	for (k=1;k<=q;k++) {
		cin >> x >> y;
		if (x>y) {
			int z=x;x=y;y=z;
		}
		if (x==y) {           //�������������ans 
			cout << ans << endl;
		} else {
			int t=query(x+1,y-1,a[x]);
			ans+=((y-x-1-t));
			ans-=t;
			t=query(x+1,y-1,a[y]);
			ans-=((y-x-1-t));
			ans+=t;
			if (a[x]<a[y]) ans++; else ans--;
			cout << ans << endl;
		}
		update(x,y);                      //���¿���Ԫ�أ��������� 
		int q=a[x];a[x]=a[y];a[y]=q;
	}
	return 0;
} 
