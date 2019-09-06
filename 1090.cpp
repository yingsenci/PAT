#include<cstdio>
#include<vector>
using namespace std;
int n;
double p,r;
double sum=0.0;
int cnt=0;
struct node{
	vector<int> next;
}v[10001];

void dfs(int index,double temprice){
	if(v[index].next.size()==0){
		if(temprice>sum){
		  cnt=1;
		  sum=temprice;
	    }
	    else if(temprice==sum){
		      cnt++;
	          }
	    return ;
	}
	for(int i=0;i<v[index].next.size();i++){
		dfs(v[index].next[i],temprice*(1+r/100));
	}
	
}
int main(){
	int t,root;
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++){
	   scanf("%d",&t);
	   v[t].next.push_back(i);
	   if (t==-1) root=i;
	}
    dfs(root,p);
	printf("%.2f %d",sum,cnt);
	return 0;
}
