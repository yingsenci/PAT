#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	string str,str_num,str_exp;
	
	int flag,i,k;
	cin>>str;
	if(str[0]=='-') printf("-"); 
	str.erase(0,1);
	str.erase(1,1);
	for(i=0;i<str.length();i++)
	if(str[i]=='E') {
		k=i;
		break;
	}
	str_num=str.substr(0,k);
	k++;
	if(str[k]=='+') flag=1;
	else flag=-1;
	str_exp=str.substr(k+1);
	int exp;
	char sexp[6];
	strcpy(sexp,str_exp.c_str());
	sscanf(sexp,"%d",&exp);
	if(exp==0){
		cout<<str_num[0]<<".";
		for(i=1;i<str_num.length();i++) cout<<str_num[i];
		return 0;
	}
	if(flag==1){
		if(str_num.length()-1<exp){
			cout<<str_num;
			for(i=str_num.length()-1;i<exp;i++)
			cout<<"0";
		}
		else{
			for(i=0;i<str_num.length();i++){
				if(i==exp+1) cout<<".";
				cout<<str_num[i];
			}
		}
	}
	else{
	     	cout<<"0.";
	     	for(i=1;i<=exp-1;i++) cout<<"0";
	     	cout<<str_num;
	}
	return 0;
}
