#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>

map<string , vector<int> > hash_tit;
map<string , vector<int> > hash_aut;
map<string , vector<int> > hash_key;
map<string , vector<int> > hash_pub;
map<string , vector<int> > hash_yea;

int main(){
	int n;

	cin>>n;
	while(n--){
		int id;
		string s1,s2,s3,s4,s5;
		scanf("%d",&id);
		getline(cin,s1);hash_tit[s1].push_back(id);
		getline(cin,s2);hash_aut[s2].push_back(id);
		
		getline(cin,s3);
		int i=0,j=0;
		vector<string> temp;
		string str;
		while(i<s3.size()&&i<s3.size()){
			while(j<s3.size()&&s3[j]!=' ') j++;
			str=s3.substr(i,j-i);
			temp.push_back(str);
			j++;
			i=j;
		}
		for(auto stemp:temp) hash_key[stemp].push_back(id);
		
		getline(cin,s4);hash_pub[s4].push_back(id);
		getline(cin,s5);hash_tit[s5].push_back(id);
		
	}
	int m;
	cin>>m;
	while(m--){
		string key;
		getline(cin,key);
		char x=key[0];
		key=key.substr(3);
		
	}
}
