#include<stdio.h>

int move=0;
int chess(unsigned long long int n){
	if(n==0){
		return 0;
	}
	if (n==1) {
		move++;
		return move;
    }
    else {
    	move++;
    	return chess(n/2);
    }
}

int main(){
	
	unsigned long long int n;
	scanf("%llu",&n);
	printf("%d",chess(n));
} 

