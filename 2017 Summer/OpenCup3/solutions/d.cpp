#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX_CITIS = 2e5+1;
int n,m,d,a,b;
std::vector<int> tab[MAX_CITIS];
int pozostalo[MAX_CITIS];

void dfs(int i){
	pozostalo[i]=MAX_CITIS*10;
	for(auto sa:tab[i])
		if((--pozostalo[sa])<d)
			dfs(sa);
}

std::vector<int> tmp,wyn;
void dfs2(int i){
	tmp.push_back(i);
	pozostalo[i]=MAX_CITIS*10;
	for(auto sa:tab[i])
		if(pozostalo[sa]<MAX_CITIS*5)
			dfs2(sa);
}

int main(){
	cin>>n>>m>>d;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		tab[a].push_back(b);
		tab[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		pozostalo[i]=tab[i].size();
	}
	for(int i=1;i<=n;i++){
		if(pozostalo[i]<d)
			dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(pozostalo[i]<MAX_CITIS*5){
			dfs2(i);
			if(tmp.size()>wyn.size())
				swap(wyn,tmp);
			tmp.clear();
		}
	}
	if(wyn.empty())
		cout<<"NIE"<<endl;
	if(wyn.size()>= (std::size_t)d){
		cout<<wyn.size()<<endl;
		sort(wyn.begin(),wyn.end());
		for(auto x:wyn)
			cout<<x<<" ";
		cout<<endl;
	}
}
