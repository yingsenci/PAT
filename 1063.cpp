#include<cstdio>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<int> > v(51);
int main(){
	int n,i,m;
	unordered_set<int> s[51];
    unordered_set<int> s1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		int t;
		while(m--){
			scanf("%d",&t);
			v[i].push_back(t);
			s[i].insert(t);
		}
	}
	int k,t1,t2;
	double ans;
	scanf("%d",&k);
	while(k--){
		scanf("%d %d",&t1,&t2);
		s1.clear();
		t1--;
		t2--;
		for(i=0;i<v[t1].size();i++){
			s1.insert(v[t1][i]);
		}
		for(i=0;i<v[t2].size();i++){
			s1.insert(v[t2][i]);
		}
		ans=(double) (s[t1].size()+s[t2].size()-s1.size())/ s1.size();
		printf("%.1f%\n",ans*100);
	}
	return 0;
}
