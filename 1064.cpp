#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct node{
     int data;
	 struct node* lchild;
	 struct node* rchild;	
}BTNode,*BT;

int n;
int a[1002];

BT build(BT p,int k){
	if(k<=n&&p==NULL){
		p=(BT)malloc(sizeof(BTNode));
		p->data=k;
		p->lchild=p->rchild=NULL;
		p->lchild=build(p->lchild,k*2);
		p->rchild=build(p->rchild,k*2+1);
	    return p;
	}
	else return NULL;
}
int cnt=0;
void inorder(BT p){
	if(p!=NULL){
		inorder(p->lchild);
		p->data=a[cnt++];
		inorder(p->rchild);
	}
}
int b[1002];
void levelorder(BT root){
	BT p;
	queue<BT> q;
	q.push(root);
	int ccnt=0;
	while(!q.empty()){
		p=q.front();
		q.pop();
		b[ccnt++]=p->data;
		if(p->lchild!=NULL) q.push(p->lchild);
		if(p->rchild!=NULL) q.push(p->rchild);
	}
	printf("%d",b[0]);
	for(int i=1;i<ccnt;i++) printf(" %d",b[i]);
}
int main(){
	int i;
	BT root=NULL;
	scanf("%d",&n);
	root = build(root,1);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	sort(a,a+n);
	inorder(root);
//	printf("%d",cnt);
	levelorder(root);
}
