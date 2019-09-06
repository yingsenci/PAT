#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100000
struct node{
	char data;
	int next;
}a[N];

int main(){
	int h1,h2,n;
	scanf("%d %d %d",&h1,&h2,&n);
	for(int i=0;i<n;i++){
		int t1,t2;
		char c;
		scanf("%d %c %d",&t1,&c,&t2);
		a[t1].data=c;
		a[t1].next=t2;
	}
	int j,i=h1;
	int len1=0,len2=0;
	while(i!=-1){
		len1++;
		i=a[i].next;
	}
	i=h2;
	while(i!=-1){
		len2++;
		i=a[i].next;
	}
	int len = abs(len1-len2);
	if(len1>len2) 
	   for(i=0;i<len;i++) h1=a[h1].next;
	else
	   for(i=0;i<len;i++) h2=a[h2].next;
	int point=-1,flag=1;
	while(h1!=-1&&h2!=-1){
		if(a[h1].data==a[h2].data&&flag){
			flag=0;
			point =h1;
		}
		else if(a[h1].data!=a[h2].data){
			if(flag==0) flag=1;
			point=-1;
		}
		h1=a[h1].next;
		h2=a[h2].next;
	}
	if(point==-1) printf("-1");
	else
	printf("%05d",point);
	return 0;	
}
