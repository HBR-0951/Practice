#include<stdio.h>


int input(int max, int a[],unsigned int b[]){		//��J�i�}�C 
	
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

void check(int k,int a[],unsigned int b[]){		//�ˬd���L���ƨæX�� 
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
void switch1(unsigned int *a,unsigned int *b){		//�洫 

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
	k=input(max1,a,b);		//��J�}�C 
	scanf("%d",&max2);
	
	unsigned int d[max2+1];			//��J�}�C 
	h=input(max2,c,d);
	check(k,a,b);
	check(h,c,d);
	
	
	unsigned int f[k+h];	
	
	for(int i=0;i<k+h;i++){			//��}�Ca,b�X�֦��}�Cc 
		if(i<k){
			e[i]=a[i];
			f[i]=b[i];
		}
		else{
			e[i]=c[i-k];
			f[i]=d[i-k];
		}
	}
	
	check(k+h,e,f);				//�ˬd���L���� 
	
	
	for(int i=0;i<k+h;i++){				//��X�}�C��0 0������ 
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
	while(p<l){					//��c�}�C�h��0 0��s�J�}�Cd 
		
		
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
				//�L�X�}�Cd 
	
	int co=0;
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
											//���ӫ��Ƥj�p�Ƨ� 
				
			
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
