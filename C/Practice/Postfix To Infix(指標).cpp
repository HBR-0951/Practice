#include<stdio.h>
#include<stdlib.h>





void push(double *top,double value)
{
	*top=value;
	
	
}
double pop(double *top)
{
	double a=*top;
	*(top)=0;
	return a;
		
		
 } 

int main()
{
	char word;
	double *top=(double*)malloc(100*sizeof(double)),a,b;
	int k=0;

	while(scanf("%c",&word) != EOF){
		
	
		
		if(word=='+'){
			k--;
			a=pop(top+k);
			k--;
			b=pop(top+k);
			
			push(top+k,a+b);
			k++;
		}
		else if(word=='-'){
			k--;
			a=pop(top+k);
			k--;
			b=pop(top+k);
		
			push(top+k,b-a);
			k++;
		}
		else if(word=='*'){
			k--;
			a=pop(top+k);
			k--;
			b=pop(top+k);
			
			push(top+k,a*b);
			k++;
		}
		else if(word=='/'){
			k--;
			a=pop(top+k);
			k--;
			b=pop(top+k);
			
			push(top+k,b/a);
			k++;
		}
		else {
			
			push(top+k,(((double)word)-48));
			k++;
		}
		
	}
	
	
	printf("%lf",*(top+k-1));
	return 0;	
		
}



