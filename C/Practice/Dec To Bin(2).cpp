#include<stdio.h>  
void binary_cal(int n){  
     int r;  
     r = n % 2;  
     if(n >= 2)  
           binary_cal(n/2);   //使用遞迴函式實現，佔用較多記憶體，執行速度較慢
     printf("%d",r);  
     return 0;  
}  
int main(void){  
      int num;  
      printf("請輸入一個十進位制整數：\n");  
      while(scanf("%d",&num) == 1){  
           printf("十進位制整數轉換為二進位制數是：\n")；  
           binary_cal(num);  
           putchar('\n')；  
      }  
      return 0;   
} 
