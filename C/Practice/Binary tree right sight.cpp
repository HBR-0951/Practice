#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str[100],max=0;
struct tree{
	int data;
	struct tree* leftptr;
	struct tree* rightptr;
};


typedef struct tree* Treeptr;




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
void level(Treeptr *root,int i){
    if(*root!=NULL){
        if(i>max){
            max=i;
        }
        if(str[i]==0){
            str[i]=(root)->data;
        }
        if((*root)->rightptr!=NULL){
            level(&(*root)->rightptr,i+1);
        }
        if((*root)->leftptr!=NULL){
            level(&(*root)->leftptr,i+1);
        }
    }
}
void rightSideView(Treeptr *root){
    int i=0;
    level((root),i);
    for(int j=0;j<=max;j++){
        printf("%d ",str[j]);
    }
    
}

int main(){
	Treeptr root=NULL;
	
	int value;
	while(scanf("%d",&value)!=EOF){
		insertTree(&root,value);
	}
	rightSideView(&root);
}
