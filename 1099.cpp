#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct BTNode{
	int data;
	int lchild;
	int rchild;
}a[101];
int b[101]={0};
int c[101]={0};
int cnt=0;
void preorder(int p){
	if(p!=-1){
		preorder(a[p].lchild);
		a[p].data=b[cnt++];
		preorder(a[p].rchild);
	}
}
void levelorder(int r){
	int p,tot=0;
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		p=q.front();
		c[tot++]=a[p].data;
		q.pop();
		if(a[p].lchild!=-1) q.push(a[p].lchild);
		if(a[p].rchild!=-1) q.push(a[p].rchild);
	}
	printf("%d",c[0]);
	for(int i=1;i<tot;i++)
	 printf(" %d",c[i]);
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		a[i].lchild=t1;
		a[i].rchild=t2;
	}
	for(i=0;i<n;i++)
	    scanf("%d",&b[i]);
	sort(b,b+n);
	preorder(0);
	levelorder(0);
}
