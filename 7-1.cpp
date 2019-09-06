#include<cstdio>
#include<cmath>

bool isprime(int n){
	int i;
	if (n<2) return false;
	if (n==2) return true;
	for(i=2;i<=int(sqrt(n));i++)
	   if(n%i==0) return false;
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	if(isprime(n)) {
		if(isprime(n-6)) {
			printf("Yes\n%d",n-6);
			return 0;
		}
		if(isprime(n+6)) {
			printf("Yes\n%d",n+6);
			return 0;
		}
	}
	do{
		n++;
	}while(!isprime(n)||!isprime(n+6));
	printf("No\n%d",n);
	return 0;
}
