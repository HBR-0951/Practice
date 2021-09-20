#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int str[100],a=0,c=0,n;
	while(scanf("%d",&n)){

	if(n==0){
		
		c++;
	}
	else{
		str[a]=n;
		printf("%d ",str[a]);
	}
		
		a++;
	}
	for(int i=0;i<c;i++){
		if(i==(c-1)){
			printf("0");
		}
		else{
			printf("0 ");
		}
		
	}
	} 
	
	
