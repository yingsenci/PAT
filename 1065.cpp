#include<cstdio>
int main(){
	int n;
	long long a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		if((a>=0&&b<=0)||(a<=0&&b>=0))
	        printf("Case #%d: %s\n",i,a+b>c ? "true":"false");
	    else{
	    	if(a>0&&c<=0) {
	    		printf("Case #%d: true\n",i);
	    		continue;
			}
			if(a<0&&c>=0){
				printf("Case #%d: false\n",i);
	    		continue;
			}
			printf("Case #%d: %s\n",i,a>c-b ? "true":"false");
		}
	}
return 0;
}
