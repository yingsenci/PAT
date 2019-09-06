#include<cstdio>
#define N 100001
struct node{
	int next;
	int data=0;
}a[N];

int main(){
	int n,sum=0;
	scanf("%d",&n);
	a[1].data=0;
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i].data);
		sum+=a[i].data;
		a[i].data+=a[i-1].data;//
		a[i].next=i+1;
		
	}
	int t;
	scanf("%d",&t);sum+=t;
	printf("sum:%d\n",sum);
	a[n].next=1;
	int m,t1,t2;
	scanf("%d",&m);
	while(m--){
		int tsum=0;
		scanf("%d %d",&t1,&t2);
		//for(int i=t1;i!=t2;i=a[i].next)
		//   tsum+=a[i].data;
		tsum=t2>t1 ? a[t2].data-a[t1].data : a[t1].data-a[t2].data;
		printf("%d\n",tsum>(sum-tsum) ? sum-tsum : tsum);
	}
	return 0;
}
