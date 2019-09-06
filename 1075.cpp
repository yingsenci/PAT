#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10002
struct info{
	int name;
	int score[6];
	int flag;
	int tot;
	int perfect;
}a[N],b[N];
int n,k;
void init(){
	for(int i=1;i<=n;i++){
		a[i].name=i;
		a[i].flag=0;
		for(int j=1;j<=k;j++)
		    a[i].score[j]=-1;
		a[i].tot=0;
		a[i].perfect=0;
	}
}
bool cmp(info x,info y){
	if(x.tot!=y.tot) return x.tot>y.tot;
	else if(x.perfect!=y.perfect) return x.perfect>y.perfect;
	     else return x.name<y.name;
}
int main(){
	int i,m;
	int pscore[6];
	scanf("%d %d %d",&n,&k,&m);
	init();
    for(i=1;i<=k;i++) 
	   scanf("%d",&pscore[i]);
    while(m--){
    	int id,p,s;
    	scanf("%d %d %d",&id,&p,&s);
    	if(s!=-1){
    		a[id].flag=1;
    		a[id].score[p]= a[id].score[p]>s ? a[id].score[p] : s;
		}
		else a[id].score[p]=a[id].score[p]>s ? a[id].score[p] : 0;
	}
	int cnt=0;
	for(i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
		    if(a[i].score[j]!=-1){
		    	a[i].tot+=a[i].score[j];
		    	if (a[i].score[j]==pscore[j]) a[i].perfect++;
			}
		if(a[i].flag==1)
		   b[cnt++]=a[i];
	}
	sort(b,b+cnt,cmp);
	int rank=1,trank=1;
	printf("%d %05d %d",rank,b[0].name,b[0].tot);
	for(i=1;i<=k;i++)
	   if(b[0].score[i]==-1) printf(" -");
	   else printf(" %d",b[0].score[i]);
	
	for(i=1;i<cnt;i++){
		printf("\n");
		if(b[i].tot==b[i-1].tot) trank++;
		else {
			 rank+=trank;
			 trank=1;
		}
		printf("%d %05d %d",rank,b[i].name,b[i].tot);
	    for(int j=1;j<=k;j++)
	       if(b[i].score[j]==-1) printf(" -");
	       else printf(" %d",b[i].score[j]);
	}
	return 0;
}
