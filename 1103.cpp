#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n,k,p;
vector<int> v,temp,ans;
int fac=-1;

void init(){
	for(int i=0;i<=n;i++){
		if(int(pow(i,p))<=n)
		   v.push_back(pow(i,p));
		else break;
	}
}
void dfs(int index,int temsum,int step,int temfac){
	if (temsum==n&&step==k){
		if(fac<temfac){
			fac=temfac;
			ans=temp;
		}
		return ;
	}
	if(temsum>n||step>k) return ;
	if(index>=1){
		temp.push_back(index);
		dfs(index,temsum+v[index],step+1,temfac+index);
		temp.pop_back();
		dfs(index-1,temsum,step,temfac);
	}	
}
int main(){
     scanf("%d %d %d",&n,&k,&p);
     init();
     dfs(v.size()-1,0,0,0);
     if (fac==-1){
     	printf("Impossible");
     	return 0;
	 }
     printf("%d = %d^%d",n,ans[0],p);
     for(int i=1;i<ans.size();i++)
	 printf(" + %d^%d",ans[i],p);
	 return 0; 
}
