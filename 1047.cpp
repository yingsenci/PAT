#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<string> > list;
int main(){
	int n,m,k,num;
	char temp[5];
	string name;
	scanf("%d %d",&n,&m);
	list.resize(m+1);
	while(n--){
		cin>>name;
		scanf("%d",&k);
		while(k--){
			scanf("%d",&num);
			list[num].push_back(name);
		}
	}
	for(int i=1;i<list.size();i++){
		printf("%d %d\n",i,list[i].size());
		sort(list[i].begin(),list[i].end());
		for(auto str:list[i]) printf("%s\n",str.c_str());
	}
	return 0;
}
