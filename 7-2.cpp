#include<cstdio>
#include<string>
#include<unordered_map>
#include<cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
unordered_map <string ,int> hash2;
int main(){
	int cnt=0,maxn1=inf,maxn2=inf;
	int n ,m;
	string s,ans;
	char str[20];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		s=str;
		hash2[s]=1;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%s",str);
		s=str;
		if(hash2.count(s)){
			cnt++;
			string date=s.substr(6,8);
			int ndate = stoi(date);
			if(maxn1>ndate){
				maxn1=ndate;
				ans = s;
			}
		} 
		else if (maxn1==0){
			string date=s.substr(6,8);
			int ndate = stoi(date);
			if(maxn2>ndate){
				maxn2=ndate;
				ans = s;
			}
		}
	}
	printf("%d\n",cnt);
	printf("%s",ans.c_str());
	return 0;
} 
