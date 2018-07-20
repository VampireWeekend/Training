#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[20],b[20];

int main() {
	int t,q,n,i,j,flag;
	cin >> q;
	for (t=1;t<=q;t++) {
		cin >> n;
		flag=1;
		for (i=1;i<=n;i++) {
			cin >> a[i];
			if (a[i]!=a[i-1]&&i!=1) flag=0;
		}
		int k=-0x3f3f3f3f,l=0x3f3f3f3f;
		int kk=0,ll=0;
		i=0;
		if (!flag)
		while (i<1000000) {
			i++;
			flag=0;
			k=-0x3f3f3f3f,l=0x3f3f3f3f;
			for (j=1;j<=n;j++) {
				if (a[j]>k) {
					k=max(k,a[j]);
					kk=j;
				}
				if (a[j]<l) {
					l=min(l,a[j]);
					ll=j;
				}
			}
			if (l==k) 
				break;
			int num=0;
			for (j=1;j<=n;j++) {
				if (j!=ll&&j!=kk) {
					b[++num]=a[j];
				}
			}
			b[n-1]=b[n]=k-l;
			for (j=1;j<=n;j++) a[j]=b[j];
		}
		else l=a[1];
		if (i<1000000) cout << l << endl; else cout << "Nooooooo!" << endl;
	}
	return 0;
}
