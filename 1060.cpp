#include<iostream>
#include<string>
using namespace std;

string change(string s,int n){
	int dot=-1;
	for(int i=0;i<s.size();i++)
	   if(s[i]=='.'){
	   	dot=i;
	   	break;
	   }
	if(dot==-1) {
		dot=s.size();
		s+='.';
	}
	s.erase(dot,1);
	int j=0;
	while(j<dot&&s[j]=='0') j++;
	s.erase(0,j);
	if(s[0]=='0'){
		dot=0;
		j=0;
		while(j<s.size()&&s[j]=='0') dot--,j++;
		s.erase(0,j);
	}
	int flag=1;
	for(j=0;j<s.size();j++)
	   if(s[j]!=0) flag=0;
	if(flag==1) dot=0;
	if(n<s.size()){
		s.erase(n);
		return "0."+s+"*10^"+to_string(dot);
	}
	else{
		for(int i=1;i<=s.size()-n;i++)
		    s+="0";
		return "0."+s+"*10^"+to_string(dot);
	}
}
int main(){
	int n;
	string s1,s2;
	cin>>n;
	cin>>s1>>s2;
	s1=change(s1,n);
	s2=change(s2,n);
	if(s1==s2) cout<<"YES "<<s1;
	else cout<<"NO "<<s1<<" "<<s2;
	return 0;
} 
