#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a,b;
vector<int> ans;
int main(){
	int n,m;
	scanf("%d",&n);
	int mid=n;
	int t;
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a.push_back(t);
	}
	scanf("%d",&m);
	mid=(mid+m)/2;
    for(i=0;i<m;i++){
		scanf("%d",&t);
		b.push_back(t);
	} 
	i=j=0;
    while(i<a.size()&&j<b.size()){
    	if(a[i]<b[j]) ans.push_back(a[i]),i++;
    	else ans.push_back(b[j]) ,j++;
	}
	while(i<a.size()) ans.push_back(a[i]),i++;
	while(j<b.size()) ans.push_back(b[j]),j++;	
	printf("%d",ans[mid]);
	return 0;
}
