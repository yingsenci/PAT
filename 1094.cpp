#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct node{
	vector<int> kid;
}a[101];

void levelorder(int r){
    int k,p1,p2,floor=0,max=0;
    int maxf;
    queue<int> q;
    q.push(r);
	p1=1;
    p2=0;
    while(!q.empty()){
    	if(p1>max){
		    maxf=floor+1;
			max=p1;
		}
    	k=q.front();
    	q.pop();
    	p1--;
    	for(int i=0;i<a[k].kid.size();i++){
    		q.push(a[k].kid[i]);
    		p2++;
		}
        if(p1==0){
        	floor++;
        	p1=p2;
        	p2=0;
		}
     
	}
        printf("%d %d",max,maxf);   
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	while(m--){
		int id,k;
		scanf("%d %d",&id,&k);
        while(k--){
        	int t;
        	scanf("%d",&t);
        	a[id].kid.push_back(t);
		}
	}
	levelorder(1);
    return 0;
}
