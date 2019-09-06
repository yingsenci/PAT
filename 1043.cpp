#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
typedef struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
}BTNode,*BT;
int n;
vector<int> ans1,ans2;
vector<int> res;
BT bst(BT p,int k){
	if(p==NULL){
		p=(BT)malloc(sizeof(BTNode));
		p->data=k;
		p->lchild=p->rchild=NULL;
	}
	else{
		if(k<p->data) p->lchild=bst(p->lchild,k);
		else p->rchild=bst(p->rchild,k);
	}
	return p;
}
void pre(BT p){
	if(p!=NULL){
		ans1.push_back(p->data);
		pre(p->lchild);
		pre(p->rchild);
	}
}
void mirpre(BT p){
	if(p!=NULL){
		ans2.push_back(p->data);
		mirpre(p->rchild);
		mirpre(p->lchild);
	}
}
void post(BT p){
	if(p!=NULL){
		post(p->lchild);
		post(p->rchild);
		res.push_back(p->data);
	}
}
void mirpost(BT p){
	if(p!=NULL){
		mirpost(p->rchild);
		mirpost(p->lchild);
		res.push_back(p->data);
	}
}
int main(){
	scanf("%d",&n);
	BT root=NULL;
	vector<int> a;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		a.push_back(t);
		root=bst(root,t);
	}
	pre(root);
	mirpre(root);
	if(a==ans1){
		post(root);
		printf("YES\n");
		printf("%d",res[0]);
		for(int i=1;i<res.size();i++) printf(" %d",res[i]);
	}
	else if(a==ans2){
		mirpost(root);
		printf("YES\n");
		printf("%d",res[0]);
		for(int i=1;i<res.size();i++) printf(" %d",res[i]);
	}
	else printf("NO");
	return 0;
}
