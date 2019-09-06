#include<cstdio>
#include<algorithm>
using namespace std;
int func(long long a,long long b){
	return b==0 ? a:func(b,a%b);
}
int main(){
	int n,i;
	long long a[102];
	long long b[102];
	long long sum=1,sumn=0;
    long long m,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld/%lld",&a[i],&b[i]);
		long long val=func(a[i],b[i]); // prevent overflow
		a[i]/=val;b[i]/=val;
		sum*=b[i];
	}
	for(i=1;i<=n;i++){
		sumn+=sum/b[i] * a[i];
	}
	if(sumn==0) {
		printf("0");
		return 0;
	}
	m=sumn/sum;
	if(m!=0) printf("%lld",m);
	sumn=abs(sumn)-abs(m)*abs(sum);
	sum=abs(sum);
	if(m!=0&&sumn%sum!=0) printf(" ");
	long long t=func(sumn,sum);
	sumn/=t;
	sum/=t;
	if(sumn%sum!=0)
	printf("%lld/%lld",sumn,sum);
	return 0;
}
