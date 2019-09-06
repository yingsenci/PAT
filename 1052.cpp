#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100001
struct info{
	int id;
	int data;
	int next;
}a[N];

bool cmp(info x,info y){
	return x.data<y.data;
}
int main(){
	int i,n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	   scanf("%d %d %d",&a[i].id,&a[i].data,&a[i].next);
	sort(a,a+n,cmp);
	printf("%d %05d\n",n,a[0].id);
	if(n==1){
		printf("%05d %d -1",a[0].id,a[0].data);
		return 0;
	}
	printf("%05d %d %05d\n",a[0].id,a[0].data,a[1].id);
	for(i=1;i<n-1;i++)
	printf("%05d %d %05d\n",a[i].id,a[i].data,a[i+1].id);
	printf("%05d %d -1",a[n-1].id,a[n-1].data);
}
