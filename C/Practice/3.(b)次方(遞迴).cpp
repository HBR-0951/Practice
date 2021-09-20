#include<stdio.h>


int r(int x,int n){
	int s;
	if(n==0){
		
		return 1;
	}
	if(n==1){
		
		return x;
	}
	else if(n>=2){
		
		
		return x*r(x,n-1);
	}
	
}

int main(){
	
	int x,n,N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){

		scanf("%d",&x);
	
		scanf("%d",&n);
		printf("%d\n",r(x,n));
	}
	
	
}
