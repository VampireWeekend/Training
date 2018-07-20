#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n,i,du=0,father,son;
	scanf("%d",&n);
		for (i=1;i<=n-1;i++) {
			scanf("%d%d",&father,&son);
			if (father==1||son==1) du++;
		}
	if (du%2) cout << "Alice"; else cout << "Bob";
}
