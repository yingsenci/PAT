#include<cstdio>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* lchild;
	struct Node* rchild;
}BTNode,*BT;

int H(BT p){
	if(p==NULL) return 0;
	else{
		int h1=H(p->lchild);
		int h2=H(p->rchild);
		return h1>h2 ? h1+1 : h2+1;
	}
}

BT LL(BT p){
	BT t=p->lchild;
	p->lchild=t->rchild;
	t->rchild=p;
	return t;
}
BT RR(BT p){
	BT t=p->rchild;
	p->rchild=t->lchild;
	t->lchild=p;
	return t;
}
BT LR(BT p){
	p->lchild=RR(p->lchild);
	return LL(p);
}
BT RL(BT p){
	p->rchild=LL(p->rchild);
	return RR(p);
}
BT insertAVL(BT root,int k){
	if(root==NULL){
		root=(BT)malloc(sizeof(BTNode));
		root->data=k;
		root->lchild=root->rchild=NULL;
	}else{
		if(k<root->data){
			root->lchild=insertAVL(root->lchild,k);
			if(H(root->lchild)-H(root->rchild)==2) 
			root= k < root->lchild->data ? LL(root):LR(root);
		}
		else{
			root->rchild=insertAVL(root->rchild,k);
			if(H(root->lchild)-H(root->rchild)==-2) 
			root= k > root->rchild->data ? RR(root):RL(root);
		}
	}
	return root;
}
int main(){
	int n,i,k;
	BT root=NULL;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		root=insertAVL(root,k);
	}
	printf("%d",root->data);
	return 0;
}
