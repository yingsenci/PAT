#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> a,b;
bool cmp(long long x,long long y) {
	return x<y;
}
int main(){
	int nc,np,i,j;
	scanf("%d",&nc);
	a.resize(nc);
	for(i=0;i<nc;i++) scanf("%lld",&a[i]);
	scanf("%d",&np);
	b.resize(np);
	for(i=0;i<np;i++) scanf("%lld",&b[i]);
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	long long sum=0;
	i=0,j=0;
    while(i<nc&&j<np&&a[i]<=0&&b[j]<=0){
    	if(a[i]==0)	{
    		i++;
			continue;
		}
    	if(b[j]==0) {
    		j++;
			continue;
		}
    	sum+=a[i]*b[j];
	    i++,j++;
	}
	i=nc-1,j=np-1;
	while(i>=0&&j>=0&&a[i]>=0&&b[j]>=0){
		if(a[i]==0)	{
    		i--;
			continue;
		}
    	if(b[j]==0) {
    		j--;
			continue;
		}
    	sum+=a[i]*b[j];
	    i--,j--;
	}
    printf("%lld",sum);
	return 0;
}

