#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int correct=0,k=0;
struct tree{
	int data;
	struct tree* leftptr;
	struct tree* rightptr;
};


typedef struct tree* Treeptr;




struct stack{
	int data;
	struct stack *nextptr;
}; 

typedef struct stack *Stackptr;

Treeptr address=NULL;

int isempty(Stackptr top){
	return top==NULL;
}

void push(Stackptr *top,int value){
	Stackptr newptr=(struct stack*)malloc(sizeof(struct stack));
	if(newptr!=NULL){
		newptr->data=value;
		newptr->nextptr=*top;
		*top=newptr;
	}
}

int pop(Stackptr *top){
	if(isempty(*top)){
			return -1;	
	}
	else{
		Stackptr temp=*top;
		int value=(*top)->data;
		(*top)=(*top)->nextptr;
		free(temp);
		return value;
	}	
}
void insertTree(Treeptr *root,int value){
	if((*root)==NULL){
		*root=(struct tree*)malloc(sizeof(struct tree));
		if(*root!=NULL){
			(*root)->data=value;
			(*root)->leftptr=NULL;
			(*root)->rightptr=NULL;
		}
	}
	else{
		if(value<=(*root)->data){
			insertTree(&(*root)->leftptr,value);
		}
		else{
			insertTree(&(*root)->rightptr,value);
		}
	}
}

void TreeAddress(Treeptr *root,int value){
	
	while(*root!=NULL)
	{
       // printf("1:%d\n",(*root)->data);
		if((*root)->data==value){
		
			address=(*root);
            
            break;
		}
		else if(value<=(*root)->data){
		
			(*root)=(*root)->leftptr;
		}
		else if(value>(*root)->data){
		
			(*root)=(*root)->rightptr;	
		}
	}
//    if(*root==NULL){
//        //printf("\n1\n");
//        //correct=1;
//    }
	
}

void ret(Treeptr *try,Treeptr *order,Stackptr *top){
	while(*try!=NULL){
		push(&(*top),(*try)->data);
		*try=*order;
	}
}
// void InOrder(Treeptr *root){
// 	Stackptr top=NULL;
// 	Treeptr cur=*root;
// 	ret(&cur,&cur->leftptr,&top);
// 	if(cur==NULL&&top!=NULL){
// 		int h=pop(&top);
		
// 	}
	
	
	
	
// }
void InOrder(Treeptr *root,int k){
	Stackptr top=NULL;
	Treeptr cur=*root;
	int i=0,str[k];
	while(1){
		while(cur!=NULL){
           
			push(&top,cur->data);
			cur=cur->leftptr;
		}
		if(cur==NULL&&top!=NULL){
			Treeptr temp=*root;
			int h=pop(&top);
			TreeAddress(&temp,h);
			str[i]=h;
			i++;
			cur=address;
			cur=cur->rightptr;
			continue;
		}
		else if(cur==NULL&&top==NULL){
			break;
		}
	}
	for(int j=0;j<k;j++){
		if(j==k-1){
			printf("%d",str[j]);
		}
		else{
			printf("%d ",str[j]);
		}
	}
}
void PreOrder(Treeptr *root,int k){
	Stackptr top=NULL;
	Treeptr cur=*root;
	int i=0,str[k];
	push(&top,cur->data);
	while(top!=NULL){
		Treeptr temp=*root;
		int h=pop(&top);
		TreeAddress(&temp,h);
		str[i]=h;
		i++;
		//printf("%d ",h);
		if(address->rightptr!=NULL){
            push(&top,address->rightptr->data);
        }
		if(address->leftptr!=NULL){
            push(&top,address->leftptr->data);
        }
		
	}
	for(int j=0;j<k;j++){
		if(j==k-1){
			printf("%d",str[j]);
		}
		else{
			printf("%d ",str[j]);
		}
	}
}
void PostOrder(Treeptr *root,int k){
    Stackptr top1=NULL;
    Stackptr top2=NULL;
	Treeptr cur=*root;
	push(&top1,cur->data);
	while(top1!=NULL){
		Treeptr temp=*root;
		int h=pop(&top1);
		push(&top2,h);
		TreeAddress(&temp,h);
		if(address->leftptr!=NULL){
            push(&top1,address->leftptr->data);
        }
		if(address->rightptr!=NULL){
            push(&top1,address->rightptr->data);
        }
		
	}
	while(top2!=NULL){
		if(top2->nextptr==NULL){
			printf("%d",top2->data);
		}
		else{
			printf("%d ",top2->data);
		}
		
		top2=top2->nextptr;
	}
}
int main(){
	Treeptr root=NULL;
	
	int value;
	while(scanf("%d",&value)){
        
		insertTree(&root,value);
		k++;
	}
	char str[10];
	while(scanf("%s",str)!=EOF){
		if(!strcmp(str,"InOrder")){
            
			InOrder(&root,k);
            printf("\n");
		}
		else if(!strcmp(str,"PreOrder")){
			PreOrder(&root,k);
            printf("\n");
		}
		else if(!strcmp(str,"PostOrder")){
			PostOrder(&root,k);
            printf("\n");
		}
	}
	
}
