#include<cstdio>
#include<unordered_map>
#include<cstring>
using namespace std;
int main(){
	int n,m;
	char t[1000];
	unordered_map < char*,int> hash;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	   for(int j=0;j<m;j++){
	   	scanf("%s",t);
	   	hash[t]++;
	   }
	   int max=0;
	   char ans[1000];
	for(auto i=hash.begin();i!=hash.end();i++)
	   if(i->second>max) {
	   	  max=i->second;
	   	  strcpy(ans,i->first);
	   }
	printf("%s",ans);
	return 0;
}
