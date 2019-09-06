#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct info{
	string name;
	string id;
	int grade;
};
bool cmp(info a,info b){
	if(a.grade!=b.grade) return a.grade>b.grade;
}
vector<info> list,ans;
using namespace std;
int main(){
	int n,i,tg;
	string t1,t2;
	info temp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>t1>>t2;
		scanf("%d",&tg);
		temp.grade=tg;temp.name=t1;temp.id=t2;
		list.push_back(temp);
	}
	int x1,x2;
	cin>>x1>>x2;
	sort(list.begin(),list.end(),cmp);
	for(i=0;i<n;i++)
	 if(list[i].grade>=x1&&list[i].grade<=x2)
	 ans.push_back(list[i]);
	if(ans.size()!=0){
		for(i=0;i<ans.size();i++)
		cout<<ans[i].name<<' '<<ans[i].id<<endl;
	}
	else printf("NONE");
	return 0;
}
