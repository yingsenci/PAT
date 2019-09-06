#include<cstdio>
#include<map>
#include<vector>
#include<queue>
using namespace std;

map<int , vector<int> > nlnode;
vector<int> level(100,0);
int maxlay=0;
int dfs(int node,int lay){
	int i;
	if (nlnode[node].size()==0){
		level[lay]++;
		maxlay= maxlay<lay ? lay : maxlay;
		return 0;
	}
	else{
		for(i=0;i<nlnode[node].size();i++)
		   dfs(nlnode[node][i],lay+1);
	}
}
int main(){

	int n,m,k,i,j,tempf,tempc;
	int count,flag=1;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&tempf,&k);
		for(j=0;j<k;j++){
			scanf("%d",&tempc);
			nlnode[tempf].push_back(tempc);
		}
	}
	dfs(1,1);
	printf("%d",level[1]);
	for (i=2;i<=maxlay;i++)
	  printf(" %d",level[i]);
	  return 0;
}
