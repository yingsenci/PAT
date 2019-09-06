#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;
int n;
int judge(){
	int i;
	for(i=1;i<n;i++)
	if(a[i]!=i) return i;
	return -1;
}
int main(){

	int t,i,p,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a.push_back(t);
		if(t==0) p=i;
	}

    while(true){
    	int temp;
    	if(a[0]==0){
    		int k=judge();
    		if(k==-1) break;
    		else {
    			temp=a[0];
    			a[0]=a[k];
    			a[k]=temp;
    			p=k;
    			cnt++;
			}
		}
		else{
		for(int j=0;j<n;j++)
          if(a[j]==p){
          	a[p]=a[j];
          	a[j]=0;
          	p=j;
          	cnt++;
          	break;
		  }			
		}

	}
	printf("%d",cnt);
	return 0;
}
