#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long lnog

long long  gcd(long long m,long long r){
	return r==0 ? m:gcd(r,m%r);
}
void func(long long a,long long b){
	int flag;
	if(a*b==0){
		printf("%s",b==0 ? "Inf":"0");
		return ;
	}
	if ((a<0&&b>0) ||(a>0&&b<0)) flag=1;
	else flag=0;
	a=abs(a);
	b=abs(b);
	if (flag==1) printf("(-");
	long long f=a/b;
	if(f!=0) printf("%lld",f);
	a=a-f*b;
	if(a%b==0){
		printf("%s",flag ? ")":"" );
		return ;
	} else if(f!=0)printf(" ");
	long long t=gcd(a,b);
	a/=t;
	b/=t;
	printf("%lld/%lld%s",a,b,flag ? ")":"");
	return ;
}
int main(){
	long long a1,b1,a2,b2;
	long long k1,k2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    func(a1,b1);printf(" + ");func(a2,b2);printf(" = ");func(a1*b2+a2*b1,b1*b2);printf("\n");
    func(a1,b1);printf(" - ");func(a2,b2);printf(" = ");func(a1*b2-a2*b1,b1*b2);printf("\n");
    func(a1,b1);printf(" * ");func(a2,b2);printf(" = ");func(a1*a2,b1*b2);printf("\n");
    func(a1,b1);printf(" / ");func(a2,b2);printf(" = ");func(a1*b2,b1*a2);printf("\n");    
}
