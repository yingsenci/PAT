#include<cstdio>
#include<queue>

using namespace std;
struct Node{
	int data;
	int lchild;
	int rchild;
}a[12];
int b[12];
int cnt; 
void print(){
	int i;
	printf("%d",b[0]);
	for(i=1;i<cnt;i++)
	   printf(" %d",b[i]);
}
void level(int r){
	queue<Node> q;
	Node temp;
	q.push(a[r]);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		b[cnt++]=temp.data;
		if(temp.rchild != -1) q.push(a[temp.rchild]);
		if(temp.lchild != -1) q.push(a[temp.lchild]);
	}
	print();
}
void inorder(int r){
	if (r!=-1){
		inorder(a[r].rchild);
		b[cnt++]=r;
		inorder(a[r].lchild);
	}
}
int main(){
	int n,root,i;
	char c1,c2;
	scanf("%d",&n);
	getchar();
	root=0;
	for(i=0;i<n;i++){
		scanf("%c %c",&c1,&c2);
		getchar();
		a[i].data=i;
		if(c1!='-') {
		   a[i].lchild=int (c1-'0');	
		   root+=a[i].lchild;
		}
		else a[i].lchild=-1;
		if(c2!='-') {
			a[i].rchild=int(c2-'0');
			root+=a[i].rchild;
		}
		else a[i].rchild=-1;
	}
	root=n*(n-1)/2-root;
	printf("root:%d\n",root);
	level(root);
	cnt=0;
	inorder(root);
	printf("\n");
	print();
	return 0;
}
