#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
string reverse(string str){
	int i;
	string str2;
	for(i=str.length()-1;i>=0;i--)  //  pay attention to the sign "--" while using downto 
	str2+=str[i];
	return str2;
}
int main(){
	int n,i,min=9999;
	string s[102];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		string temp;
		getline(cin,temp);
		s[i]=reverse(temp);
		if(i!=n-1) getchar();
		if (min>s[i].length()) min=s[i].length();
		
	}
	int flag=1;
	stack<char> ans;
	for(i=0;i<min;i++){
		char key=s[0][i];
		for(int j=1;j<n;j++)
		   if(key!=s[j][i]) {
		   	flag=0;
		   	break;
		   }
		if(flag) ans.push(key);
		else break;
	}
	if(ans.empty()) {
		printf("nai");
	}
	else{
		int fl=1;
		while(!ans.empty()){
			char x=ans.top();
			ans.pop();
			if(fl==1&&x==' ') continue;
			else {
				printf("%c",x);
				fl=0;
		    }
		}
	}
	return 0;
}
