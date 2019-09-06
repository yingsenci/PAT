#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
	vector<string> ansid,anspw;
	int n,n1,cnt=0;
	string id,pw;
	cin>>n;
	n1=n;
	while(n1--){
		cin>>id>>pw;
		int i=0,flag=0;
		while(i<pw.length()){
			if(pw[i]=='1') pw[i]='@',flag=1;
			if(pw[i]=='0') pw[i]='%',flag=1;
			if(pw[i]=='l') pw[i]='L',flag=1;
			if(pw[i]=='O') pw[i]='o',flag=1;
			i++;
		}
		if(flag){
			cnt++;
			ansid.push_back(id);
			anspw.push_back(pw);
		}
	}
	if(cnt==0){
		if(n==1) printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified",n);
	}else{
		printf("%d\n",cnt);
		for(int i=0;i<ansid.size();i++)
		    cout<<ansid[i]<<" "<<anspw[i]<<endl;
	}
    return 0;
}
