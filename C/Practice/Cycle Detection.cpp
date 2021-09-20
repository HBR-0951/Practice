#include<stdio.h>

#define SIZE 100
int s=0,stack[SIZE];

void push(int data){
    stack[s]=data;
    s++;
}
int pop(){
    int i=stack[s-1];
    s--;
    return i;
}
int determine(int i,int N,int str[][N]){
	int deter[N];
	for(int j=0;j<N;j++){
		deter[j]=0;
	}
	// for(int t=0;t<N;t++){
	// 	for(int j=0;j<N;j++){
	// 		printf("%d ",str[t][j]);
	// 	}
	// 	printf("\n");
	// }

	int k=i,p=0;
	while(p==0){
		int h=-1;
        
		while(h<N){
            int check=0;
            for(int g=0;g<N;g++){
                if(str[k][g]==1){
                    check=1;
                    break;
                }
            }
            if(check==0){
                p=2;
                break;
            }
            else{
                h++;
                if(h>=N){
                    p=3;
                    break;
                }
			    if(str[k][h]==1){
                    //printf("k:%d h:%d\n",k,h);
				    if(deter[h]==0){
                        push(h);
					    deter[h]=1;
					    k=h;
                        h=-1;
                    
				    }
				    else{
					    p=1;
                        break;
				    }
			    }
		    }
        }
			
	}
    //printf("p:%d\n",p);
    if(p==1){
        return 1;
    }
	else{
        return 0;
    }
}
	

int main(){
	int N,a,b,p=0;
	scanf("%d",&N);
	int str[N][N];
    // int* p[N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			str[i][j]=0;
		}
	}
	while(scanf("%d",&a)!=EOF&&scanf("%d",&b)!=EOF){
		str[a][b]=1;
	}
	// for(int i=0;i<N;i++){
	// p[i]=str[i];
	// }
//	for(int i=0;i<N;i++){
//		for(int j=0;j<N;j++){
//			printf("%d ",str[i][j]);
//		}
//		printf("\n");
//	}
	 for(int i=0;i<N&&p==0;i++){
		p=determine(i,N,str);
		
		
	 }
    if(p==1){
        printf("Cycle");
    }
    else{
        printf("No Cycle");
    }
} 
