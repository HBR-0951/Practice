#include<stdio.h>
#include<string.h>

void swap(char *a, char *b){

	char c;
	c=*a;
	*a=*b;
	*b=c;
}

void fun(int a,int b,char list[]){
	int k;
	if(b==1){
		printf("%c\n",list[a]);
	}
	else if(b==2){ 

		for(k=0;k<a;k++){

			printf("%c",list[k]);
		}
		printf("%c%c\n",list[a],list[a+1]);
	for(k=0;k<a;k++)
	{
		printf("%c",list[k]);
	}printf("%c%c\n",list[a+1],list[a]);
	}
	else{ 
		for(k=0;k<b;k++)
	{

	swap(&list[a],&list[a+k]);
	fun(a+1,b-1,list);
	swap(&list[a],&list[a+k]);
	}
	}
	}

int main(){
	
	int len,N;
	char list[100];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s",list);
		len=strlen(list);
		fun(0,len,list);
	}
}

