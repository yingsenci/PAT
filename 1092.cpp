#include<cstdio>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(){
	string s1,s2;
	int flag[1001];
	int visit[1001];
	int cnt=0;
	fill(flag,flag+1001,0);
	fill(visit,visit+1001,1);
	cin>>s1>>s2;
	for(int i=0;i<s2.length();i++)
	   for(int j=0;j<s1.length();j++)
	      if(visit[j]==1&&s2[i]==s1[j]){
	      	visit[j]=0;
	      	flag[i]=1;
	      	cnt++;
	      	break;
		  }
	int less=0;
	for(int i=0;i<s2.length();i++) if(flag[i]) less++; 
	if(cnt==s2.length()) printf("Yes %d",s1.length()-cnt);
	else  printf("No %d",s2.length()-less);
	return 0;
}
