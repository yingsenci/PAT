#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int visit[1002]={0};
int n,level;
int tot=0;
vector<vector<int> > v;
struct node{
	int data;
	int le;
};

void bfs(int index){
	queue<node> q;
	node x;
	x.data=index;
	x.le=0;
	q.push(x);
	while(!q.empty()){
		node t=q.front();
		q.pop();
		for(int i=0;i<v[t.data].size();i++){
			if(visit[v[t.data][i]]!=1&&t.le<level){
				node temp;
				temp.data=v[t.data][i];
				temp.le=t.le+1;
				q.push(temp);
				visit[v[t.data][i]]=1;
				tot++;
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&level);
	int i;
	v.resize(n+1);
	for(i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		while(num--){
			int t;
			scanf("%d",&t);
			v[t].push_back(i);
		}
	}
	int k;
	scanf("%d",&k);
	while(k--){
		memset(visit,0,sizeof(visit));
		int key;
		tot=0;
		scanf("%d",&key);
		visit[key]=1;
		bfs(key);
		printf("%d\n",tot);
	}
	return 0;
}
