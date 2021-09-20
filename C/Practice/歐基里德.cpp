#include<stdio.h>
int G(int a,int b){
	
	if(b==0){
		return a;
	}
	else{
		return G(b,a%b);
	}
	
}
