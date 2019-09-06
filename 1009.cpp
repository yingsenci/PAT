#include<cstdio>
#include<map>
using namespace std;
int main(){
	int k1,k2;
	int t1,i=0,count=0;
	double t2;
	double list[2001]={0};
	int flag[2001]={0};
	map<int ,double> a;
	map<int ,double> b;
	scanf("%d",&k1);
	while(k1--){
		scanf("%d %lf",&t1,&t2);
		a[t1]=t2;
	}
	scanf("%d",&k2);
	while(k2--){
		scanf("%d %lf",&t1,&t2);
		b[t1]=t2;
	}
	
	for(map<int,double>::iterator it1=a.begin();it1!=a.end();it1++)
	    for(map<int,double>::iterator it2=b.begin();it2!=b.end();it2++){
	    	//printf("%d %d\n",it1->first,it2->first);
	    	list[it1->first+it2->first]+=it1->second*it2->second;
	    	flag[it1->first+it2->first]=1;
		}
	for(i=2000;i>=0;i--){
    	if(flag[i]) count++;
	}
	printf("%d",count);
    for(i=2000;i>=0;i--){
    	if(flag[i]) printf(" %d %.1f",i,list[i]);
	}
	return 0;
}
