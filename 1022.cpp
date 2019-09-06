#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string , vector<int> > hash_tit;
map<string , vector<int> > hash_aut;
map<string , vector<int> > hash_key;
map<string , vector<int> > hash_pub;
map<string , vector<int> > hash_yea;
vector<int> ans;
void findtitle(string key){
	if(hash_tit[key].size()==0) return ;
	for(auto it:hash_tit[key])
	   ans.push_back(it);
}
void findauthor(string key){
	if(hash_aut[key].size()==0) return ;
	for(auto it:hash_aut[key])
	   ans.push_back(it);
}
void findkey(string key){
	if(hash_key[key].size()==0) return ;
	for(auto it:hash_key[key])
	   ans.push_back(it);
}
void findpublish(string key){
	if(hash_pub[key].size()==0) return ;
	for(auto it:hash_pub[key])
	   ans.push_back(it);
}
void findyear(string key){
	if(hash_yea[key].size()==0) return ;
	for(auto it:hash_yea[key])
	   ans.push_back(it);
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int id;
		string s1,s2,s3,s4,s5;
		cin>>id;
		getchar();
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
		getline(cin,s5);hash_yea[s5].push_back(id);
		
	}
	int m;
	cin>>m;getchar();
	while(m--){
		ans.clear();
		string key;
		getline(cin,key);
		cout<<key<<endl;
		char x=key[0];
		key=key.substr(3);
		switch (x){
			case '1':findtitle(key);break;
			case '2':findauthor(key);break;
			case '3':findkey(key);break;
			case '4':findpublish(key);break;
			case '5':findyear(key);break;
			default:break;
		}
		if(ans.size()==0) printf("Not Found\n");
		else {
			sort(ans.begin(),ans.end());
			for(auto it:ans) printf("%07d\n",it);
		}
	}
	return 0;
}
