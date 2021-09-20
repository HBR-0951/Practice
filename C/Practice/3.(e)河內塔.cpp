#include <stdio.h>

int moved=0;

void hanoi(int n, char A, char B, char C) {
	
  
	
    if(n>=1){
    
        hanoi(n-1, A, C, B);
     
        printf("%d:%d %c %c\n",++moved,n,A, C);
        hanoi(n-1, B, A, C);
         
    }
    
}

int main() {
    int n;
    char A,B,C;
  
    scanf("%d", &n);
    scanf("%c%c%c",&A,&B,&C);
    hanoi(n,A,B,C);
    
   
    
}
