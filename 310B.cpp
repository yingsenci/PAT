#include<cstdio>
#include<vector>
using namespace std;
const int N = 100000;
struct node{
	int id;
	int data;
	int next;
}t,a[N];
vector<node> v,ans;
int main(){
	int i,n,head;
	scanf("%d %d",&n,&head);
	for(i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		a[temp].id=temp;
		scanf("%d %d",&a[temp].data,&a[temp].next);
	}
	i=head;
	if(head==-1) {
		printf("0 -1\n");
		return 0;
	}
	while(i!=-1){
        v.push_back(a[i]);
        i=a[i].next;
	}
	printf("%d %05d\n",v.size(),head);
	int j=v.size()-1;
	i=0;
	while(i<j){
		if(j-i==1) break;
		printf("%05d %d %05d\n",v[i].id,v[i].data,v[j].id);
		printf("%05d %d %05d\n",v[j].id,v[j].data,v[i+1].id);
		i++;
		j--;
	}
	if(j-i==1){
		printf("%05d %d %05d\n",v[i].id,v[i].data,v[j].id);
		printf("%05d %d -1",v[j].id,v[j].data);
	}
	else if(i==j){
		printf("%05d %d -1",v[j].id,v[j].data);
	}
	return 0;
	
}
