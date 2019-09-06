#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10002
int hash1[N]={0};
int a[N]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		hash1[a[i]]++;
	}
	for(int i=0;i<n;i++)
	  if(hash1[a[i]]==1){
	  	printf("%d",a[i]);
	  	return 0;
	  }
	printf("None");
	return 0;
}
