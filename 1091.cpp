#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n,m,t,l,cnt=0;
int x[6]={1,0,0,-1,0,0};
int y[6]={0,1,0,0,-1,0};
int z[6]={0,0,1,0,0,-1};
int visit[1300][130][61];
int v[1300][130][61];
struct node{
	int nx;
	int ny;
	int nz;
};

int judge(node temp){
	if(temp.nx<1||temp.nx>m||temp.ny<1||temp.ny>n||temp.nz<1||temp.nz>l) return 0;
	if(v[temp.nx][temp.ny][temp.nz]==1&&visit[temp.nx][temp.ny][temp.nz]==0) return 1;
	else return 0;
}
void bfs(int xi,int yi,int zi){
	node t1;
	t1.nx=xi;
	t1.ny=yi;
	t1.nz=zi;
	queue<node> q;
	q.push(t1);
	visit[xi][yi][zi]=1;
	while(!q.empty()){
		node t2=q.front();
		node t3;
		q.pop();
		cnt++;
        for(int i=0;i<6;i++){
        	t3.nx=t2.nx+x[i];
        	t3.ny=t2.ny+y[i];
			t3.nz=t2.nz+z[i];
			if(judge(t3)){
				visit[t3.nx][t3.ny][t3.nz]=1;
				q.push(t3);
			}		
		}
	} 
	if(cnt<t) cnt=0;
}
int main(){
	int i,j,k;
	memset(v,0,sizeof(v));
	memset(visit,0,sizeof(visit));
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(k=1;k<=l;k++)
	   for(i=1;i<=m;i++)
	      for(j=1;j<=n;j++)
	        scanf("%d",&v[i][j][k]);
	int ans=0;
	for(k=1;k<=l;k++)
	   for(i=1;i<=m;i++)
	      for(j=1;j<=n;j++){
	      	cnt=0;
	      	if(visit[i][j][k]==0&&v[i][j][k]==1)bfs(i,j,k);
	      	ans+=cnt;
		  }	
	printf("%d",ans);
	return 0;
}
