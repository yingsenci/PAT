#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int flag=0;
int mid=0;
vector<int> s;
bool isempty(vector<int> &s1){
	if(s1.size()==0) return true;
	else return false;
}
int PeekMedian(vector<int> &s2){
	int len=s2.size();
	vector<int> s3=s2;
	if(flag==0){
	   sort(s3.begin(),s3.end());
	   if(len%2==0) mid=s3[len/2-1];
       else mid=s3[(len+1)/2-1];
	}   
	return mid;
}
int main(){
	int n,num;
	char order[12];
	scanf("%d",&n);
	while(n--){
		scanf("%s",order);
		if(strcmp(order,"Push")==0){
			scanf("%d",&num);
			s.push_back(num);
			flag=0;
		}
		else{
			if(isempty(s)) {
				printf("Invalid\n");
				continue;
			}
			if(strcmp(order,"Pop")==0){
				printf("%d\n",s.back());
				s.pop_back();
				flag=0;
			}
			else{
				printf("%d\n",PeekMedian(s));
				flag=1;
			}
		}
	}
}
