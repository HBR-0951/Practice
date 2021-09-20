#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int order=0;
struct List{
	char value;
	int order;
	struct List* nextptr;
};

typedef struct List* listptr;


void insert(listptr* head,listptr* tail,char value,int number){
	listptr newptr=(struct List*)malloc(sizeof(struct List));
	if(newptr!=NULL){
		newptr->value=value;
		newptr->order=number;
		newptr->nextptr=NULL;
		if((*head)==NULL){
			    if(number==0){
                    (*head)=newptr;
                   
                   
                }
				else{
                    printf("Index out of range\n");
                }
            (*tail)=newptr;
		}
		else{
			
			if(number>((*tail)->order)+1){
				printf("Index out of range\n");
			}
			else if(number==0){
                listptr temp=*head;
				newptr->nextptr=temp;
				(*head)=newptr;
                listptr retry=newptr;
			    int i=number;
                while(retry!=NULL){
                    retry->order=i;
                    i++;
                   
                    retry=retry->nextptr;
                }
			}
			else{
				listptr temp=(*head);             
                while(temp!=NULL){	
                	if(temp->nextptr==NULL){
				    (*tail)->nextptr=newptr;
				    (*tail)=newptr;
                   
                    break;
                    }
                    else if(temp->nextptr->order==number){
                       
                        newptr->nextptr=temp->nextptr;
                         
                   		temp->nextptr=newptr;
                        
                        listptr retry=newptr;
					    int i=number;
                        while(retry!=NULL){
                            retry->order=i;
                            i++;
                            
                            retry=retry->nextptr;
                        }
					    break;
               		}
           	        temp=temp->nextptr;
				}
				    
            }		
		}			
	}
}
	
void delete(listptr *head,listptr *tail,int order){
	char value;
	if((*head)==NULL){
		printf("List is Empty\n");
	}
	else{
		if(order>(*tail)->order){
			printf("Index out of range\n");
		}
		else if(order==0){
			value=(*head)->value;
			*head=(*head)->nextptr;
			listptr retry=*head;
			int i=0;
			while(retry!=NULL){
				retry->order=i;
				i++;
				retry=retry->nextptr;
			}
            printf("%c\n",value);
		}
		else{
			listptr temp=*head;
			while(temp!=NULL){
				if(temp->nextptr->order==order){
					value=temp->nextptr->value;
					temp->nextptr=temp->nextptr->nextptr;
                    listptr retry=*head;
			        int i=0;
			        while(retry!=NULL){
				        retry->order=i;
				        i++;
				        retry=retry->nextptr;
			        }
                    break;
				}
				temp=temp->nextptr;
			}
            listptr newtemp=*head;
            while(newtemp!=NULL){
                if(newtemp->nextptr==NULL){
                    (*tail)=newtemp;
                }
                newtemp=newtemp->nextptr;
            }
			printf("%c\n",value);
		}
	}
}

int main(){
	char string[10];
	listptr head=NULL;
	listptr tail=NULL;
	while(scanf("%s",string)!=EOF){
		if(!strcmp(string,"insert")){
            
			char value;
			int number;
			scanf(" %c",&value);
			scanf("%d",&number);
			insert(&head,&tail,value,number);
            
		}
		else if(!strcmp(string,"delete")){
			int order;
			scanf("%d",&order);
		    delete(&head,&tail,order);
            
		}
		else if(!strcmp(string,"print")){
			listptr temp=head;
			while(temp!=NULL){
				if(temp->nextptr==NULL){
					printf("%c\n",temp->value);
				}
				else{
					printf("%c ",temp->value);
				}
				temp=temp->nextptr;
			}
		}
	}
}
