#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int i,n;
	vector<string> list,temp(56);
	vector<int>  a(56);
	scanf("%d",&n);
	list.push_back("");
	for(i=1;i<=13;i++) list.push_back("S"+to_string(i));
    for(i=1;i<=13;i++) list.push_back("H"+to_string(i));
    for(i=1;i<=13;i++) list.push_back("C"+to_string(i));
    for(i=1;i<=13;i++) list.push_back("D"+to_string(i));
    list.push_back("J1");list.push_back("J2");
	for(i=1;i<=54;i++) scanf("%d",&a[i]);
	while(n--){
		temp.clear();
		for(i=1;i<=54;i++) temp[a[i]]=list[i];			 
		for(i=1;i<=54;i++) list[i]=temp[i];
	}
	cout<<list[1];
	for(i=2;i<=54;i++) cout<<" "<<list[i];
	return 0;
}
