
#include<stdio.h>
#include<string.h>
void swap(char *a, char *b)
{ //�~���禡�A�����������
char c;
c=*a;
*a=*b;
*b=c;
}
//�~���禡�A�L�X�Ҧ������ƦCvoid fun(int a,int b,char element[])
{
int k;
if(b==1)//���׬��@�ɡA�����C�L�C
{
printf("%c\n",element[a]);
}
else if(b==2)
{ //���׬��G�� �A
//�⤧�e���j���������C�X�A
//���᤬������줸��

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
{ //����פj��3�ɧQ�ΤU�C���j
for(k=0;k<b;k++)
{
//��swap�ϩҦ���������C��۹諸�Ĥ@��m�W
swap(&element[a],&element[a+k]);
fun(a+1,b-1,element);//����C�C���j�A�Ϥ�����simple case
swap(&element[a],&element[a+k]);//�M��A���^��
}
}
}


int main(void)
{
char element[11];//�ŧi�ܼ�element
int len;//�ŧi�ܼ�len
printf("�е��w�����A�ܦh10��>");
gets(element);//��ϥΪ̵����Ȧs�^element
len=strlen(element);//�d�welement������
fun(0,len,element);//�~����Ƨ@�ζ}�l
return(0);
}

