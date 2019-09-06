#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
bool isprime(int m){
	int i;
	if(m==1||m==0) return false;
	if(m==2)  return true;
	for(i=2;i<=int(sqrt(m));i++)
		if(m%i==0) return false;
	return true;
}
int main(){
	vector<int> ans;
	int m,n;
	int a[10002]={0};
	scanf("%d %d",&m,&n);
	while(!isprime(m)) m++;
	while(n--){
		int t,key,cnt=1;
		scanf("%d",&t);
		key=t%m;
		while(a[key]!=0&&cnt<m){
			key=(t%m+cnt*cnt)%m;
		    cnt++;
		}
		if(cnt==m) ans.push_back(-1);
		else {
			a[key]=t;
			ans.push_back(key);
		}
	}
	if(ans[0]!=-1) printf("%d",ans[0]);
	else printf("-");
	for(int i=1;i<ans.size();i++){
		if(ans[i]!=-1)	printf(" %d",ans[i]);
		else printf(" -");
	}

	return 0;
} 
