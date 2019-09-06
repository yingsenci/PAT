#include<cstdio>
#include<unordered_map>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

unordered_map<string, set<int> > Hash;

int main(){
	int n,m;
	char name[6];
	scanf("%d %d",&n,&m);
	while(m--){
		int index,k;
		scanf("%d %d",&index,&k);
		while(k--){
			scanf("%s",name);
			string na=name;
			Hash[na].insert(index);
		}
	} 
	while(n--){
		scanf("%s",name);
		string na=name;
		if(Hash[na].size()==0){
			printf("%s 0\n",name);
			continue;
		}
		//sort(Hash[na].begin(),Hash[na].end());
		printf("%s %d",name,Hash[na].size());
		for(auto i:Hash[na]) printf(" %d",i);
		printf("\n");
	}
	return 0;
}
