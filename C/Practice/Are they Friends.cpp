#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int h=0,people;

// union list{
// 	int data;
// 	int order;
	
// }; 
// typedef union list List;

// void makeFriend(){
	
// }

int main(){
    int people;
	scanf("%d",&people);
	int str[2][people+1];
	char s[10];
    for(int i=0;i<people+1;i++){
        str[0][i]=i;
        str[1][i]=i;
    }
	while(scanf("%s",s)!=EOF){
		if(!strcmp(s,"BeFriend")){
			int a,b;
			scanf("%d",&a);
			scanf("%d",&b);
            if(a<b){
                for(int i=0;i<people+1;i++){
                    
                    if(str[1][i]==str[1][b]){
                        str[1][i]=str[1][a];
                    }
                }       
            }
            else{
                for(int i=0;i<people+1;i++){
                    if(str[1][i]==str[1][a]){
                        str[1][i]=str[1][b];
                    }
                }         
            }
		 }
		if(!strcmp(s,"IsFriend")){
			int a,b;
			scanf("%d",&a);
			scanf("%d",&b);
            if(str[1][a]==str[1][b]){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
		}
	}
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<people+1;j++){
    //         printf("%d ",str[i][j]);
    //     }
    //     printf("\n");
    // }
	
}
