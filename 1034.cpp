#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

map<string ,int> strtoint;
map<int , string> intostr;
map<string , int> ans;
int vis[1001];
int w[1001];
int wp[1001][1001];
int e[1001][1001];
int n=1;
int trans(string s){
	if(strtoint[s]!=0) return strtoint[s];
	else{
		strtoint[s]=n;
		intostr[n]=s;
		n++;
		return n-1;
	}
}

void dfs(int u,int &head,int &num,int &tot){
	num++;
	vis[u]=1;
	if(w[u]>w[head]) head=u;
	for(int i=1;i<n;i++){
		if(wp[u][i]>0){
			tot+=wp[u][i];
			wp[u][i]=wp[i][u]=0;
		if(vis[i]==0)
	    	dfs(i,head,num,tot);	
		}
		
	}
}
int main(){
	int m,lim;
	cin>>m>>lim;
	memset(w,0,sizeof(w));
	memset(wp,0,sizeof(wp));
	memset(vis,0,sizeof(vis));
	while(m--){
		string t1,t2;
		int we;
		cin>>t1>>t2>>we;
		int x1=trans(t1);
		int x2=trans(t2);
		e[x1][x2] =1;
		w[x1]+=we;
		w[x2]+=we;
		wp[x1][x2]=we;
		wp[x2][x1]=we;
	}
	for(int i=1;i<n;i++){
		if(vis[i]==0){
			int head=i,num=0,tot=0;
			dfs(i,head,num,tot);
			if(num>2&&tot>lim)
			ans[intostr[head]]=num;
		}
	}
	printf("%d\n",ans.size());
	for(auto res:ans) cout<<res.first<<" "<<res.second<<endl;
    return 0;
} 
