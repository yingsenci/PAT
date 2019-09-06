#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m;	
    scanf("%d %d",&n,&m);
    vector<int> v(n);
    int i,j,flag=0;
    int t1,t2;
	for(i=0;i<n;i++) scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	for(i=0;i<n;i++){
		if(flag==1) break;
		for(j=i+1;j<n;j++)
		   if(v[i]+v[j]==m){
		   	flag=1;
		   	t1=v[i];t2=v[j];
		   	break;
		   }
	}
	if(flag)
	printf("%d %d",t1,t2);
	else
	printf("No Solution");
	return 0;
}
