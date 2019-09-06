#include<cstdio>
#define ll long long
int main(){
	ll n,i,t;
	ll len,max=0;
	scanf("%lld",&n);
	i=2;
	while(i<=n){
		ll k=i;
		len=0;
		while (n%k==0){
		    len++;
		   	 k=k*(i+len);
		}
		if(len>max){
			max=len;
			t=i;
		}
		i++;
	}
	printf("%d\n",max);
	printf("%lld",t);
	for(i=1;i<max;i++)
	    printf("*%lld",++t);
	return 0;
}
