#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N =1002;
int e[N][N];
int vis[N];
int n;

void dfs(int u){
	vis[u]=1;
	for(int i=1;i<=n;i++)
	   if(vis[i]==0&&e[u][i]>0)
	     dfs(i);
}
int main(){
	int i,cnt=0;
	int m,k;
	fill(e[0],e[0]+N*N,0);
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		e[t1][t2]=1;
		e[t2][t1]=1;
	}
	while(k--){
		int t;
		fill(vis,vis+N,0);
		cnt=0;
		scanf("%d",&t);
		vis[t]=1;
		for(i=1;i<=n;i++)
		  if(vis[i]==0){
		  	dfs(i);
		  	cnt++;
		  }
		printf("%d\n",cnt-1);
	}
	
}
