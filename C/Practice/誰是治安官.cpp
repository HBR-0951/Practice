#include<stdio.h>


int main(){
	int people,a,b,c=0;
	scanf("%d",&people);
	int num[people];
	int str[people][people],d[100],h=0;
	for(int i=0;i<people;i++){
		num[i]=0;
		for(int j=0;j<people;j++){
			str[i][j]=0;
		}
	}
	while(scanf("%d",&a)!=EOF){
		scanf("%d",&b);
        d[h]=a;
        h++;
        // printf("num[%d]:%d\n",b-1,num[b-1]);
        str[b-1][num[b-1]]=a;
        num[b-1]++;
	}
		
	// for(int i=0;i<people;i++){
	// 	for(int j=0;j<people;j++){
	// 		printf("%d ",str[i][j]);
	// 	}
	// printf("\n");
	// }
	for(int i=0;i<people;i++){
		if(num[i]==people-1){
	        c=i+1;
	        //printf("c:%d\n",c);
	    }
	}
    if(c==0){
        printf("-1");
    }
    else{
        for(int i=0;i<h;i++){
            if(d[i]==c){
                printf("-1");
            }
            else if(d[i]!=c&&i==h-1){
                printf("%d",c);
            }
        }
    }
    
	
} 
