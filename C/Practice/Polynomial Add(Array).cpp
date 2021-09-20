#include<stdio.h>


int input(int max, int a[],unsigned int b[]){		//輸入進陣列 
	
	int i=0,j=0,k=0;
	char x;
	int c[1000];
	
	while(x!='#'){	

		
		scanf("%d%c",&c[j],&x);
		
			if(j%2!=0){
				if(c[j]>max){
					i=i-1;
					j=j-1;
					continue;
				}
				b[k]=c[j];
		
				k++;
			}
			else{
			
				a[i]=c[j];
			
				i++;
			}
		
		j++;
			
	}
		
	
		
	return k;

}

void check(int k,int a[],unsigned int b[]){		//檢查有無重複並合併 
	int c=0;
	int count=0; 
	for(int i=0;i<k;i++){
		
		for(int j=i+1;j<k;j++){
			if(b[i]==b[j]){
				a[i]+=a[j];
				a[j]=0;
				b[j]=0;
				c++;
			}
		}
	}
}
void switch1(unsigned int *a,unsigned int *b){		//交換 

	unsigned int x;
	x=*a;
	*a=*b;
	*b=x;	
}
void switch2(int *a,int *b){
	int x;
	x=*a;
	*a=*b;
	*b=x;	
}
	
	


int main(){
	
	int max1,max2,k,h,a[1000],c[1000],e[1000],l,time=0,count1,count2,len;
	scanf("%d",&max1);
	
	unsigned int b[max1+1];	
	k=input(max1,a,b);		//輸入陣列 
	scanf("%d",&max2);
	
	unsigned int d[max2+1];			//輸入陣列 
	h=input(max2,c,d);
	check(k,a,b);
	check(h,c,d);
	
	
	unsigned int f[k+h];	
	
	for(int i=0;i<k+h;i++){			//把陣列a,b合併成陣列c 
		if(i<k){
			e[i]=a[i];
			f[i]=b[i];
		}
		else{
			e[i]=c[i-k];
			f[i]=d[i-k];
		}
	}
	
	check(k+h,e,f);				//檢查有無重複 
	
	
	for(int i=0;i<k+h;i++){				//算出陣列中0 0的次數 
		if(e[i]==0&&f[i]==0){
			time++;
			
		}
	}
	l=k+h;
	len=k+h-time;
	
	int coe[l];
	unsigned int dex[l]={0};
	int p=0;
	
	int i=0;
	while(p<l){					//把c陣列去掉0 0後存入陣列d 
		
		
		if(e[i]==0&&f[i]==0){
			i++;
			continue;
			
		}
		
		else{
			
			coe[p]=e[i];
			dex[p]=f[i];
			
			i++;
		}
		p++;
		
	}
				//印出陣列d 
	
	int co=0;
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
											//按照指數大小排序 
				
			
			co++;
			if(dex[i]<dex[j+1]&&(j+1!=len)){				
				switch2(&coe[i],&coe[j+1]);				
				switch1(&dex[i],&dex[j+1]);												
			}
		}
	}
	
	
	
	
	for(int t=0;t<len;t++){
		if(coe[t]==0){
			continue;
		}
		if(t==len-1){
			printf("%d*x^%u",coe[t],dex[t]);
		}
		else{
			printf("%d*x^%u + ",coe[t],dex[t]);
		}
	}
		
	
	
	
}
