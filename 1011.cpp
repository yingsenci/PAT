#include<cstdio>
int main(){
	double a[4];
	double sum=1,max=0;
	char c[4];
	int i,k,t=3;
	while(t--){
	for (i=1;i<=3;i++){
	    scanf("%lf",&a[i]);	
		if (a[i]>max) {
			max=a[i];
			k=i;
		}
	}
	 switch (k){
	 	case 1:c[t]='W';break;
	 	case 2:c[t]='T';break;
	 	case 3:c[t]='L';break;
	 	default:break;
	 }		
	 sum*=a[k];
	}
    sum=(sum*0.65-1)*2;
	printf("%c %c %c %.2f",c[2],c[1],c[0],sum);
    return 0;
}
