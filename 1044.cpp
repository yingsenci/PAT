#include<cstdio>
#include<vector>
using namespace std; 
#define inf 9999999;
struct node{
	int first;
	int second;
};

int main(){
	vector<node> ans;
	int n,m,max=inf;
	int i,j;
	scanf("%d %d",&n,&m);
	vector<int> a(n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	i=j=0;
	while(i<n&&j<n){
		int sum=a[i];
		while(i<n&&j<n&&sum<m) {
			j++;
			sum+=a[j];
		}
		if(sum<max&&sum>=m){
			ans.clear();
			node nod={i,j};
			ans.push_back(nod);
			max=sum;
		}
		else if(sum==max){
			node nod={i,j};
			ans.push_back(nod);
		}
		i++;
		j=i;
	}
	for(auto res:ans) printf("%d-%d\n",res.first+1,res.second+1);
	return 0;
}
