#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct str{
	char data;
	struct str *next;
}; 



void push(str *top,char value){
	
	str *newptr=(str*)malloc(sizeof(str));
	if(newptr!=NULL)
	{
		
		newptr->data=value;
	
		newptr->next=*top;
	
		*top=newptr;
	
	}
	
}

void pop(char *rec){
	*rec=0;
}


int main(){
	
	int n,t=0,h=0,k=0;
	scanf("%d",&n);
	int *s=(int*)malloc(n*n*sizeof(int));
	str *top=NULL;
	top=(str*)malloc(sizeof(str));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",(s+i*n+j));
		}
	}
	while(h<n||k<n){
		if(h==n-1&&k==n-1){
			break;
		}
		
		if(*(s+h*n+(k+1))==1){
			char value='E';
			push(rec+t,value);
			
			*(s+h*n+k)=-1;
			k++;
			t++;
			if(k==(n-1)&&h!=(n-1)){
				char value='S';
				push(rec+t,value);
			
				*(s+h*n+k)=-1;
				h++;
				t++;
			}
			continue;
		}
		else if(*(s+(h+1)*n+k)==1){
			char value='S';
			push(rec+t,value);
			
			*(s+h*n+k)=-1;
			h++;
			t++;
		
			if(h==(n-1)&&k!=(n-1)){
				char value='W';
				push(rec+t,value);
				
				*(s+h*n+k)=-1;
				k--;
				t++;
			
			}
			continue;
		}
		else if(*(s+h*n+(k-1))==1){
			char value='W';
			push(rec+t,value);
			
			*(s+h*n+k)=-1;
			k--;
			t++;
			if(k==0){
				char value='N';
				push(rec+t,value);
				
				*(s+h*n+k)=-1;
				h--;
				t++;
			
			}
			continue;
		}
		else if(*(s+(h-1)*n+k)==1){
			char value='N';
			push(rec+t,value);
				
			*(s+h*n+k)=-1;
			h--;
			t++;
			if(h==0){
				char value='E';
				push(rec+t,value);
				
				*(s+h*n+k)=-1;
				k++;
				t++;
			
			}
			continue;
		}
		else{
			*(s+h*n+k)=0;
			char c=*(rec+(t-1));
			
			
			pop(rec+(t-1));
			t--;
			if(c=='E'){
				k--;
			}
			else if(c=='S'){
				h--;
			}
			else if(c=='W'){
				k++;
			}
			else if(c=='N'){
				h++;
			}
		
			
			
		}
	}

	for(int i=0;i<t;i++){
		printf("%c",*(rec+i));
	}
	
	
	
	
	
	
}
