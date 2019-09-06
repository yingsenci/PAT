#include<cstdio>
int main(){
	int n,t2,t1=0,cnt=0;
	scanf("%d",&n);
	cnt=n*5;
	while(n--){
		scanf("%d",&t2);
		if ((t2-t1)>0) {
		cnt+=(t2-t1)*6;
		}
	    else {
	    	cnt+=(t1-t2)*4;		
		}
	    t1=t2;
	}
	printf("%d",cnt);
	return 0;
}
