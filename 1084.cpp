#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
int main(){
	string s1,s2;
	int i,j,cnt;
	int v[1001]={0};
	int flag[1001]={0};
	set<char> s;
	map<char,int> mp;
	cin>>s1>>s2;
	for(i=0;i<s1.length();i++) {
		v[i]=1;
		if(s1[i]>='a'&&s1[i]<='z') s1[i]=s1[i]-32;
		mp[s1[i]]=1;
	}
	for(i=0;i<s2.length();i++) {
		if(s2[i]>='a'&&s2[i]<='z') s2[i]=s2[i]-32;
	}	
	for(i=0;i<s2.length();i++){
		for(j=0;j<s1.length();j++){
	   	if(s1[j]==s2[i]) v[j]=0;
	   }
	}
    for(i=0;i<s1.length();i++)
    if(v[i]==1&&mp[s1[i]]==1){
    	mp[s1[i]]=0;
    	cout<<s1[i];
	}
    return 0;
}


