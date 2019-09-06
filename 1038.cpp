#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string s1,string s2){
	return s1+s2<s2+s1;
}
int main(){
	int n;
	char t[10];
	scanf("%d",&n);
	vector<string> a(n);
	for(int i=0;i<n;i++){
		scanf("%s",t);
		a[i]=t;
	}
	sort(a.begin(),a.end(),cmp);
	string res;
	for(int i=0;i<n;i++)
	   res+=a[i];
	while(res.length()!=0&&res[0]=='0') res.erase(0,1);
	if(res.length()==0) cout<<"0";
	else cout<<res;
	return 0;
}
