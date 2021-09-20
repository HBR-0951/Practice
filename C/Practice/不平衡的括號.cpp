#include<stdio.h>
#include<stdlib.h>



int k=0,wrong=0,h=0,isp[]={1,2,3};

void push(char *top,char value)
{
	*top=value;
	
	
}
void pop(char *top)
{
	char a=*top;
	*(top)=0;
	
		
		
} 



int main()
{
	char top[100],word;
	int per[100];
	while(scanf("%c",&word)!=EOF){
		if(word=='('||word=='['||word=='{'||k==0){
			if(word=='('){
				per[k]=isp[0];
				if(k==0){
					push(top+k,word);
					k++;
				}
				else if(per[k]<=per[k-1]){
					push(top+k,word);
					k++;
				}
				else{
					wrong++;
					break;
				}
			
				
			}
			else if(word=='['){
				per[k]=isp[1];
				if(k==0){
					push(top+k,word);
					k++;
				}
				else if(per[k]<=per[k-1]){
					push(top+k,word);
					k++;
				}
				else{
					wrong++;
					break;
				}
			}
			else if(word=='{'){
				per[k]=isp[2];
				if(k==0){
					push(top+k,word);
					k++;
				}
				else if(per[k]<=per[k-1]){
					push(top+k,word);
					k++;
				}
				else{
					wrong++;
					break;
				}
			}
			else{
				wrong++;
				break;
			}
			
		}
		else if(word==')'){
			k--;
			if(*(top+k)=='('){
				pop(top+k);
			}
			else{
				wrong++;
				break;
			}
			
		}
		else if(word==']'){
			k--;
			if(*(top+k)=='['){
				pop(top+k);
			}
			else{
				wrong++;
				break;
			}
			
		}
		else if(word=='}'){
			k--;
			if(*(top+k)=='{'){
				pop(top+k);
			}
			else{
				wrong++;
				break;
			}
			
		}
	}

	if(wrong!=0){
		printf("Illegal");
	}
	else{
		printf("Legal");
	}
}



