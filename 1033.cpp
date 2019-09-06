#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int dis;
	double pr;
};
bool cmp( node a,node b){
	return a.dis<b.dis;
}
int main(){
	vector<node> gas;
	int n,m,dest,per;
	scanf("%d %d %d %d",&n,&dest,&per,&m);
	int maxper=n*per;
	gas.resize(m);
	for(int i=0;i<m;i++)
	   scanf("%lf %d",&gas[i].pr,&gas[i].dis);
	sort(gas.begin(),gas.end(),cmp);
	node x;
	x.dis=dest;x.pr=0;
	gas.push_back(x);
	if(gas[0].dis!=0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	int i=0,temdis=0,temn=0;
	double temp=0;
	while(i!=m){
		int u=-1;
		if(gas[i].dis+maxper<gas[i+1].dis){
			temdis=gas[i].dis+maxper;
			printf("The maximum travel distance = %d.00",temdis);
			return 0;
		}
		for(int j=i+1;j<=m;j++){
			if(gas[i].dis+maxper>gas[j].dis&&gas[j].pr<gas[i].pr){
				u=j;
				break;
			}
		}
		if(u!=-1){
			temp=gas[i].pr*(gas[u].dis-gas[i].dis);
			i=u;
			break;
		}
		else{
			double min=99999;
			for(int j=i+1;j<=m;j++)
			  if(gas[i].dis+maxper>gas[j].dis&&gas[j].pr<min) {
			     min=gas[j].pr;
			     u=j;
			  }
			  
		}
	}
	
}
