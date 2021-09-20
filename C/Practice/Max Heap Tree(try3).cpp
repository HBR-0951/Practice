#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree{
	int data;
    struct tree* leftptr;
    struct tree* rightptr;
};

struct list{
	int data;
	struct list* nextptr;
};
typedef struct tree* treeptr;
typedef struct list* listptr;

listptr head=NULL;
listptr tail=NULL;

treeptr Address=NULL;
int str[100],h=0;
void enqueue(int value){
    str[h]=value;
    // printf("str[%d]:%d\n",h,str[h]);
    h++;
}

void treeAddress(treeptr* root,int value){
    
	if(*root!=NULL){
		if((*root)->data==value){
			Address=*root;
		}
		else{
			treeAddress(&(*root)->leftptr,value);
			treeAddress(&(*root)->rightptr,value);
		}
	}
}
void InOrder(treeptr *root){
	if((*root)!=NULL){
		InOrder(&(*root)->leftptr);
		printf("InOrder:%d\n",(*root)->data);
		InOrder(&(*root)->rightptr);
	}

}
void insertTree(treeptr* root,int value){
    
	if((*root)==NULL){
		*root=(struct tree*)malloc(sizeof(struct tree));
		if(*root!=NULL){
			enqueue(value);
			(*root)->data=value;
			(*root)->leftptr=NULL;
			(*root)->rightptr=NULL;
		}
        
         treeAddress(&*root,value);
         Address=NULL;
	}
	else{
        
 		int k=0;
        treeptr tr=*root;
 		while(k<h){

 			treeAddress(&tr,str[k]);
 			if(Address->leftptr==NULL){

                treeptr newptr=(treeptr)malloc(sizeof(struct tree));
				newptr->data=value;
				newptr->leftptr=NULL;
				newptr->rightptr=NULL;
				if(newptr!=NULL){
				Address->leftptr=newptr;
				}
				enqueue(value);
                
				break;
			}
           
			else if(Address->rightptr==NULL){
               
				treeptr newptr=(treeptr)malloc(sizeof(struct tree));
				newptr->data=value;
				newptr->leftptr=NULL;
				newptr->rightptr=NULL;
				if(newptr!=NULL){
				Address->rightptr=newptr;
				}
				enqueue(value);
               
				break;
			}		     
 				 k++;
 		}
	}
}

void switchTree(treeptr* a,treeptr* b){
    int temp=(*a)->data;
    (*a)->data=(*b)->data;
    (*b)->data=temp;
}
void switchList(int a,int b){
    int temp=a;
    
    
}
// void check(treeptr* root){
    
//     if(*root!=NULL){
        
//         if((*root)->leftptr!=NULL||(*root)->rightptr!=NULL){
//             if((*root)->leftptr!=NULL){
//                 if((*root)->leftptr->data>(*root)->data){
//                     switchTree(&(*root)->leftptr,&(*root));
//                     switchList((*root)->leftptr->data,(*root)->data);
                    
//                 }
//             }
//             if((*root)->rightptr!=NULL){
//                 if((*root)->rightptr->data>(*root)->data){
//                     switchTree(&(*root)->rightptr,&(*root));
//                     switchList((*root)->rightptr->data,(*root)->data);
                    
//                 }
//             }
//         }
//         else{
//             check(&(*root)->leftptr);
//             check(&(*root)->rightptr);
//         }
        
//     }
// }
void check(treeptr* root){
    
    if(*root!=NULL){
        
        if((*root)->leftptr!=NULL||(*root)->rightptr!=NULL){
            if((*root)->leftptr!=NULL){
                if((*root)->leftptr->data>(*root)->data){
                    switchTree(&(*root)->leftptr,&(*root));
                    switchList((*root)->leftptr->data,(*root)->data);
                    
                }
            }
            if((*root)->rightptr!=NULL){
                if((*root)->rightptr->data>(*root)->data){
                    switchTree(&(*root)->rightptr,&(*root));
                    switchList((*root)->rightptr->data,(*root)->data);
                    
                }
            }
        }
        else{
            check(&(*root)->leftptr);
            check(&(*root)->rightptr);
        }
        
    }
}
int main(){
	int value;
	treeptr root=NULL;
   
	while(scanf("%d",&value)!=EOF){
        // printf("h:%d\n",h);
		insertTree(&root,value);
        // printf("Insert:\n");
        // InOrder(&root);
        // printf("root:%d\n",root->data);
        // if(root->leftptr!=NULL){
        //     printf("root->leftptr:%d\n",root->leftptr->data);
        // }
        // if(root->rightptr!=NULL){
        //     printf("root->rightptr:%d\n",root->rightptr->data);
        // }
		// check(&root);
		// printf("\ncheck:\n\n");
		// InOrder(&root);
		// printf("root:%d\n",root->data);
		// if(root->leftptr!=NULL){
		// printf("root->leftptr:%d\n",root->leftptr->data);
		// }
		// if(root->rightptr!=NULL){
		// printf("root->rightptr:%d\n",root->rightptr->data);
		// }
		// h++;
	}
    InOrder(&root);
    
}
