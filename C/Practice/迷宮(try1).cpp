#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct str{
	char data;
	struct str *next;
}; 

typedef struct str node;
typedef node *nodeptr;



void push(nodeptr *top,char value);
char pop(nodeptr *top);
int isempty(nodeptr top){
	return top==NULL;
}
int main()
{

	nodeptr top=NULL;
	nodeptr temp=NULL;
	*temp=*top;
	int n,h=0,k=0;
	scanf("%d",&n);
	int s[n][n];
	while(h!=n||k!=n){
		if(s[h][k+1]!=0&&s[h][k+1]!=-1){
			char value='E';
			push(&top,value);
			s[h][k]=-1;
			k++;
		}
		else if(s[h+1][k]!=0&&s[h+1][k]!=-1){
			char value='S';
			push(&top,value);
			s[h][k]=-1;
			h++;
		}
		else if(s[h][k-1]!=0&&s[h][k-1]!=-1){
			char value='W';
			push(&top,value);
			s[h][k]=-1;
			k--;
		}
		else if(s[h-1][k]!=0&&s[h-1][k]!=-1){
			char value='N';
			push(&top,value);
			s[h][k]=-1;
			h--;
		}
		else{
			s[h][k]=0;
			pop(&top);
			
		}
		
	}
	while(temp!=NULL){
		printf("%c",temp->data);
		temp=temp->next;
	}
	
	
	
	
	
}
void push(nodeptr *top,char value)
{
	
	nodeptr newptr=(node*)malloc(sizeof(node));
		
	if(newptr!=NULL)
	{
		
		newptr->data=value;
	
		newptr->next=*top;
	
		*top=newptr;
	
	}
	
}
char pop(nodeptr *top)
{
		if(isempty(*top)){
			return -1;	
		}

		nodeptr temp=*top;
		char i=(*top)->data;
		*top=(*top)->next;
		free(temp);
}
