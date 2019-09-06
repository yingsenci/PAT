#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<cmath>
#include<set>
#define ll long long
using namespace std;
const int N=505,INF=0x3f3f3f3f;
int a[N],mape[N][N];
int num[N],d[N],vis[N],n,m,c1,c2,tot[N];
 
void init(){
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));
    memset(num,0,sizeof(num));
    memset(tot,0,sizeof(tot));
}
 
void dijk(){
    d[c1]=0;
    num[c1]=a[c1];
    tot[c1]=1;
    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&(v==-1||d[j]<d[v])){
               v=j;
            }
        }
        vis[v]=1;
        for(int j=0;j<n;j++){
            if(j==v)continue;
            if(d[j]==d[v]+mape[v][j]){
                tot[j]+=tot[v];
                num[j]=max(num[j],num[v]+a[j]);
            }
            if(d[j]>d[v]+mape[v][j]){
                d[j]=d[v]+mape[v][j];
                tot[j]=tot[v];
                num[j]=num[v]+a[j];
            }
        }
    }
}
 
int main(){
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    init();
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)mape[i][j]=0;
            else mape[i][j]=INF;
        }
    }
    int s,e,c;
    while(m--){
        scanf("%d%d%d",&s,&e,&c);
        mape[s][e]=c;
        mape[e][s]=c;
    }
    dijk();
    printf("%d %d\n",tot[c2],num[c2]);

}
