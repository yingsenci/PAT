#include<cstdio>
#include<cstring>
#include<limits.h>
int main(){
	int n,m,v,i,j,c1,c2,c1_temp,c2_temp,temp;
	int num_p[501]={0};
	int cost[501][501];
	int fin[501];
	int flag[501];
	int num[501];
	int sum_p[501];
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(i=0;i<n;i++){
	    scanf("%d",&num_p[i]);
	    sum_p[i] = 0;
		flag[i]=1;
		num[i]=0;
		fin[i]=INT_MAX;
	}
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
          if(i==j)
             cost[i][j]=0;
          else
             cost[i][j]=INT_MAX;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&c1_temp,&c2_temp,&temp);
		cost[c1_temp][c2_temp]=temp;
		cost[c2_temp][c1_temp]=temp;
	}
	flag[c1]=0;
	fin[c1]=0;
	num[c1]=1;
	sum_p[c1]=num_p[c1];
	for(i=0;i<n;i++)
	    if(cost[c1][i]!=0){
	     fin[i]=cost[c1][i];
	     num[i]=1;		       
		}

	
	for(i=0;i<n;i++){
		v=-1;
		for(j=0;j<n;j++){
		 if(v==-1&&flag[j])v=j;
		 if(flag[j]&&(fin[j]<fin[v]))
		       v=j;
		 }
		flag[v]=0;
		for(j=0;j<n;j++){
			if (v==j)continue;
			if(fin[j]==fin[v]+cost[v][j]){
				num[j]+=num[v];
				if(sum_p[j]<sum_p[v]+num_p[j])
				   sum_p[j]=sum_p[v]+num_p[j];
			}
			if (fin[j]>fin[v]+cost[v][j]){
				fin[j] = fin[v]+cost[v][j];
				num[j]=num[v];	
			    sum_p[j]=sum_p[v]+num_p[j];
			}
		}
	}
	printf("%d %d",num[c2],sum_p[c2]);
	return 0;
}
