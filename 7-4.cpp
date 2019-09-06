#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct 	node{
	int data;
	struct node* lchild;
	struct node* rchild;
}btnode,*bt;
int n;
vector<int> a,b;

bt build(bt p,vector<int> a,vector<int> b){
	if(a.size()==0) return NULL;
	p=(bt)malloc(sizeof(btnode));
	p->lchild=p->rchild=NULL;
	p->data=a.back();
	int key=a.back();
	int k=0;
	vector<int> a1,a2,b1,b2;
	while(b[k]!=key) k++;
	for(int i=0;i<k;i++){
		a1.push_back(a[i]);
		b1.push_back(b[i]);
	}
	for(int i=k;i<a.size()-1;i++){
		a2.push_back(a[i]);
		b2.push_back(b[i+1]); 
	}
	p->lchild=build(p->lchild,a1,b1);
	p->rchild=build(p->rchild,a2,b2);
	return p;
}
void travel(bt p){
	if(p!=NULL){
		travel(p->lchild);
		printf("%d ",p->data);
		travel(p->rchild);
	}
}
bool isfull(bt p){
	if(p->lchild==NULL&&p->rchild==NULL) return true;
	else if(p->lchild==NULL||p->rchild==NULL) return false;
	bool x1=isfull(p->lchild);
	bool x2=isfull(p->rchild);
	if(x1&&x2) return true;
	else return false;
}
void findr(bt r,bt &p,int k){
	if(r!=NULL){
		if (r->data==k) {
			p=r;
			return ;
		}
		findr(r->lchild,p,k);
		findr(r->rchild,p,k);
	} 
}
void sibling(bt p,bool &k,int t1,int t2){
	if(p->lchild!=NULL&&p->rchild){
		if((p->lchild->data==t1&&p->rchild->data==t2)||(p->lchild->data==t2&&p->rchild->data==t1)){
			k=true;
			return ;
		}
	    sibling(p->lchild,k,t1,t2);
		sibling(p->rchild,k,t1,t2); 
	}
}
int getl(bt p){
	if(p==NULL) return 0;
	int h1=getl(p->lchild);
	int h2=getl(p->rchild);
	return h1>h2 ? h1+1:h2+1;
}
int main(){
	int n,m;
	bt root=NULL;
	scanf("%d",&n);
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	  scanf("%d",&b[i]);
	 root=build(root,a,b); 
	 scanf("%d",&m);
	 getchar();
	bool full=isfull(root);
	 while(m--){
	 	string order;
	 	getline(cin,order);
	 	if(order=="It is a full tree"){
	 		if(full) printf("Yes\n");
	 		else printf("No\n");
	 		continue;
		 }
		string str;
		int k=0;
		while(k<order.size()&&order[k]!=' ') k++;
		k++;
		if(order[k]=='i'){
			str=order.substr(k,9);
			if(str=="is the ro"){
				string s=order.substr(0,k-1);
				int num = stoi(s);
				if(root->data==num) printf("Yes\n");
				else printf("No\n");
				continue;
			}
			if(str=="is the pa"){
				string s=order.substr(0,k-1);
				int n1 = stoi(s);
				int t=k;
				while(t<order.size()&&!isdigit(order[t])) t++;
				s=order.substr(t);
				int n2 = stoi(s);
				bt p1;
				findr(root,p1,n1);
				if(p1->lchild->data==n2||p1->rchild->data==n2) printf("Yes\n");
				else printf("No\n");
				continue;
			}
			if(str=="is the le"){
				string s=order.substr(0,k-1);
				int n1 = stoi(s);
				int t=k;
				while(t<order.size()&&!isdigit(order[t])) t++;
				s=order.substr(t);
				int n2 = stoi(s);
				bt p1;
				findr(root,p1,n2);
				if(p1->lchild==NULL){
					printf("No\n");
					continue;
				}
				if(p1->lchild->data==n1) printf("Yes\n");
				else printf("No\n");
				continue;
			}
			if(str=="is the ri"){
				string s=order.substr(0,k-1);
				int n1 = stoi(s);
				int t=k;
				while(t<order.size()&&!isdigit(order[t])) t++;
				s=order.substr(t);
				int n2 = stoi(s);
				bt p1;
				findr(root,p1,n2);
				if(p1->rchild==NULL){
					printf("No\n");
					continue;
				}
				if(p1->rchild->data==n1) printf("Yes\n");
				else printf("No\n");
				continue;
			}
		}
		else{
			string s=order.substr(0,k-1);
			int n1 = stoi(s);
			int t=k;
			while(t<order.size()&&!isdigit(order[t])) t++;
			int n2;
			if(isdigit(order[t+1])){
				s=order.substr(t,2);
			}
			else s=order.substr(t,1);
			n2 = stoi(s);
			if(order[order.size()-1]=='s'){
				bool x=false;
				sibling(root,x,n1,n2);
				if(x) printf("Yes\n");
				else printf("No\n");
				continue;
			}
			else{
				bt p1,p2;
				findr(root,p1,n1);
				findr(root,p2,n2);
				int l1=getl(p1);
				int l2=getl(p2);
				printf("h:%d %d\n",l1,l2);
				if(l1==l2) printf("Yes\n");
				else printf("No\n");
				continue;
			}
		}
	 	
	 }
	 
	 
	 return 0;
} 
