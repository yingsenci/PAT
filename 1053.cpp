#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int w;
	vector<int> child;
};
int weight;
vector<node> v;
vector<vector<int> > ans;
vector<int> temans;
void dfs(int k,int temsum){
	if(temsum==weight&&v[k].child.size()==0){
		ans.push_back(temans);
	    return ;
	}
	for(int i=0;i<v[k].child.size();i++){
		if(temsum+v[v[k].child[i]].w<=weight){
			temans.push_back(v[v[k].child[i]].w);
			dfs(v[k].child[i],temsum+v[v[k].child[i]].w);
			temans.pop_back();
		}
	}
}
bool cmp(vector<int> a,vector<int> b){
	int size= a.size()>b.size() ? b.size():a.size();
	for(int i=0;i<size;i++){
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return a.size()>b.size();
}
int main(){
	int n,m;
	scanf("%d %d %d",&n,&m,&weight);
	v.resize(n);
	for(int i=0;i<n;i++)
	  scanf("%d",&v[i].w);
	while(m--){
		int nod,k;
		scanf("%d %d",&nod,&k);
		while(k--){
			int temp;
			scanf("%d",&temp);
			v[nod].child.push_back(temp);
		}
	}
	//temans.push_back(v[0].w);
	dfs(0,v[0].w);
	sort(ans.begin(),ans.end(),cmp);
	for(auto i:ans){
		printf("%d",v[0].w);
		for(auto j:i) printf(" %d",j);
		printf("\n");
	}
	return 0;
}
