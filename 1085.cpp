#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[100001];
int judge(int max,int min,int c){
	int m,r;
	m=max/c;
	r=max%c;
	if(m>min||(m==min&&r>0)) return 1;
	else return 0;
}
int main(){
	long long n,p;
	int m1,m2,r1,r2;
	memset(a,0,sizeof(a));
	scanf("%lld %lld",&n,&p);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
    int i=0,j=n-1;
    while(i<=j&&judge(a[j],a[i],p)){
    	m1=p/a[i];
    	r1=p%a[i];
    	m2=a[j]/p;
    	r2=a[j]%p;
    	if(m1>m2) i++;
    	else{
    		if(m1==m2){
    			if(r1>r2) i++;
    			else j--;
			}else
			 j--;
		}
	}
	if(i>j) printf("0");
	else printf("%d",j-i+1);
	return 0;
}
