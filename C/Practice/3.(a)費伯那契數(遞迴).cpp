#include<stdio.h>

int fab(unsigned int n)
{

	if(n==0)
	{
	
		return 0;
	}
	if(n<=2)
	{
		
		return 1;
	}
	if(n>2)
	{
	
		return fab(n-1)+fab(n-2);
	}
}

int main()
{
	int n,s,N;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
	
		scanf("%d",&s);
		printf("%d\n",fab(s));
	}
	
		
	
	
	
}

