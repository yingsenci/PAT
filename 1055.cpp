#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
	char id[10];
	int age;
	int val;
};

bool cmp1(const info &a,const info &b){
	if(a.age!=b.age) return a.age>b.age;
	else if(a.val!=b.val) return a.val>b.val;
	else return strcmp(a.id,b.id)<0;
}
bool cmp2(const info &a,const info &b){
	if(a.val!=b.val) return a.val>b.val;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	vector<info> v,w;
	int i,n,k;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		info x;
		scanf("%s %d %d",&x.id,&x.age,&x.val);
		v.push_back(x);
	}
	
	sort(v.begin(),v.end(),cmp1);
	w=v;
	for(int s=1;s<=k;s++){
		v.clear();
		v=w;
		int max,a1,a2;
		scanf("%d %d %d",&max,&a1,&a2);
		int i=0;
		while(i<n&&v[i].age>a2) i++;
		int j=i;
		while(j<n&&v[j].age>=a1) j++;
		printf("Case #%d:\n",s);
		if(i==j) {
			printf("None\n");
			continue;
		}
		sort(v.begin()+i,v.begin()+j,cmp2);
		for(int x=0;x< (j-i<max ? j-i:max);x++){
			printf("%s %d %d\n",v[x+i].id,v[x+i].age,v[x+i].val);
		}
	}
	return 0;
}
