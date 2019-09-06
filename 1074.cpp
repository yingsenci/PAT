#include<cstdio>
#include<cstring>
#define N 100000
struct list{
	int data;
	int next;
}a[N];

int main(){
	int i,r,n,k;
	scanf("%d %d %d",&r,&n,&k);
	for(i=0;i<n;i++){
		int tp;
		scanf("%d",&tp);
		scanf("%d %d",&a[tp].data,&a[tp].next);
	}
	int p1,p2;
	if(n==1){
	   printf("%05d %d %d",r,a[r].data,a[r].next);
	   return 0; 
    }
    int remain =n;
    p1=r;p2=a[r].next;
    a[p1].next=-1;
    int cnt=0;
    int root,flag=1;
    while(remain>=k){
		a[p2].next=p1;
		p1=p2;
		p2=a[p2].next;
    	remain--;
    	cnt++;
    	if((cnt+1)%k==0) {
    		cnt=0;
    		if(flag==1){
    			root=p1;
    			flag=0;
			}
			if(remain>0){
				a[r].next=p2;
				p1=p2;
				a[p1].next=-1;
				p2=a[p2].next;
				r=p1;
			}
		}
	}
	while(root!=-1){
		if(a[root].next!=-1)
		printf("%05d %d %05d\n",root,a[root].data,a[root].next);
		else{
			printf("???%d",a[root].next);
			printf("%05d %d %d\n",root,a[root].data,a[root].next);
		root=a[root].next;
		}

	}
	return 0;
}

