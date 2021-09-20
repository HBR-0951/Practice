#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct str{
	char data;
	struct str *next;
}; 

typedef struct str node;
typedef node *nodeptr;



void enquence(nodeptr *head,nodeptr *tail,char value)
{
	
	nodeptr newptr=(node*)malloc(sizeof(node));
		
	if(newptr!=NULL)
	{
		
		newptr->data=value;
	
		newptr->next=NULL;
	
		if(*head==NULL)
		{
			*head=newptr;
		}
		else{
			(*tail)->next=newptr;
		}
	*tail=newptr;
	}

	
}

void dequence(nodeptr *head){
	
	if(*head==NULL){
		printf("Queue is Empty\n");
	
	}
	else{
		nodeptr temp=*head;
		char i=(*head)->data;
		*head=(*head)->next;
		free(temp);
		printf("%c\n",i);
	}
}

int main()
{

	nodeptr head=NULL;
	nodeptr tail=NULL;


	
	
	char s[10];
	char *value=(char*)malloc(10*sizeof(char));
	int i=0,j=0;



	
		
	while(scanf("%s",s)!=EOF){
	
		if(!strcmp(s,"enque")){
			int h=0;
			if(i==10){
					printf("Queue is full\n");
					j=10;
					
					continue;
				}
			scanf("%s",value);
				
			j+=strlen(value);
		
			
			while(i<j){
				if(i>=10){
					printf("Queue is full\n");
					j=10;
					break;
				}
				enquence(&head,&tail,*(value+h));
			
				h++;	
				i++;			
				
				
			}
			
		
		}
		
			
		
			

		else if(!strcmp(s,"deque")){
			int a;
			scanf("%d",&a);
			if(head==NULL){
				printf("Queue is Empty\n");
				continue;
			}
			else{
				for(int k=0;k<a;k++){
					if(head==NULL){
						printf("Queue is Empty\n");
						break;
					}
					else{
						nodeptr temp=head;
						char i=(head)->data;
						head=(head)->next;
						free(temp);
						printf("%c\n",i);
					
					}
				}
				j-=a;
				i-=a;
				
				
			}
			
					
		}
		else if(!strcmp(s,"print")){
			nodeptr newhead=head;
			while(newhead!=NULL){
				if(newhead->next==NULL){
					printf("%c",newhead->data);
				}
				else{
					printf("%c ",newhead->data);
				}
				
				newhead=newhead->next;
			}
			printf("\n");
		}
	}
	

	

	
	
	
}


