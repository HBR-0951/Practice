include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int val;
	struct Node *next;
}node;

void sort(node** head){
	node *Head=(node*)malloc(sizeof(node));
	Head->val=(*head)->val;
	Head->next=NULL;
	node* first=(*head)->next;
	while(first!=NULL){
		node* q=Head;
		node* p;
		node* newptr=(node*)malloc(sizeof(node));
		newptr->val=first->val;
		while(q!=NULL&&(q->val<newptr->val)){
			p=q;
			q=q->next;
		}
		if(q==Head){
			Head=newptr;
		
		}
		else{
			p->next=newptr;
		}
		newptr->next=q;
		first=first->next;
	}
    *head=Head;
    
    
	
}
void enque(node** head,node **tail,int h){
	node* newptr=(node*)malloc(sizeof(node));
	newptr->val=h;
	newptr->next=NULL;
	if(*head==NULL){
		*head=newptr;
	}
	else{
		(*tail)->next=newptr;
	}
	(*tail)=newptr;
}

int main(){
	node* head=NULL;
	node* tail=NULL;
	int h;
	while(scanf("%d",&h)!=EOF){
		enque(&head,&tail,h);
	}
	
    sort(&head);
    node* temp=head;
    
}

