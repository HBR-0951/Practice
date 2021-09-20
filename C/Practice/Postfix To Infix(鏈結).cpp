#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct str{
	double data;
	struct str *next;
}; 

typedef struct str node;
typedef node *nodeptr;



void push(nodeptr *top,double value)
{
	
	nodeptr newptr=(node*)malloc(sizeof(node));
		
	if(newptr!=NULL)
	{
		
		newptr->data=value;
	
		newptr->next=*top;
	
		*top=newptr;
	
	}
	
}
double pop(nodeptr *top)
{
		
		nodeptr temp=*top;
		double w=(*top)->data;
		*top=(*top)->next;
		free(temp);
		return w;
		
 } 

int main()
{
	char word;
	nodeptr top=NULL;
	

	while(scanf("%c",&word)!=EOF){
		
	
		
		if(word=='+'){
			
			double a=pop(&top);
			
			double b=pop(&top);
			
			push(&top,a+b);
		
			
		}
		else if(word=='-'){
			double a=pop(&top);
			double b=pop(&top);
			push(&top,b-a);
				
		
		}
		else if(word=='*'){
			double a=pop(&top);
			double b=pop(&top);
			push(&top,a*b);
				
			
		}
		else if(word=='/'){
			double a=pop(&top);
			double b=pop(&top);
			push(&top,b/a);
				
			
		}
		else {
			
			push(&top,(((double)word)-48));
		
		}
		
		
	}
	
	while(top!=NULL){
		printf("%lf",top->data);
		top=top->next;
	}
	return 0;
}

