#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct student{
	string name;
	string signin;
	string signout;
}stu[10000],t;

bool cmpin(student a,student b){
	return a.signin<b.signin;
}
bool cmpout(student a,student b){
	return a.signout>b.signout;
}
int main(){
	int i,j,m;
	cin>>m;
	for (i=0;i<m;i++)
	    cin>>stu[i].name>>stu[i].signin>>stu[i].signout;

	sort(stu,stu+m,cmpin);
	cout<<stu[0].name<<" ";
	sort(stu,stu+m,cmpout);
	cout<<stu[0].name;
		 
	return 0;	
}
