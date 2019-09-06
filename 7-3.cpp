#include<cstdio>
#include<vector>
using namespace std;
const int N =1001;
struct node{
	int id;
	int call[N]={0};
	bool callback[N]={false};
}a[N];
vector<node> gang;
vector<int>  ans[N];

int father[N];
void init(int n){
	for(int i=1;i<=n;i++)
	  father[i]=i;
}

int findfa(int k){
	while(k!=father[k]){
		k=father[k];
	}
	return k;
}
void Union(int x,int y){
	int fx = findfa(x);
	int fy = findfa(y);
	if(fx<fy) father[fy]=fx;
	else father[fx]=fy;
}

int main(){
	int i,k,n,m;
	scanf("%d %d %d",&k,&n,&m);
	for(i=0;i<m;i++){
		int t1,t2,len;
		scanf("%d %d %d",&t1,&t2,&len);
		a[t1].id=t1;
		a[t1].call[t2]+=len;
		a[t2].callback[t1]=true;
	}
	for(i=1;i<=n;i++){
		int j,cnt1=0,cnt2=0;
		for(j=1;j<=n;j++)
			if(a[i].call[j]<=5&&a[i].call[j]!=0){
				cnt1++;
				if(a[i].callback[j]) cnt2++;
			}
        if(cnt1>k&&(cnt2<=cnt1/5)) gang.push_back(a[i]); 
	}
	if(gang.size()==0){
		printf("None");
		return 0;
	}
	init(n);
	int j;
	for(i=0;i<gang.size();i++)
	   for(j=i+1;j<gang.size();j++){
	   	int t1=gang[i].id,t2=gang[j].id;
	   	if(a[t1].callback[t2]&&a[t2].callback[t1])
	   	    Union(t1,t2);
	   }			
	for(i=0;i<gang.size();i++)
	   ans[father[gang[i].id]].push_back(gang[i].id);	
	for(i=1;i<=n;i++)
		if(ans[i].size()!=0){
			for(auto x:ans[i]) printf("%d ",x);
			printf("\n");
		}
	     
    return 0;
}
