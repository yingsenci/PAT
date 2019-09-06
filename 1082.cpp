#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

struct info{
	string s;
	string c;
};
vector<info> v;
int main(){
	vector<string> read;
	map<char ,string>mp;
	map<int, string>mp2;
	mp['1']="yi";mp['2']="er";;mp['3']="san";mp['4']="si";
	mp['5']="wu";mp['6']="liu";mp['7']="qi";mp['8']="ba";mp['9']="jiu";mp['0']="ling";
	mp2[4]="Qian";mp2[3]="Bai";mp2[2]="Shi";mp2[1]="ge";
	string str,str1,str2;
	int len,flag=0;
	cin>>str;
	if(str[0]=='0'){
		printf("ling");
		return 0;
	}
	if(str[0]=='-'){
		read.push_back("Fu");
		str.erase(0,1);
	}
	if(str.length()==9){
		read.push_back(mp[str[0]]);
	    read.push_back("Yi");
	    str.erase(0,1);
	}
	if(str.length()>4){
		str1=str.substr(0,str.length()-4);
		str2=str.substr(str.length()-4);
		for(int i=0;i<str1.length();i++){
			info temp;
			temp.c=mp[str1[i]];
			temp.s=mp2[str1.length()-i];
		    v.push_back(temp);
		}
        if(v[v.size()-1].c=="ling") v.pop_back();
        if(v[v.size()-1].c=="ling") v.pop_back();
        if(v[v.size()-1].c=="ling") v.pop_back();
	    flag=0;
		for(int i=0;i<v.size();i++)
		if(v[i].c=="ling") {
			if(flag==1) continue;
			else{
				flag=1;
				read.push_back("ling");
			}
		}
		else{
			flag=0;
			read.push_back(v[i].c);
			read.push_back(v[i].s);
		}
		read.push_back("Wan");
	}
	else str2=str;
	
	v.clear();
	for(int i=0;i<str2.length();i++){
			info temp;
			temp.c=mp[str2[i]];
			temp.s=mp2[str2.length()-i];
		    v.push_back(temp);
		}
        if(v[v.size()-1].c=="ling") v.pop_back();
        if(v[v.size()-1].c=="ling") v.pop_back();
        if(v[v.size()-1].c=="ling") v.pop_back();
		 flag=0;
		for(int i=0;i<v.size();i++)
		if(v[i].c=="ling") {
			if(flag==1) continue;
			else{
				flag=1;
				read.push_back("ling");
			}
		}
		else{
			flag=0;
			read.push_back(v[i].c);
			read.push_back(v[i].s);
		}
	cout<<read[0];
	for(int i=1;i<read.size();i++)
		if(read[i]!="ge") cout<<' '<<read[i];
	

	return 0;
}
