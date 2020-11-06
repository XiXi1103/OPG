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
