#include<cstdio>
int a[101];
int b[101];
int n;
void print(int fin[]){
	int i;
	printf("%d",fin[1]);
	for(i=2;i<=n;i++)
	  printf(" %d",fin[i]);
}

void insertsort(int k){
	int i;
	b[0]=b[k];
	for(i=k-1;b[i]>b[0];i--)
	     b[i+1]=b[i];
	b[i+1]=b[0];
	print(b);
}

int judge(){
	int i;
	for(i=1;i<=n;i++)
	   if(a[i]!=b[i]) return 0;
	return 1;
}
void merge(int a[],int begin,int mid,int end){
	int c[101]={0};
	int k=0,i=begin;
    //	int mid=(begin+end)/2;
	int j=mid+1;
	while(i<=mid&&j<=end){
		if(a[i]<a[j]) c[k++]=a[i++];
		else   c[k++]=a[j++];
	}
	while(i<=mid) c[k++]=a[i++];
	while(j<=end) c[k++]=a[j++];
	k=0;
	for(i=begin;i<=end;i++)
	    a[i]=c[k++];
}
void Mergesort(){
	int k=1;
	int i;
	int flag=0;
	while(k<=n){
		i=1;
		while(i<=n-2*k+1){
		    merge(a,i,i+k-1,i+2*k-1);
		    i+=2*k;
	    }
	    if(i<=n-k+1){
	    	merge(a,i,i+k-1,n);
		}
		if(flag==1){
			print(a);
			break;
		}
		if(judge()==1) flag=1;
	    k*=2;
	}

	
}
int main(){
	int i,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for(i=2;i<=n;i++)
	   if(b[i]<b[i-1]){
	   	k=i;
	   	break;
	   }
	int flag=0;
	for(i=k;i<=n;i++)
	   if(a[i]!=b[i]){
	   	flag=1;
	   	break;
	   }
	if(flag==0){
		printf("Insertion Sort\n");
		insertsort(k);
	}
	else{
		printf("Merge Sort\n");
		Mergesort();
	}
	return 0;
}
