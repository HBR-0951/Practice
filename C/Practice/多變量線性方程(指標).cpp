#include<stdio.h>
#include<stdlib.h>



void determine(double *string,int m,int num){				//把 a陣列裡的值存入 *string裡 
	double *number=(double*)malloc(m*sizeof(double));
	int time=0;
	
	for(int i=1;i<=m;i++){
		*(number+(i-1))=*(string+i*(num+1)-1);
	
	}
	for(int i=0;i<m;i++){
		for(int k=0;k<num+1;k++){
			if(*(string+i*(num+1)+k)==0&&k==num){
				time++;
			}
			if(*(string+i*(num+1)+k)==0){
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
				if(*(number+i)!=0&&j==num-1&&(*(string+i*(num+1)+j))==0){
				printf("No solution");
				s=1;
				break;
				}
				else if((*(string+i*(num+1)+j))==0){
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

void Timer(double *string,double *timer,int m,int num){
							
	timer=(double*)malloc(m*num*sizeof(double));
	int test=0;
	
	for(int i=0;i<num;i++){
	
			for(int j=0;j<m;j++){
			
				if(i==j){
					*(timer+(j*num)+i);
					continue;
				}
				else{
					if(*(string+i*(num+1)+i)==0){
						*(timer+(j*num)+i)=0;
					}
					else{
					
					*(timer+(j*num)+i)=-(*(string+j*(num+1)+i))/(*(string+i*(num+1)+i));
					}
				
				}
			}			
			for(int h=0;h<m;h++){
				for(int k=0;k<num+1;k++){
					if(h==i){
					
						continue;
					}
					*(string+h*(num+1)+k)+=(*(timer+(h*num)+i))*(*(string+i*(num+1)+k));			
				}		
			}		
	}
}

int main(){
											//m=row,num=變數數量,num+1=column 
	int m=0,n=0,time=0,num;
	double *string;
	double *timer;
	scanf("%d",&num);
	double **str;
	
	str=(double**)malloc(100*sizeof(double*));		   
	while(1){		
		*(str+m)=(double*)malloc((num+1)*sizeof(double));						//把輸入的質存入 a陣列裡 ,以-999結束 
		while(n<num+1){	
			
			scanf("%lf",(*(str+m)+n));
			if(*(*(str+m)+n)==-999){				 
				break;
			}	
			
			n++;
		}
		if(*(*(str+m)+n)==-999){
			*(*(str+m)+n)=0;
			break;
		}
		n=0;
		m++;	
	}
	string=(double*)malloc(m*(num+1)*sizeof(double));
	for(int i=0;i<m;i++){								//把 a陣列裡的值存入 *string裡 
		for(int k=0;k<num+1;k++){
			*(string+i*(num+1)+k)=*(*(str+i)+k);			
		}	
	}	
	free(*str);
	Timer(string,timer,m,num);			//計算要相乘的數，並將其存入 *string裡 
	determine(string,m,num);
}

