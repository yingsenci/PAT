#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<limits.h>
using namespace std;
int v[1500][1500];
int d[1500];

int main(){
	int n,ns,m,limit;
	
	fill(v[0],v[0]+1500*1500,999999);
	string s1,s2;
	scanf("%d %d %d %d",&n,&ns,&m,&limit);
	while(m--){
		int t,t1,t2;
		cin>>s1>>s2;
		scanf("%d",&t);
		if(s1[0]=='G'){
			s1=s1.substr(1);
			t1=stoi(s1)+n;
	    }
	    else t1=stoi(s1);
	    if(s2[0]=='G'){
			s2=s2.substr(1);
			t2=stoi(s2)+n;
	    }
	    else t2=stoi(s2);
	    v[t1][t2]=t;
	    v[t2][t1]=t;
	}
	m=ns;
	int index,i,j;
	int visit[1500];
	int ansid;
	int ansd=-1;
	double ansave=999999;
	for(index=n+1;index<=n+m;index++){
		
		fill(d,d+1500,999999);
		fill(visit,visit+1500,0);
		d[index]=0;
		for(i=1;i<=n+m;i++){
			int min=999999;
			int u=-1;
			for(j=1;j<=n+m;j++)
			   if(visit[j]==0&&d[j]<min){
			   	u=j;
			   	min=d[j];
			   }
			if(u==-1) break;
			visit[u]=1;
			for(j=1;j<=n+m;j++)
			  {
			  	if(visit[j]==0&&d[j]>d[u]+v[u][j]&&v[u][j]!=999999)
			    d[j]=d[u]+v[u][j];
			  }
			  
		}
		int mind=999999;
		double avr=0;
		for(i=1;i<=n;i++){
			if(d[i]>limit) {
				mind=-1;
				break;
			}
			if(d[i]<mind) mind=d[i];
			avr+=1.0*d[i];
		}
		if(mind==-1) continue;
		avr/=n;
		if(mind>ansd){
			ansd=mind;
			ansave=avr;
			ansid=index;
		}
		else if(mind==ansd&&ansave>avr){
			ansave=avr;
			ansid=index;
		}
	}
	if(ansd==-1)
	   printf("No Solution");
	else{
		printf("G%d\n",ansid-n);
		printf("%.1f %.1f",(double)ansd,ansave);
	}
	return 0;
}
