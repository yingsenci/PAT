#include<cstdio>
#include<algorithm>
using namespace std;

int a[101];
int b[101];
int c[101];
int n;
void print(int k){
	int i;
	if(k==1) printf("Insertion Sort\n");
	if(k==0)  printf("Heap Sort\n");
	printf("%d",b[0]);
	for(i=1;i<n;i++)
	 printf(" %d",b[i]);
}
void insertion(){
	int i,k;
	for(i=1;i<n;i++)
	   if (b[i-1]>b[i]) {
	   	k=i;
	   	break;
	   }
	int key=b[k];
	for(i=k-1;b[i]>key;i--)
	    b[i+1]=b[i];
	b[i+1]=key;
	print(1);
}
void heap(int x){
     int m=n-x;
	 int t,k;
	 t=b[0];
	 b[0]=b[m-1];
	 b[m-1]=t;
	 m--;
	 t=0;
	 int key=b[0];
	 while(t<m){
	 	if(2*t+2<m)
	      k= b[2*t+1] >b[2*t+2] ? 2*t+1 : 2*t+2;
	   	else if(2*t+1<m)
	   	        k=2*t+1;
	   	     else break;
	   	if(b[t]<b[k]){
	   		int temp=b[t];
	   		b[t]=b[k];
	   		b[k]=temp;
	   		t=k;
		   }
		else break;
	 }
	 print(0);	
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    c[i]=a[i];
	}
	for(i=0;i<n;i++)
	    scanf("%d",&b[i]);
	sort(c,c+n);
	int t1=0,t2=0;
	for(i=n-1;i>=0;i--){
		if(c[i]==a[i]) t1++;
		if(c[i]==b[i]) t2++;
		else break;
	}
    if (t2>0&&(t2!=t1)) heap(t2);
    else insertion();
    return 0;
}
