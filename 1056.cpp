#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct node{
	int id;
	int nrank;
	int fin;
};
bool cmp(node a,node b){
	return a.nrank>b.nrank;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	int i,n,m;
	vector<int> w,t;
	vector<int> seq;
	vector<node> ans;
	map<int ,int > hash;
	scanf("%d %d",&n,&m);
	w.resize(n+1);
	t.resize(n+1);
	seq.resize(n+1);
    ans.resize(n);
	for(i=0;i<n;i++) {
	scanf("%d",&t[i]);	
	hash[t[i]]=i;
	}
	for(i=0;i<n;i++) {
		scanf("%d",&seq[i]);
		w[i]=t[seq[i]];
	}
	if(n==1) {
		printf("1");
		return 0;
	}
	int count=0;
	vector<int> rank(n+1,0);
 	int ranknum=1;
	 while(count!=1){
	 	count=0;
	    int max;
	 	vector<int> temp;
		int i=0,j=0;
		while(j<w.size()){
			while(j<w.size()&&j-i!=m) j++;
			count++;
		    max=w[i];
			for(int k=i;k<j;k++) max= max<w[k] ? w[k]:max;
			temp.push_back(max);
			for(int k=i;k<j;k++)
			   if(w[k]!=max) rank[hash[w[k]]]=ranknum;
			i=j;
			}
		ranknum++;
		if(count==1) {
			rank[hash[max]]=ranknum;
		}
		w.clear();
		w=temp;
		}
	
	for(int i=0;i<n;i++){
		ans[i].id=i;
		ans[i].nrank=rank[i];
	}
	sort(ans.begin(),ans.end(),cmp);
	int tt=1;
	int dt=1;
	ans[0].fin=1;
	for(int i=1;i<n;i++)
	 if(ans[i].nrank==ans[i-1].nrank) {
	 	ans[i].fin=tt;
	 	dt++;
	 }
	 else{ 
	     tt+=dt;
	     dt=1;
	     ans[i].fin=tt;
	 }
	 sort(ans.begin(),ans.end(),cmp2);
	printf("%d",ans[0].fin);
	for(int i=1;i<n;i++) printf(" %d",ans[i].fin);
	return 0;
}
