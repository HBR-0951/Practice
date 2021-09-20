#include<stdio.h>
#include<stdlib.h>







int main(){
	
	int m=0,n=0,time=0,max=0,l=0,row=0,num;
	
	
	scanf("%d",&num);
	double str[1000][num+1];
	for(int i=0;i<1000;i++){
		for(int j=0;j<num+1;j++){
			str[i][j]=0;
		}
	}
	while(1){
	
		
		while(n<num+1){
		
			scanf("%lf",&str[m][n]);	
			if(str[m][n]==-999){
				if(n!=0){
					m++;
				}
				break;
			}
		
			n++;
		}
		if(str[m-1][n]==-999){
			str[m-1][n]=0;
			break;
		}
		else if(str[m][n]==-999){
			break;
		}
		n=0;
		m++;
		
		
		
	
		
	}

	double string[m][num+1];
	for(int i=0;i<m;i++){
		for(int k=0;k<num+1;k++){
			string[i][k]=str[i][k];
		}
	}

	int line=num-1;
	
	double timer[m][num];					//ºâ¥Xnumber ¨Ã¦X¨Ö 
	int test=0;
	
	for(int i=0;i<num;i++){
	
			for(int j=0;j<m;j++){
			
				if(i==j){
					timer[j][i];
					continue;
				}
				else{
					if(string[i][i]==0){
						timer[j][i]=0;
					}
					else{
						timer[j][i]=-(string[j][i])/(string[i][i]);
					}
					
					
					
				}
			}
		
			for(int h=0;h<m;h++){
				for(int k=0;k<num+1;k++){
					if(h==i){
						
						continue;
					}
					
					string[h][k]+=timer[h][i]*(string[i][k]);
					
				}
				
			}
				
	}
	
	
	
					//check
	
double number[m];
	
	
	for(int i=0;i<m;i++){
		number[i]=string[i][num];
		
	}
	for(int i=0;i<m;i++){
		for(int k=0;k<num+1;k++){
			if(string[i][k]==0&&k==num){
				time++;
			}
			if(string[i][k]==0){
				continue;
			}
			else{
				break;
			}
		}
	}		

	int s=0;

	if(m-time>=num){
		for(int i=0;i<m;i++){
			for(int j=0;j<num;j++){
				if(number[i]!=0&&j==num-1&&string[i][j]==0){
				printf("No solution");
				s=1;
				break;
				}
				else if(string[i][j]==0){
					continue;
				}
				else{
					break;
				}
			}
			if(s==1){
				break;
			}
						
		}
		if(s==0){
			printf("The only solution");
				
			}
		
	
		
		
	}
	else{
		printf("Infinite solutions");
	}
	
	
	
	
	
	
	
}
