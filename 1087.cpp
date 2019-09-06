#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<string ,int> nu;
map<int ,string> na;
vector<int>  path,tempath;
int cost[201][201];
int ha[201]; 
int visit[201]={0};
int fin,fin_cost=0,fin_ha=0;
double ave_ha=0;
int n,nump=0,numroad=1;
void dfs(int index,int temc,double temp,int step){
	if(index==fin&&temc>fin_cost){
	     numroad=1;
	     fin_cost=temc;
	     fin_ha=temp;
	     nump=step;
	     ave_ha=temp/step;
	     path=tempath;
	     return ;
	}
	else if(index==fin&&temc==fin_cost){
		   numroad++;
		   if(temp>fin_ha||(temp==fin_ha&& ave_ha < temp/step)){
			 fin_ha=temp;
	         nump=step;
	         ave_ha=temp/step;
	         path=tempath;
		 }
		  return ;
		}
	for(int i=1;i<n;i++)
	   if(visit[i]!=1&&cost[index][i]>0){
	   	visit[i]=1;
	   	tempath.push_back(i);
	   	dfs(i,temc+cost[index][i],temp+ha[i],step+1);
	   	visit[i]=0;
	   	tempath.pop_back();
	   }	 
}
int main(){
	int m;
	string root;
	scanf("%d %d",&n,&m);
	cin>>root;
	nu[root]=0;
	for(int i=1;i<n;i++){
		string tm;
		int ta; 
		cin>>tm>>ta;
		nu[tm]=i;
		na[i]=tm;
		ha[i]=ta;
		if(tm=="ROM") fin=i;
	}
    for(int i=0;i<m;i++){
    	string t1,t2;
    	int tcost;
    	cin>>t1>>t2>>tcost;
    	cost[nu[t1]][nu[t2]]=tcost;
    	cost[nu[t2]][nu[t1]]=tcost;
	}	
	visit[0]=1;
	dfs(0,0,0,0);
	printf("%d %d %d %d\n",numroad,fin_cost,fin_ha,int(ave_ha));
	cout<<root;
	for(int i=0;i<path.size();i++)
	cout<<"->"<<na[path[i]];
	return 0;
}
