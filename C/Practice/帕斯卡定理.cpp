#include<stdio.h>

int main(){
	
	int a,n,num;
	scanf("%d",&n);
	
	num=n+1;
	int str[n+1][num];
	
	for(int i=0;i<n+1;i++){
		
		for(int j=0;j<=i;j++){
			if(j==0||i==j){
				str[i][j]=1;
			}
			if(j<i&&j!=0){
				str[i][j]=str[i-1][j-1]+str[i-1][j];
			}
			else{
			
			}
		}
	}

	for(int i=0;i<n+1;i++){
		
		for(int j=0;j<=i;j++){
			if(i==j){
				printf("%d",str[i][j]);
			}
			else{
				printf("%d ",str[i][j]);
			}
		
		}
		printf("\n");
		
	}
			
	
	
}
