#include<cstdio>
#include<vector>
using namespace std;

struct info{
	int key;
	vector<int> sub;
}a[100001];
int num[100001];
int n;
double p,r,sum=0.0;

void dfs(int index,double temprice){
	if(a[index].key==0){
		sum+=temprice*num[index];
		return ;
	}
	for(int i=0;i<a[index].sub.size();i++)
	    dfs(a[index].sub[i],temprice*(1+r/100));
}
int main(){
	int i,temp,t;
	scanf("%d %lf %lf",&n,&p,&r);
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		a[i].key=temp;
		if(temp==0){
			scanf("%d",&num[i]);
			continue;
		}
		while(temp--){
			scanf("%d",&t);
			a[i].sub.push_back(t);
		}
	}
	dfs(0,p);
	printf("%.1f",sum);
	return 0;
}
