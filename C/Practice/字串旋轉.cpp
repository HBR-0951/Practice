#include<stdio.h>


int main(){
	
	int n,row=0,column=0,newrow=0;
	scanf("%d",&n);
	char str[n][100],ne[100][n];
	int time[n];
	for(;row<n;row++){
	
		scanf(" %[^\n]",&str[row]);	
		
				
	}
	for(int i=0;i<n;i++){
		time[i]=0;
	}
	int max=0;
	int s=0;					//Âà´« 
	for(int i=n-1;i>-1;i--){
		while(str[i][column]!=NULL){
			ne[column][newrow]=str[i][column];
			
			
			time[s]++;
			column++;
		}
		if(max<column){
			max=column;
		}
		s++;
		column=0;
		newrow++;
	}
	
	for(int i=0;i<n;i++){
		printf("time:%d\n",time[i]);
	}
	
	for(int i=0;i<max;i++){
		for(int j=0;j<n;j++){
			if(i<time[j]){
				
				printf("%c",ne[i][j]);
			}
			else{
				printf(" ");
				continue;
			}
			
		}
		if(i<max-1){
			printf("\n");	
		}
	}
	
}
