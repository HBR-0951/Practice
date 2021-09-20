#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int correct=0;
struct tree{
	int data;
	struct tree* leftptr;
	struct tree* rightptr;
};

struct list{
	int data;
	struct list* nextptr;
};
typedef struct tree* Treeptr;
typedef struct list* Listptr;

Treeptr address=NULL;

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
void InOrder(Treeptr *root){
	if((*root)!=NULL){
		InOrder(&(*root)->leftptr);
		printf("%d ",(*root)->data);
		InOrder(&(*root)->rightptr);
	}

}
void PreOrder(Treeptr *root){
	if((*root)!=NULL){
		printf("%d ",(*root)->data);
		PreOrder(&(*root)->leftptr);
		PreOrder(&(*root)->rightptr);
	}

}

void PostOrder(Treeptr *root){
	if((*root)!=NULL){
		PostOrder(&(*root)->leftptr);
		PostOrder(&(*root)->rightptr);
		printf("%d ",(*root)->data);
	}

}
void enque(Listptr* head,Listptr* tail,int value){
	Listptr newptr=(Listptr)malloc(sizeof(struct list));
	if(newptr!=NULL){
		newptr->data=value;
		newptr->nextptr=NULL;
		if(*head==NULL){
			*head=newptr;
		}
		else{
			(*tail)->nextptr=newptr;
		}
		*tail=newptr;
	}
	
}
void TreeAdress(Treeptr *root,int value){
	
	while(*root!=NULL)
	{
       // printf("1:%d\n",(*root)->data);
		if((*root)->data==value){
		
			address=(*root);
            printf("%d ",address->data);
            break;
		}
		else if(value<=(*root)->data){
		
			(*root)=(*root)->leftptr;
		}
		else if(value>(*root)->data){
		
			(*root)=(*root)->rightptr;	
		}
	}
    if(*root==NULL){
        //printf("\n1\n");
        //correct=1;
    }
	
}
void LevelOrder(Treeptr *root){
	Listptr head=NULL;
	Listptr tail=NULL;
    Treeptr check=*root;
	if((*root)!=NULL){
		enque(&head,&tail,(*root)->data);
       printf("%d ",(*root)->data);
	}
    int i=0;
	while((*root)!=NULL){
    //while(i<7){
        Treeptr temp=check;
        //printf("temp->data:%d\n",temp->data);
		if((*root)->leftptr!=NULL){
            //printf("\nleft\n");
			enque(&head,&tail,(*root)->leftptr->data);
            //printf("(*root)->leftptr->data:%d\n",(*root)->leftptr->data);
		}
		if((*root)->rightptr!=NULL){
           // printf("\nright\n");
			enque(&head,&tail,(*root)->rightptr->data);
           // printf("(*root)->rightptr->data:%d\n",(*root)->rightptr->data);
		}
        
		//printf("2:%d\n",head->data);
		head=head->nextptr;
        if(head!=NULL){
            TreeAdress(&temp,head->data);
		    (*root)=address;
            i++;
        }
        else{
            break;
        }
		
	}
}


int main(){
	Treeptr root=NULL;
	
	int value;
	while(scanf("%d",&value)!=EOF){
		insertTree(&root,value);
	}
	InOrder(&root);
	printf("\n");
	PreOrder(&root);
	printf("\n");
	PostOrder(&root);
	printf("\n");
    LevelOrder(&root);
}
