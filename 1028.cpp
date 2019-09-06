#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct info{
	int id;
	char name[10];
	int grade;
};
vector<info> a;
bool cmp1(info x,info y){
	return x.id<y.id;
}
bool cmp2(info x,info y){
	if(strcmp(x.name,y.name)!=0) return strcmp(x.name,y.name)<0;
	else return x.id<y.id;
}
bool cmp3 (info x,info y){
	if(x.grade!=y.grade) return x.grade<y.grade;
	else return x.id<y.id;
}
int main(){
	int n,order;
	scanf("%d %d",&n,&order);
	a.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&a[i].id,&a[i].name,&a[i].grade);
	}
	switch(order){
		case 1:sort(a.begin(),a.end(),cmp1);break;
		case 2:sort(a.begin(),a.end(),cmp2);break;
		case 3:sort(a.begin(),a.end(),cmp3);break;
	}
	for(auto ans:a)printf("%06d %s %d\n",ans.id,ans.name,ans.grade);
	return 0;
}
