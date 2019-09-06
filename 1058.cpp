#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	string s1,s2;
	vector<int> a,b,ans(3);
	string s;
	int i=0,j=0;
	cin>>s1>>s2;
	while(j<s1.length()){
		while(j<s1.length()&&s1[j]!='.')j++;
	    s=s1.substr(i,j-i);
	    a.push_back(stoi(s));
	    j++;
	    i=j;
	}
	i=j=0;
    while(j<s2.length()){
		while(j<s2.length()&&s2[j]!='.')j++;
	    s=s2.substr(i,j-i);
	    b.push_back(stoi(s));
	    j++;
	    i=j;
	}
	int c;
	ans[2]=(a[2]+b[2])%29;
	c=(a[2]+b[2])/29;
	ans[1]=(a[1]+b[1]+c)%17;
    c=(a[1]+b[1]+c)/17;
    ans[0]=(a[0]+b[0]+c);
    cout<<ans[0]<<"."<<ans[1]<<"."<<ans[2];
	return 0;
}
