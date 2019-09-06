#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	int i,sum=0,n=0;
	int a[10000]={0};
	string str;
	cin>>str;
	for (i=0;i<str.length();i++)
	     sum+=int(str[i])-'0';
	while(sum>0){
	  a[n]=sum%10;
	  sum/=10;
	  n++;	
	}
	n--;
	switch (a[n]){
		case 1:printf("one");break;
		case 2:printf("two");break;
		case 3:printf("three");break;
		case 4:printf("four");break;
		case 5:printf("five");break;
		case 6:printf("six");break;
		case 7:printf("seven");break;
		case 8:printf("eight");break;
		case 9:printf("nine");break;
		case 0:printf("zero");break;
		default:break;
	}
	for(i=n-1;i>=0;i--)
	   	switch (a[i]){
		case 1:printf(" one");break;
		case 2:printf(" two");break;
		case 3:printf(" three");break;
		case 4:printf(" four");break;
		case 5:printf(" five");break;
		case 6:printf(" six");break;
		case 7:printf(" seven");break;
		case 8:printf(" eight");break;
		case 9:printf(" nine");break;
		case 0:printf(" zero");break;
		default:break;
	}
	return 0;
}
