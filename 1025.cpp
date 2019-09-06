#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct info{
	char id[15];
	int score;
	int local_rank;
	int fin_rank;
	int num;
}temp;
vector<info>  stu,ans;

bool cmp(info x,info y){
	if(x.score!=y.score) return x.score>y.score;
	else return strcmp(x.id,y.id)<0;
}
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int m,temscore;
		char temid[15];
		stu.clear();
		scanf("%d",&m);
		while(m--){
			scanf("%s %d",temp.id,&temp.score);
			temp.num=i;
			stu.push_back(temp);
		}
		sort(stu.begin(),stu.end(),cmp);
		stu[0].local_rank=1;
		ans.push_back(stu[0]);
		for(int j=1;j<stu.size();j++){
			stu[j].local_rank= stu[j].score==stu[j-1].score ? stu[j-1].local_rank:j+1;
			ans.push_back(stu[j]);
		}   
	}
	sort(ans.begin(),ans.end(),cmp);
	ans[0].fin_rank=1;
	printf("%d\n",ans.size());
	printf("%s %d %d %d\n",ans[0].id,ans[0].fin_rank,ans[0].num,ans[0].local_rank);
	for(i=1;i<ans.size();i++){
		ans[i].fin_rank= ans[i].score==ans[i-1].score ? ans[i-1].fin_rank : i+1;
		printf("%s %d %d %d\n",ans[i].id,ans[i].fin_rank,ans[i].num,ans[i].local_rank);
	}
	return 0;
}
