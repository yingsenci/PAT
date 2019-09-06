#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int n,b;
	vector<int> ans;
	scanf("%d %d",&n,&b);
	if(n==0){
		printf("Yes\n0");
		return 0;
	}
	while(n>0){
		ans.push_back(n%b);
		n/=b;
	}
	int i=0,j=ans.size()-1;
	while(i<j&&ans[i]==ans[j]) i++,j--;
	if(i<j)
		printf("No\n");
	else printf("Yes\n");
	printf("%d",ans[ans.size()-1]);
	for(i=ans.size()-2;i>=0;i--) printf(" %d",ans[i]);
	return 0;
}
