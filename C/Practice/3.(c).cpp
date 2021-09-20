#include<stdio.h>


int A(int m,int n){
	int s;
	if(m==0){
	
		return n+1;
	}
	if(m>0&&n==0){
		return A(m-1,1);
	}
	if(m>0&&n>0){
		return A(m-1,A(m,n-1));
	}
}

int main(){

	int m,n,N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
	scanf("%d",&m);
	scanf("%d",&n);
	printf("%d\n",A(m,n));
}
}
