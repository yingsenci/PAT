#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
	unordered_map<char,int> hash;
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(auto i : s2)
	    hash[i]=1;
	for(auto i:s1)
	   if(hash[i]!=1) cout<<i;
	return 0;
}
