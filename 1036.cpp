#include<cstdio>
#include<string>
#include<cstring>
struct  info{
	char na[12];
	char male;
	char id[12];
	int grade;
}stu;
int main(){
	info m,f;
	m.grade=101;
	f.grade=-1;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s %c %s %d",stu.na,&stu.male,stu.id,&stu.grade);
		if(stu.male=='M'){
			if(stu.grade<m.grade){
				strcpy(m.na,stu.na);
				m.male='M';
				strcpy(m.id,stu.id);
				m.grade=stu.grade;
			}
		}
		else{
			if(stu.grade>f.grade){
				strcpy(f.na,stu.na);
				f.male='F';
				strcpy(f.id,stu.id);
				f.grade=stu.grade;
			}
		}
	}
	if(f.grade!=-1) printf("%s %s\n",f.na,f.id);
	else printf("Absent\n");
	if(m.grade!=101) printf("%s %s\n",m.na,m.id);
	else printf("Absent\n");
	if(f.grade!=-1&&m.grade!=101) printf("%d",f.grade-m.grade);
	else printf("NA");
	return 0;
}
