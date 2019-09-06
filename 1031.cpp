#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	string str;
	int n1,n2,n3;
	cin>>str;
	int k=1;
	while(3*k-2<=str.length()) k++;
	k--;
	n1=n2=k;n3=str.length()-n1-n2+2;
	for(int i=0;i<n1-1;i++){
		printf("%c",str[i]);
		for(int j=1;j<=n3-2;j++)
		  printf(" ");
		printf("%c\n",str[str.length()-1-i]);
	}
	for(int i=n1-1;i<n1+n3-1;i++) printf("%c",str[i]);
	return 0; 
}
