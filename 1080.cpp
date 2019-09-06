#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct  school{
	vector<int> nu;
	int nsize;
}sch[101];
struct info{
	int id;
	int fing;
	int ge;
	int gi;
	vector<int> apply;
};
vector<info> stu(40001),cpystu(40001);
bool cmp(info a,info b){
	if (a.fing!=b.fing) return a.fing>b.fing;
	else if (a.ge!=b.ge) return a.ge>b.ge; //pay attenrion to another else
}
int judge(int a,int b){
	if(cpystu[a].fing==cpystu[b].fing&&cpystu[a].ge==cpystu[b].ge){
		  return 1;
	}
	 
	else return 0;
	
}
int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++)
	    scanf("%d",&sch[i].nsize);
	for(i=0;i<n;i++){
		stu[i].id=i;
		scanf("%d %d",&stu[i].ge,&stu[i].gi);
		stu[i].fing=(stu[i].ge+stu[i].gi)/2;
		for(j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			stu[i].apply.push_back(t);
		}
	}
	cpystu=stu;
	sort(stu.begin(),stu.end(),cmp);
	for(i=0;i<n;i++){
		int index=0;
		while(index<stu[i].apply.size()){
			if(sch[stu[i].apply[index]].nsize>0){
				sch[stu[i].apply[index]].nsize--;
				sch[stu[i].apply[index]].nu.push_back(stu[i].id);
				break;
			}
			else{
				 if(judge(stu[i].id,sch[stu[i].apply[index]].nu[sch[stu[i].apply[index]].nu.size()-1])){
				 	sch[stu[i].apply[index]].nu.push_back(stu[i].id);
				 	break;
				 }
				 else index++;
			}
		}
	}
	for(i=0;i<m;i++){
		if(sch[i].nu.size()!=0){
			sort(sch[i].nu.begin(),sch[i].nu.end());
			printf("%d",sch[i].nu[0]);
			for(j=1;j<sch[i].nu.size();j++)
			   printf(" %d",sch[i].nu[j]);
		}
		printf("\n");
	}
	return 0;
} 
