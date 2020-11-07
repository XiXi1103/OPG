#include<bits/stdc++.h>
using namespace std;
char s[1024],stack1[1024];
int top=0;
int isTerminal(char c){
	if(c!='N') return 1;
	return 0;
} 
int cmp1(char a, char b){
	int flag[6][7]={
	{1,-1,-1,-1,1,1,-2},
	{1,1,-1,-1,1,1,-2},
	{1,1,2,2,1,1,-2},
	{-1,-1,-1,-1,0,2,-2},
	{1,1,2,2,1,1,-2},
	{-1,-1,-1,-1,2,0,-2},
	};
	int i=0,j=6;
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
	int j=st;
	while(cmp1(stack1[j],c)==1){
		
		if(stack1[j]=='i'){
			stack1[j]='N';
			printf("R\n");
		}
		else if((stack1[j]=='+'||stack1[j]=='*')&&stack1[j+1]=='N'&&stack1[j-1]=='N'){
			stack1[top]='\0';
			stack1[top-1]='\0';
			top-=2;
			stack1[top]='N'; 
			printf("R\n");
		}
		else if (stack1[j]==')'&&stack1[j-1]=='N'&&stack1[j-2]=='('){
			stack1[top]='\0';
			stack1[top-1]='\0';
			top-=2;
			stack1[top]='N';
			printf("R\n");
		}
		else if(stack1[j]=='#') break;
		
		else return 0;
		if(isTerminal(stack1[top])==0) j=top-1;
		else j=top;
	}
	if(cmp1(stack1[j],c)==2){
		return 2;
	}
	if(c!='#'){
		stack1[++top]=c;
		printf("I%c\n",stack1[top]);
	}
	
	return 1;
}
int main(int argc,char *argv[]){
	FILE *fp;
	fp = fopen(argv[1], "rb");
	while(fgets(s,1024,fp)){
// 		while(~scanf("%s",s)){
		int j=0;
		top=0;
		stack1[top]='#';
		for(int k=0;s[k]!='\0';k++){
			if(s[k]=='\r'||s[k]=='\n')
				s[k]='\0';
		} 
		int len= strlen(s);
		s[len]='#';
		for(int i=0;i<=len;i++){
			if(isTerminal(stack1[top])) j=top;
			else j=top-1;
			int f=cmp1(stack1[j],s[i]);
			if(f==1){
				int p= R(j,s[i]);
				if(p==0){
					printf("RE\n");
					return 0;
				}
				if(p==2){
					printf("E\n");
					return 0;
				}
			}
			else if(f==-1){
				top++;
				stack1[top]=s[i];
				printf("I%c\n",stack1[top]);
			}
			else if(f==0){
				if(s[i]=='#'){
					return 0;
				}
				stack1[++top]=s[i];
				printf("I%c",stack1[top]);
			}
			else{
				printf("E\n");
				return 0;
			}
		}
		
		fclose(fp);
		return 0;
}
} 
