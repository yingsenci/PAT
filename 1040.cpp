#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	string str;
	int k,i,j,min=1;
	getline(cin,str);
	k=0;
	while(k<str.length()){
		int temp;
		i=j=k;
		while(i>=0&&j<str.length()&&str[i]==str[j]){
			i--;j++; 
		}
		temp=j-i-1;
		if (temp>min) min=temp;
		i=k;j=k+1;
		while(i>=0&&j<str.length()&&str[i]==str[j]){
			i--;j++;
		}
		temp=j-i-1;
		if(temp>min) min=temp;
		k++;
	}
	cout<<min;
	return 0;
}
