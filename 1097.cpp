#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N 1000000
struct info{
	int ad;
	int data;
	int next;
}a[N];
vector<info> b;
vector<info> c;
int exist[N]={0};
int main(){
	int r,n;
	scanf("%d %d",&r,&n);
	int m=n;
	while(n--){
		int t;
		scanf("%d",&t);
		a[t].ad=t;
		scanf("%d %d",&a[t].data,&a[t].next);
		}
	int p=r;
	while(p!=-1){
		if(exist[abs(a[p].data)]==0){
			exist[abs(a[p].data)]=1;
			b.push_back(a[p]);
		}
		else{
			c.push_back(a[p]);
		}
		p=a[p].next;
	}
    for(int i=0;i<b.size()-1;i++){
        printf("%05d %d %05d\n",b[i].ad,b[i].data,b[i+1].ad);
	}
	printf("%05d %d -1\n",b[b.size()-1].ad,b[b.size()-1].data);
    if(m!=1){
    	for(int i=0;i<c.size()-1;i++){
        printf("%05d %d %05d\n",c[i].ad,c[i].data,c[i+1].ad);
	    }
	    printf("%05d %d -1\n",c[c.size()-1].ad,c[c.size()-1].data);
	}

	return 0;
}
