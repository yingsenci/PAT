#include<cstdio>
#include<string>
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

int transfer1(string x){
	if(x=="tret") return 0;
	if(x=="jan") return 1;
	if(x=="feb") return 2;
	if(x=="mar") return 3;
	if(x=="apr") return 4;
	if(x=="may") return 5;
	if(x=="jun") return 6;
	if(x=="jly") return 7;
	if(x=="aug") return 8;
	if(x=="sep") return 9;
	if(x=="oct") return 10;
	if(x=="nov") return 11;
	if(x=="dec") return 12;
	if(x=="tam") return 13;
	if(x=="hel") return 14;
	if(x=="maa") return 15;
	if(x=="huh") return 16;
	if(x=="tou") return 17;
	if(x=="kes") return 18;
	if(x=="hei") return 19;
	if(x=="elo") return 20;
	if(x=="syy") return 21;
	if(x=="lok") return 22;
	if(x=="mer") return 23;
	if(x=="jou") return 24;
	
}
int transfer2(string x){
	if(x=="tam") return 1;
	if(x=="hel") return 2;
	if(x=="maa") return 3;
	if(x=="huh") return 4;
	if(x=="tou") return 5;
	if(x=="kes") return 6;
	if(x=="hei") return 7;
	if(x=="elo") return 8;
	if(x=="syy") return 9;
	if(x=="lok") return 10;
	if(x=="mer") return 11;
	if(x=="jou") return 12;
}
void Mars(string str){
	stringstream temp;
	int t;
	temp<<str;
	temp>>t;
	stack<int> s;
	while(t!=0){
		s.push(t%13);
		t/=13;
	}
	if(s.size()==0) printf("tret\n");
	else{
	  if (s.size()==2){
		t=s.top();
	    s.pop();
	    if(t==1) printf("tam ");
	    if(t==2) printf("hel ");
	    if(t==3) printf("maa ");
	    if(t==4) printf("huh ");
		if(t==5) printf("tou ");
	    if(t==6) printf("kes ");
	    if(t==7) printf("hei ");
	    if(t==8) printf("elo ");
	    if(t==9) printf("syy ");
	    if(t==10) printf("lok ");
	    if(t==11) printf("mer ");
	    if(t==12) printf("jou ");
	  }
	  t=s.top();
	  s.pop();
	    if(t==0) printf("tret");
	    if(t==1) printf("jan");
	    if(t==2) printf("feb");
	    if(t==3) printf("mar");
	    if(t==4) printf("apr");
		if(t==5) printf("may");
	    if(t==6) printf("jun");
	    if(t==7) printf("jly");
	    if(t==8) printf("aug");
	    if(t==9) printf("sep");
	    if(t==10) printf("oct ");
	    if(t==11) printf("nov");
	    if(t==12) printf("dec");
    }	
    printf("\n");
}

void Earth(string str){
	string t1,t2;
	int i,k,f,s;

    if (str.length()==3||str.length()==4){
    	 f=transfer1(str);
    	 s=0;
	}
	else{
		t2=str.substr(0,3);
		t1=str.substr(4,3);
		f=transfer1(t1);
		s=transfer2(t2);
	}
	printf("%d\n",f+s*13);	
}
int main(){
	int n;
	string str;
	scanf("%d",&n);
	getchar();
	while(n--){
		getline(cin,str);
		if (str[0]>='0'&&str[0]<='9')
		   Mars(str);
		else
		   Earth(str);
	}
}
