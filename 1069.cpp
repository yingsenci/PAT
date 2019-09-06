#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(vector<int> d){
	for(int i=0;i<4;i++)
	printf("%d",d[i]);
}
int main(){
	vector<int> a(4,0);
	vector<int> b(4,0);
	vector<int> c(4,0);
	int n,i=0;
	scanf("%d",&n);
	while(n>0){
		a[i++]=n%10;
		n/=10;
	}
	b=a;
	int flag=0;
	for(i=1;i<4;i++)
	  if(a[i]!=a[i-1]) flag=1;
	if(flag==0) {
		print(a);
		printf(" - ");
		print(a);
		printf(" = 0000");
		return 0;
	}
	while(c[0]!=6||a[1]!=1||a[2]!=7||a[3]!=4){
		sort(a.begin(),a.end(),greater<int>());
		sort(b.begin(),b.end());
		print(a);printf(" - ");print(b);printf(" = ");
		for(i=3;i>=0;i--){
			if(a[i]>=b[i]) c[i]=a[i]-b[i];
			else{
				c[i]=a[i]+10-b[i];
				a[i-1]--;
			}
		}
		print(c);
		printf("\n");
		a=c;b=c;
	}
	return 0;
}
