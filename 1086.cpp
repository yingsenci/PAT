#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
int a[10000]={0};
int n,cnt=0;
int b[10000]={0};
void postorder(int k){
	if(a[k]!=0){
		postorder(k*2);
		postorder(k*2+1);
		b[cnt++]=a[k];
	}
}
void create(){
	int i,k=1;
	int flag=0;
	stack<int> s;
	for(i=1;i<=2*n;i++){
		string str;
		int temp;
		cin>>str;
		if(str=="Push"){
			cin>>temp;
			if(flag==0){
				s.push(k);
				a[k]=temp;
				k*=2;
			}
			else{
				flag=0;
				int ki=2*k+1;
				a[2*k+1]=temp;
				s.push(ki);
				k=ki*2;
			}
		}
		else{
			k=s.top();
			s.pop();
			flag=1;
		}
	}
}
int main(){
	cin>>n;
	create();
	postorder(1);
	printf("%d",b[0]);
	for(int i=1;i<cnt;i++)
	  printf(" %d",b[i]);
	return 0;
}
