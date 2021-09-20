
#include<stdio.h>
#include<string.h>
void swap(char *a, char *b)
{ //外部函式，互換元素資料
char c;
c=*a;
*a=*b;
*b=c;
}
//外部函式，印出所有元素排列void fun(int a,int b,char element[])
{
int k;
if(b==1)//長度為一時，直接列印。
{
printf("%c\n",element[a]);
}
else if(b==2)
{ //長度為二時 ，
//把之前遞迴的的元素列出，
//之後互換末兩位元素

for(k=0;k<a;k++){

printf("%c",element[k]);
}
printf("%c%c\n",element[a],element[a+1]);
for(k=0;k<a;k++)
{
printf("%c",element[k]);
}printf("%c%c\n",element[a+1],element[a]);
}
else
{ //當長度大於3時利用下列遞迴
for(k=0;k<b;k++)
{
//用swap使所有元素都能列於相對的第一位置上
swap(&element[a],&element[a+k]);
fun(a+1,b-1,element);//之後慢慢遞迴，使之成為simple case
swap(&element[a],&element[a+k]);//然後再換回來
}
}
}


int main(void)
{
char element[11];//宣告變數element
int len;//宣告變數len
printf("請給定元素，至多10個>");
gets(element);//把使用者給的值存回element
len=strlen(element);//查定element的長度
fun(0,len,element);//外部函數作用開始
return(0);
}

