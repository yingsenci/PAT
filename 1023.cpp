#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s1,s2,s3="";
	cin>>s1;
	reverse(s1.begin(),s1.end());
	s2=s1;
	int c=0;
	for(int i=0;i<s1.size();i++){
		int t=(atoi(s1[i])+s2[i]-'0'+c)%10;
		c=((s1[i]-'0')+s2[i]-'0'+c)/10;
		s3+=to_string(t);
	}
	if(c==1) s3+="1";
	reverse(s3.begin(),s3.end());
	if(c==1){
		cout<<"No"<<endl<<s3;
		return 0;
	}
	s2=s3;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	for(int i=0;i<s1.size();i++)
	  if(s1[i]!=s2[i]){
	  	cout<<"No"<<endl<<s3;
		return 0;
	  }
	cout<<"Yes"<<endl<<s3;
		return 0;
}
