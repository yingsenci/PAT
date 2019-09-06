#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define N 200000
vector<int> v;
void prime(){
	v.push_back(2);
	for(int i=3;i<=N;i++){
		int flag=1;
		for(int j=2;j<=(int)sqrt(i);j++)
		  if(i%j==0) {
		  	flag=0;
		  	break;
		  }
		if(flag) v.push_back(i);
	}
}
struct info{
	int prime;
	int ccnt=0;
}a[1000];
int main(){
	prime();
	long long n,m;
	scanf("%lld",&n);
	m=n;
	int cnt=0,k=0;
	int flag=0;
	while(n>1){
		while(n>0&&n%v[k]==0){
			flag=1;
			a[cnt].prime=v[k];
			a[cnt].ccnt++;
		    n/=v[k];
		}
		k++;
		if(flag==1){
			cnt++;
			flag=0;
		}
	}
	if(m==1) {
		printf("1=1");
		return 0;
	}
	if(a[0].ccnt!=1)
	 printf("%lld=%d^%d",m,a[0].prime,a[0].ccnt);
	else printf("%lld=%d",m,a[0].prime);
	for(int i=1;i<cnt;i++)
	if(a[i].ccnt!=1)
	  printf("*%d^%d",a[i].prime,a[i].ccnt);
	else printf("*%d",a[i].prime);
	return 0;
	
}
