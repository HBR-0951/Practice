#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int h=0;									//h 計算堆疊內的數量 
int isp[]={12,12,13,13,0,19,14};			//isp 是堆疊內的優先順序 
int icp[]={12,12,13,13,20,19,15};			//icp 是進堆疊的優先順序
 
void push(char *top,char value)
{
	*top=value;
	
	
}
char pop(char *top)
{
	char a=*top;
	*(top)=0;
	return a;
		
		
 } 

int PrecedenceIcp(char word){		//傳回輸入的運算子的優先序(icp) 
	if(word=='+'){
		return icp[0];			
	}
	else if(word=='-'){
		return icp[1];
	}
	else if(word=='*'){
		return icp[2];
	}
	else if(word=='/'){
		return icp[3];
	}
	else if(word=='('){
		return icp[4];
	}
	else if(word==')'){
		return icp[5];
	}
	else if(word=='^'){
		return icp[6];
	}
	else{
		return 0;
	}
	
}
int PrecedenceIsp(char word){		//傳回輸入的運算子的優先序(isp) 
	if(word=='+'){
		return isp[0];			
	}
	else if(word=='-'){
		return isp[1];
	}
	else if(word=='*'){
		return isp[2];
	}
	else if(word=='/'){
		return isp[3];
	}
	else if(word=='('){
		return isp[4];
	}
	else if(word==')'){
		return isp[5];
	}
	else if(word=='^'){
		return isp[6];
	}
	else{
		return 0;
	}
	
}

int main()
{

	
	char top[100];		//top為要堆疊的陣列 
	char word;
	
	while(scanf("%c",&word)!=EOF){			//當輸入!=^z
		if(word!='+'&&word!='-'&&word!='*'&&word!='/'&&word!='^'&&word!='('&&word!=')'){	//當word不等於運算元的時候 
			printf("%c",word);
		}
		else{				//當word等於運算元的時候
			if(h==0){		// 當堆疊內沒有任何運算元的時候(h==0) 
				push(top+h,word);
				h++;
				
			}
			else{
				if(PrecedenceIcp(word)>PrecedenceIsp(*(top+(h-1)))){		//當要進堆疊的運算元的優先序(icp)大於堆疊內最上面的運算元的優先序(isp)時 
					if(word==')'){		//當word為右括號時 (word==')') 
						while(*(top+(h-1))!='('){		//當堆疊內最上面的運算元不是左括號的時候 (*(top+(h-1))!='(') 
							printf("%c",pop(top+(h-1)));
							h--;
							if(*(top+(h-1))=='('){
								pop(top+(h-1));
								if((h-1)>0){
									h--;
								}
								break;
							}
						}
					}
					else{
						push(top+h,word);
						h++;
					}
					
				}
				else{
					while(PrecedenceIsp(*(top+(h-1)))>=PrecedenceIcp(word)){
                        
						printf("%c",pop(top+(h-1)));		
						h--;		
                        if(h==0){
                            break;
                        }
					}
					push(top+h,word);
                    h++;
				}
			}
		}
		
	}
	for(int i=h-1;i>=0;i--){
		printf("%c",top[i]);
		
	}
	
}



 

