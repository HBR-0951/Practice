#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int h=0;									//h �p����|�����ƶq 
int isp[]={12,12,13,13,0,19,14};			//isp �O���|�����u������ 
int icp[]={12,12,13,13,20,19,15};			//icp �O�i���|���u������
 
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

int PrecedenceIcp(char word){		//�Ǧ^��J���B��l���u����(icp) 
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
int PrecedenceIsp(char word){		//�Ǧ^��J���B��l���u����(isp) 
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

	
	char top[100];		//top���n���|���}�C 
	char word;
	
	while(scanf("%c",&word)!=EOF){			//���J!=^z
		if(word!='+'&&word!='-'&&word!='*'&&word!='/'&&word!='^'&&word!='('&&word!=')'){	//��word������B�⤸���ɭ� 
			printf("%c",word);
		}
		else{				//��word����B�⤸���ɭ�
			if(h==0){		// ����|���S������B�⤸���ɭ�(h==0) 
				push(top+h,word);
				h++;
				
			}
			else{
				if(PrecedenceIcp(word)>PrecedenceIsp(*(top+(h-1)))){		//��n�i���|���B�⤸���u����(icp)�j����|���̤W�����B�⤸���u����(isp)�� 
					if(word==')'){		//��word���k�A���� (word==')') 
						while(*(top+(h-1))!='('){		//����|���̤W�����B�⤸���O���A�����ɭ� (*(top+(h-1))!='(') 
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



 

