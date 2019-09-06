#include<cstdio>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
typedef struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
}btnode,*bt;
vector<int> a,b;
vector<int> ans;
int n;

bt build(bt p,vector<int> a,vector<int> b){
	if(a.size()==0) return NULL;
	p=(bt)malloc(sizeof(btnode));
	p->data=a.back();
	p->lchild=p->rchild=NULL;
	int k;
	int t;
	for(int i=0;i<b.size();i++)
       if(b[i]==a.back()) {
       	k=i;
       	break;
    }
    vector<int> a1,a2,b1,b2;
    for(int i=0;i<k;i++) {
    	a1.push_back(a[i]);
    	b1.push_back(b[i]);
	} 
	for(int i =k+1;i<a.size();i++){
		a2.push_back(a[i-1]);
    	b2.push_back(b[i]);
	}
	p->lchild=build(p->lchild,a1,b1);
	p->rchild=build(p->rchild,a2,b2);
	return p;
}

void level(bt r){
	queue<bt> q;
	bt p;
	q.push(r);
	while(!q.empty()){
		p=q.front();
		ans.push_back(p->data);
		q.pop();
		if(p->lchild!=NULL) q.push(p->lchild);
		if(p->rchild!=NULL) q.push(p->rchild);
	}
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++) printf(" %d",ans[i]);
}
int main(){
	scanf("%d",&n);
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	scanf("%d",&b[i]);
	bt root=NULL;
	root=build(root,a,b);
	level(root);
	return 0;
}
