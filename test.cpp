#include<bits/stdc++.h>
using namespace std;
char s[1024],stack1[1024];
int isTerminal(char c){
	if(c!='N') return 1;
	return 0;
} 
int cmp(char a, char b){
	int flag[6][6]={
	{1,-1,-1,-1,1,1},
	{1,1,-1,-1,1,1},
	{1,1,2,2,1,1},
	{-1,-1,-1,-1,0,2},
	{1,1,2,2,1,1},
	{-1,-1,-1,-1,2,0}
	};
	int i,j;
	if(a=='+') i=0;
	if(a=='*') i=1;
	if(a=='i') i=2;
	if(a=='(') i=3;
	if(a==')') i=4;
	if(a=='#') i=5;
	
	if(b=='+') j=0;
	if(b=='*') j=1;
	if(b=='i') j=2;
	if(b=='(') j=3;
	if(b==')') j=4;
	if(b=='#') j=5;
	
	return flag[i][j];
}
int R(int st,char c){
	int top1=st,j=st;
	while(cmp(stack1[j],c)==1){
		if(isTerminal(stack1[top1])==0) j=top1-1;
		else j=top1;
		if(stack1[j]=='i'){
			stack1[j]='N';
			printf("R\n");
		}
		else if((stack1[j]=='+'||stack1[j]=='*')&&stack1[j+1]=='N'&&stack1[j-1]=='N'){
			top1-=2;
			stack1[top1]='N'; 
			printf("R\n");
		}
		else if (stack1[j]==')'&&stack1[j-1]=='N'&&stack1[j-2]=='('){
			top1-=2;
			stack1[top1]='N';
			printf("R\n");
		}
		else if(stack1[j]=='#') break;
		
		else return 0;
	}
	stack1[++top1]=c;
	if(c!='#')
	printf("I%c\n",stack1[top1]);
	return 1;
}
int main(int argc,char *argv[]){
	FILE *fp;
	fp = fopen(argv[1], "rb");
	while(fgets(s,1024,fp)){
		int top=0,j=0;
		stack1[top]='#';
		int len= strlen(s);
		s[len-2]='#';
		s[len-1]='\0';
		for(int i=0;s[i]!='\0';i++){
			if(isTerminal(stack1[top])) j=top;
			else j=top-1;
			if(cmp(stack1[j],s[i])==1){
				if(!R(j,s[i])){
					printf("RE\n");
					return 0;
				} 
				top++;
			}
			else if(cmp(stack1[j],s[i])==-1){
				top++;
				stack1[top]=s[i];
				printf("I%c\n",stack1[top]);
			}
			else if(cmp(stack1[j],s[i])==0){
				if(s[i]=='#'){
					return 0;
				}
				stack1[++top]=s[i];
				printf("I%c",stack1[top]);
			}
			else{
				printf("E\n");
				break;
			}
		}
}
} 
