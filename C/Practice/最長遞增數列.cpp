#include<stdio.h>


int main(){

	int a[100],i,len=1,max=0;
	char x;
	i=0;
	
	while(x!='#'){
		
			
		scanf("%d%c",&a[i],&x);
		
		
	
		i++;	
	}
	printf("end\n");
	for(int j=1;j<i;j++){	
		if(a[j]>a[j-1]){	
			len++;
			if(max<len){
				max=len;
			}
		}
		
		if(a[j]<a[j-1]){
			if(max<len){
				max=len;	
			}
			len=1;	
		}
	}
	printf("%d",max);	
	}
	

