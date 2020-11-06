#include<stdio.h>
#include<string.h>
char s[1024],stack[1024];
int isTerminal(char c){
	if(c!='N') return 1;
	return 0;
} 
int cmp(char a, char b){
	int flag[6][6]={//+ * i ( ) #
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
	while(cmp(stack[j],c)==1){
		if(isTerminal(stack[top1])==0) j=top1-1;
		else j=top1;
		if(stack[j]=='i'){
			stack[j]='N';
			printf("R\n");
		}
		else if((stack[j]=='+'||stack[j]=='*')&&stack[j+1]=='N'&&stack[j-1]=='N'){
			top1-=2;
			stack[top1]='N'; 
			printf("R\n");
		}
		else if (stack[j]==')'&&stack[j-1]=='N'&&stack[j-2]=='('){
			top1-=2;
			stack[top1]='N';
			printf("R\n");
		}
		else if(stack[j]=='#') break;
		
		else return 0;
	}
	stack[++top1]=c;
	if(c!='#')
	printf("I%c\n",stack[top1]);
	return 1;
}
int main(int argc,char *argv[]){
	FILE *fp;
	fp = fopen(argv[1], "rb");
	while(fgets(s,1024,fp)){
//		scanf("%s",s);
		int top=0,j;
		stack[top]='#';
		int len= strlen(s);
		s[len]='#';
		s[len+1]='\0';
		for(int i=0;s[i]!='\0';i++){
			if(isTerminal(stack[top])) j=top;
			else j=top-1;
			if(cmp(stack[j],s[i])==1){
				if(!R(j,s[i])){
					printf("RE\n");
					return 0;
				} 
				top++;
			}
			else if(cmp(stack[j],s[i])==-1){
				top++;
				stack[top]=s[i];
				printf("I%c\n",stack[top]);
			}
			else if(cmp(stack[j],s[i])==0){
				if(s[i]=='#'){
					return 0;
				}
				stack[++top]=s[i];
				printf("I%c",stack[top]);
			}
			else{
				printf("E\n");
				break;
			}
		}
}
} 
