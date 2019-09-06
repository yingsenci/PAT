#include<map>
#include<iostream>
using namespace std;
int main(){
	map<int ,char> Hash;
	for(int i=0;i<=9;i++) Hash[i]='0'+i;
	Hash[10]='A';Hash[11]='B';Hash[12]='C';
	int a1,b1,c1;
	cin>>a1>>b1>>c1;
	cout<<"#";
	int a[2],b[2],c[2];
	a[1]=a1%13;a1/=13;a[0]=a1%13;
	b[1]=b1%13;b1/=13;b[0]=b1%13;
	c[1]=c1%13;c1/=13;c[0]=c1%13;
	cout<<Hash[a[0]]<<Hash[a[1]]<<Hash[b[0]]<<Hash[b[1]]<<Hash[c[0]]<<Hash[c[1]];
	return 0;
}	
