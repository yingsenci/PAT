#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

bool T(char s){
	if((s>='0'&&s<='9')||(s>='A'&&s<='Z')||(s>='a'&&s<='z')) return true;
	else return false;
}

void transfer(string &s){
	char c;
	for(int i=0;i<s.length();i++)
	  if(s[i]>='A'&&s[i]<='Z')  s[i]+=32;

}
int main(){
	string str;
	
	string maxs;
	int max=0;
	map<string,int> cnt;
	getline(cin,str);
	transfer(str);
	int i=0,j=0;
	while(i<str.size()){
		string temstr;
		while(i<str.size()&& !T(str[i])) i++;
		j=i;
		while(j<str.size()&& T(str[j])) j++;
		//cout<<"ij"<<i<<","<<j<<endl;
		temstr=str.substr(i,j-i);
		//cout<<temstr<<endl;
		cnt[temstr]++;
		if(max<cnt[temstr]){
			max=cnt[temstr];
			maxs=temstr;
		}
		i=j;
	}
	cout<<maxs<<" "<<max;
    return 0;
}
