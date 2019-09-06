#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<vector>
#define N 10001
using namespace std;

int a[N][101];
int path[N][101];
int v[N];
bool cmp(int a,int b){
	return  a>b;
}
int main(){
    int n,i,m,j;
    vector<int> ans;
    memset(a,0,sizeof(a));
    memset(path,0,sizeof(path));
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
    	scanf("%d",&v[i]);
	}
	sort(v+1,v+n+1,cmp);
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++){
	   	if(j-v[i]>=0){
	   		if(a[i-1][j]>a[i-1][j-v[i]]+v[i])
	   		   a[i][j]=a[i-1][j];
	   		else{
	   			a[i][j]=a[i-1][j-v[i]]+v[i];
	   			path[i][j]=1;
	   			
			   }
		   }
	   }
	
	if(a[n][m]!=m) printf("No Solution");
	else{
		while(m>0){
			while(path[n][m]==0) n--;
			ans.push_back(v[n]);
			m-=v[n];
			n--;
		}
		printf("%d",ans[0]);
		for(i=1;i<ans.size();i++) printf(" %d",ans[i]);
	}
	return 0;
}
