#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define N 100002
struct info{
	char id[9];
	int v;
	int t;
	int tot;
	int level;
}a[N];

bool cmp(info x,info y){
	if(x.level!=y.level) return x.level<y.level;
	else if(x.tot!=y.tot) return x.tot>y.tot;
	     else if(x.v!=y.v) return x.v>y.v;
	          else return strcmp(x.id,y.id)<0;
}
int main(){
	int n,l,h,i,cnt=0;
	char temid[9];
	int temv,temt;
	scanf("%d %d %d",&n,&l,&h);
	for(i=0;i<n;i++){
		scanf("%s %d %d",temid,&temv,&temt);
		if(temv<l||temt<l) continue;
		strcpy(a[cnt].id,temid);
		a[cnt].t=temt;
		a[cnt].v=temv;
		a[cnt].tot=temt+temv;
		if(temt>=h&&temv>=h) a[cnt].level=1;
		else if(temt<h&&temv>=h)  a[cnt].level=2;
		     else if(temt<h&&temv<h&&temv>=temt)  a[cnt].level=3;
		          else a[cnt].level=4;
	    cnt++;
	}
	sort(a,a+cnt,cmp);
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++)
	    printf("%s %d %d\n",a[i].id,a[i].v,a[i].t);
    return 0;
}
