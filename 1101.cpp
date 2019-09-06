#include<cstdio>
#include<limits.h>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001];
int b[100001];
int n;
int left=INT_MIN;
int right;
int fmax(int i,int j){
	int max=INT_MIN;
	int t,k;
	for(k=i;k<=j;k++)
	   if(a[k]>max) {
	   	t=k;
	   	max=a[k];
	   }
	return t;
}
int fmin(int i,int j){
	int min=INT_MAX;
	int t,k;
	for(k=i;k<=j;k++)
	    if(a[k]<min){
	    	t=k;
			min=a[k];
		}
	return t;
}
int main(){
	int i,j,cnt=0,ma,mi;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=0;
    j=n-1;
    while(i<=j){
    	ma=fmax(i,j);
    	mi=fmin(i,j);
    	if(mi<ma){
    		b[cnt++]=a[mi];
    		b[cnt++]=a[ma];
		}
		else if(mi==ma) b[cnt++]=a[ma];
		i=mi+1;
		j=ma-1;
	}
	sort(b,b+cnt);
	printf("%d\n",cnt);
	if(cnt!=0){
		printf("%d",b[0]);
		for(i=1;i<cnt;i++)
		  printf(" %d",b[i]);
	}
	else{
		printf("\n");
	}
	return 0;
}
