#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	string s1,s2;
	string s3,s4;
	map<char , string> mp;
	mp['A']="MON";mp['B']="TUE";mp['C']="WED";mp['D']="THU";mp['E']="FRI";mp['F']="SAT";mp['G']="SUN";
	cin>>s1>>s2>>s3>>s4;
	int i=0;
	int len1 = s1.size()<s2.size() ? s1.size() : s2.size();
	int len2 = s3.size()<s4.size() ? s3.size() : s4.size();
	for(i=0;i<len1;i++)
	   if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G') {
	   	cout<<mp[s1[i]]<<" ";
	   	break;
	   }
	int k=i+1;
	for(i=k;i<len1;i++)
	if(s1[i]==s2[i]){
		if(s1[i]>='0'&&s1[i]<='9') {
			int temp=s1[i]-'0';
			printf("%02d",temp);
			break;
		}
		if(s1[i]>='A'&&s1[i]<='N'){
			int temp=s1[i]-'A'+	10;
			printf("%02d",temp);
			break;
		}
	}
	for(i=0;i<len2;i++)
	   if(s3[i]==s4[i]&&(islower(s3[i])||isupper(s3[i]))){
		   printf(":%02d",i);
		   break;
	   }
	return 0;
}
