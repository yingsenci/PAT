#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPN(string s){
	int i=0,j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j]) return false;
		i++;
		j--;
	}
	return true;
}
string func(string s1){
	string s2=s1;
	string s="";
	reverse(s2.begin(),s2.end());
	int c=0;
	for(int i=0;i<s1.size();i++){
		string tem=to_string(((s1[i]-'0')+(s2[i]-'0')+c)%10);
		s+=tem;
		c=((s1[i]-'0')+(s2[i]-'0')+c)/10;
	}
	if(c==1)
	s+="1";
	reverse(s.begin(),s.end());
	return s;

}
int main(){
	long long k,step=0;
	string x;
	cin>>x>>k;
	while(step<k){
		if(isPN(x)) break;
		step++;
		x=func(x);	
	}
    cout<<x<<endl<<step;
	return 0;     	
} 
