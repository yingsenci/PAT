#include<cstdio>
int main(){
	long long n;
	long long cnt=0;
	scanf("%lld",&n);
	int i=1;
	if(n>212000000) {
		i=212000001;
		cnt=271200001;
	}
	for(;i<=n;i++){
		int t=i;
		while(t>0){
			if(t%10==1)cnt++;
			t/=10;
		}
	}
	printf("%lld",cnt);
}
