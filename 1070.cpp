#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct item{
	int num;
	double val;
	double per;
};

bool cmp(item a,item b){
	return a.per>b.per;
}
int main(){
	int i,n,m;
	vector<item> a(1002);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].num);
	}
	for(i=0;i<n;i++){
		scanf("%lf",&a[i].val);
		a[i].per=a[i].val/a[i].num;
	}
	sort(a.begin(),a.end(),cmp);
	double sum=0;
	i=0;
	while(a[i].num<=m){
		sum+=a[i].val;
		m-=a[i].num;
		i++;
	}
	if(m>0&&i<n) sum+=m*a[i].per;
	printf("%.2f",sum);
	return 0;
}
