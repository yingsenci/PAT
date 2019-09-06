#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int max,n,m;
			queue<int> q1,q2;
		stack<int> s;
	scanf("%d %d %d",&max,&n,&m);
	while(m--){
		vector<int> vis(n+1,0);

		int x,i,t,flag=1;
		for(i=1;i<=n;i++){
			scanf("%d",&t);
			q1.push(i);
			q2.push(t);
		}
	    s.push(1);
	    vis[1]=1;
	    q1.pop();
	    while(!q2.empty()&&flag){
	    	x=q2.front();q2.pop();
	    	if(!s.empty())
			  if(x==s.top()){
	    		s.pop();
	    		continue;
			  }
			if(vis[x]==1){
				flag=0;
				break;
			}
			while(!q1.empty()&&(s.empty()||s.top()!=x)){
				int n1;
				n1=q1.front();
				q1.pop();
				s.push(n1);				
                vis[n1]=1;			
			}
		    if(s.size()>max) flag=0;
		    else {
		    	s.pop();
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
		while(!s.empty()) s.pop();
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
	}
	return 0;
}
