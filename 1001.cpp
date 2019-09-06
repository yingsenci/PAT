#include<cstdio>
#include<cstring>
int main(){
	int exp[1001];
	float coef[1001];
	int k1,k2,i,temp_exp,count=0;
	float temp_coef;
	memset(exp,0,sizeof(exp));
	memset(coef,0,sizeof(coef));
	scanf("%d",&k1);
	for(i=0;i<k1;i++){
		scanf("%d %f",&temp_exp,&temp_coef);
		coef[temp_exp]+=temp_coef;
	}
	scanf("%d",&k2);
	for(i=0;i<k2;i++){
		scanf("%d %f",&temp_exp,&temp_coef);
		coef[temp_exp]+=temp_coef;
	}
	for(i=1001;i>=0;i--)
	    if(int(coef[i])!=0)
	       count++;
	printf("%d",count);
	for(i=1001;i>=0;i--)
	    if(int(coef[i])!=0){
	    	printf(" %d %.1f",i,coef[i]);
		}
	return 0;
}
