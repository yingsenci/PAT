#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
vector<int> path,d,vis,cost;
struct node{
	int des=inf;
	int cos=inf;
}e[502][502];
int main(){
	int n,m,s,dest;
	scanf("%d %d %d %d",&n,&m,&s,&dest);
	d.resize(n+1);
	cost.resize(n+1);
	path.resize(n+1);
	vis.resize(n+1);
	//fill(e[0],e[0]+502*502,inf);
	fill(vis.begin(),vis.end(),0);
	fill(d.begin(),d.end(),inf);
	fill(cost.begin(),cost.end(),inf);
	while(m--){
        int t1,t2,c,t;
		scanf("%d %d %d %d",&t1,&t2,&c,&t);
		e[t1][t2].des=c;
		e[t1][t2].cos=t;
		e[t2][t1].des=c;
		e[t2][t1].cos=t;
	}
	int i;
	for(i=0;i<n;i++){
		path[i]=i;
	}
	d[s]=0;
	cost[s]=0;
	for(i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==0&&d[j]<min){
				u=j;
			min=d[j];
			}
		}
		if(u==-1) 
			break;		
		vis[u]=1;
		for(int j=0;j<n;j++)
			if(vis[j]==0){
				if(d[j]>d[u]+e[u][j].des&&e[u][j].des!=inf){
					cost[j]=cost[u]+e[u][j].cos;
					d[j]=d[u]+e[u][j].des;
					path[j]=u;
				}
				else if(d[j]==d[u]+e[u][j].des&&cost[j]>cost[u]+e[u][j].cos&&e[u][j].cos!=inf){
					cost[j]=cost[u]+e[u][j].cos;
					path[j]=u;
				}
			}		
	}
	vector<int> ans;
	int de=dest;
	while(path[dest]!=dest){
		ans.push_back(dest);
		dest=path[dest];
	}
	printf("%d",s);
	for(i=ans.size()-1;i>=0;i--) printf(" %d",ans[i]);
	printf(" %d %d",d[de],cost[de]);
	return 0;
}
