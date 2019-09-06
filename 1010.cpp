#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
long long pw(long long i,long long n){
	long long j,t=1;
	if(n==0) return 1;
	for(j=1;j<=n;j++)
	    t*=i;
	return t;
}
long long caculate(string s,long long r){
	long long i,j=0,sum=0;
	long long len=s.length();
	char str[2];
	for(i=len-1;i>=0;i--){
		if (s[i]>='a')
		  sum+=pw(r,j)*(s[i]-'a'+10);
		else
		sum+=pw(r,j)*(s[i]-'0');
		j++;
	}
	return sum;
}
long long main(){
	long long tag,radix;
	long long t1,i;
	string s1,s2,temp;
	cin>>s1>>s2;
	scanf("%lld %lld",&tag,&radix);
	if(tag==2){
       temp=s1;
       s1=s2;
       s2=s1;
	}
	t1=caculate(s1,radix);
	//prlong longf("%lld",t1);
	char max = s2[0];
	for(i=1;i<s2.length();i++)
	    if (max<s2[i]) max=s2[i];
	//prlong longf(" %c",max);
	i=2;
	while(i<=36){
		long long t2=caculate(s2,i);
		if (t1==t2){
			prlong longf("%lld",i);
			return 0;
		}
		i++;
	}
	prlong longf("Impossible");
	return 0;
}
