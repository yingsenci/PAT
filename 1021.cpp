#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 10002; 
struct node{
	vector<int> child;
}a[N];
int vis[N];
int n,cnt=0,Max=0;
vector<int> ans;

void dfs(int u){
	vis[u]=1;
	for(auto i :a[u].child){
		if(vis[i]==0)
		dfs(i);
	}
}

void getheight(int head,int u,int h){
	if(Max<h){
		Max=h;
		ans.clear();
		ans.push_back(head);
	}
	else if (Max==h&&head!=ans.back()) ans.push_back(head);
	vis[u]=1;
	for(auto i :a[u].child){
		if(vis[i]==0)
		getheight(head,i,h+1);
	}
	
}
int main(){
	scanf("%d",&n);
	fill(vis,vis+N,0);
	for(int i=1;i<n;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		 a[t1].child.push_back(t2);
	     a[t2].child.push_back(t1);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			cnt++;
		}
	}
	if(cnt>1){
		printf("Error: %d components",cnt);
		return 0;
	}
	for(int i=1;i<=n;i++){
		fill(vis,vis+N,0);
		getheight(i,i,1);
	}
	for(auto res:ans) printf("%d\n",res);
	return 0;
}
