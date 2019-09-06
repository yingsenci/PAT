#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	string s;
	vector<int> a1,a2;
	cin>>s;
	int countp=0,countt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='P') countp++;
		if(s[i]=='A') a1.push_back(countp);
	}
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='T') countt++;
		if(s[i]=='A') a2.push_back(countt);	    	
	}
    int sum=0,len=a1.size();
    for(int i=0;i<len;i++)
      sum=(sum+(a1[i]*a2[len-i-1]))%1000000007;
    cout<<sum;
    return 0;
}
