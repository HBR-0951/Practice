#include<stdio.h>  
void binary_cal(int n){  
     int r;  
     r = n % 2;  
     if(n >= 2)  
           binary_cal(n/2);   //�ϥλ��j�禡��{�A���θ��h�O����A����t�׸��C
     printf("%d",r);  
     return 0;  
}  
int main(void){  
      int num;  
      printf("�п�J�@�ӤQ�i����ơG\n");  
      while(scanf("%d",&num) == 1){  
           printf("�Q�i������ഫ���G�i���ƬO�G\n")�F  
           binary_cal(num);  
           putchar('\n')�F  
      }  
      return 0;   
} 
