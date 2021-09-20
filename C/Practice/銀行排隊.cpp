#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int k=0,desk;

struct banklist{			//�ƶ����H���W�� 
	char Name[20];
	int ArriveTime;
	int DealTime;
	int Desknumber;
	int Finishtime;
	int order;
	struct banklist *nextptr;
}; 

typedef struct banklist *Queueptr;		// �ŧi Queueptr�� struct banklist�����Ы��A 

Queueptr head=NULL;			//head,tail����C���Y��� 
Queueptr tail=NULL;

int min(int full[]){		//�D�X�̤֤H�ƶ������@�� 
    int min=desk-1;  
    for(int i=desk-1;i>0;i--){
        if(full[i-1]<=full[min]&&i-1>=0){
            min=i-1;           
        }
    }   	
    return min;
}

void enqueue(char *name,int arrivetime,int dealtime,int desknumber){		//��H���ө�F�ɶ��s�i enqueue 
	Queueptr newptr=(struct banklist*)malloc(sizeof(struct banklist));
	
	if(newptr!=NULL){
		strncpy(newptr->Name,name,10);	
		newptr->ArriveTime=arrivetime;
		newptr->DealTime=dealtime;	
		newptr->Desknumber=-1;
		newptr->nextptr=NULL;
		if(head==NULL){
			head=newptr;
            tail=newptr;	
		}
		else{
			(tail)->nextptr=newptr;
            tail=newptr;      
		}
	}
}

void Enqueue(Queueptr *head,Queueptr *tail,char *name,int desknumber,int finishtime){	//��n��X���H��i Enqueue 
	Queueptr newptr=(struct banklist*)malloc(sizeof(struct banklist));
	
	if(newptr!=NULL){
		strncpy(newptr->Name,name,20);	
		newptr->Desknumber=desknumber;
		newptr->Finishtime=finishtime;	
		newptr->nextptr=NULL;
		if(*head==NULL){
			*head=newptr;
            *tail=newptr;	
		}
		else{
			(*tail)->nextptr=newptr;
            *tail=newptr;      
		}
	}
}

int main(){	
	char name[20];
	int arrivetime,dealtime,count=0,Time=0,list=0;	//Time==�ɶ�(clock) 
	scanf("%d",&desk);
	int Desk[desk];	
	while(scanf("%s",name)!=EOF){		//��J �m�W�B��F�ɶ��B�B�z�ɶ� �A�B�d�x�٨S���t(Desknumber==-1) 
		scanf("%d",&arrivetime);
		scanf("%d",&dealtime);	
		enqueue(name,arrivetime,dealtime,-1);
		k++;							// k==��J���H��        
	}	
	int full[desk];
	for(int i=0;i<desk;i++){		// full���C�@�Ʀ��h�֤H�A�q0�}�l 
		full[i]=0;
	}	
	
	while(count<k){
		Queueptr Head=NULL;		// count �p���X���H�� 
		Queueptr Tail=NULL;	
		int t=0;				//�p��@��Time�̦��h�֤H�B�z�� 
		Queueptr newhead=head;
		while(newhead!=NULL){
			if(newhead->ArriveTime!=0){		//��H�٨S��F���ɫJ (ArriveTime!=0���ɭ�) 
				newhead->ArriveTime-=1;              				
			}
			else{
				if(newhead->DealTime>0&&newhead->Desknumber==-1&&list<k){	//��H��F��A���t�d�x�ö}�l�B�z  (DealTime>0,Desknumber==-1)
						for(int i=0;i<desk;i++){							
							if(full[i]==0){				//���٨S�H�ƶ����ɭԡA���t�d�x�����L (i) 
								newhead->DealTime--;
								newhead->Desknumber=i;
								newhead->order=full[i]+1;								
								full[i]++;				//�}�l�ƶ� (full[i]++) 
								list++;                               
								break;
							}
							else if(full[i]!=0&&i==desk-1){		//��C���d�x�����H�ƶ����ɭ� 
								int n=min(full);				//��X�����d�x�ƶ����H�̤� (n) �ä��t�d�x���L 							
								newhead->Desknumber=n;
								newhead->order=full[n]+1;								
                                full[n]++;					//�~��ƶ�(full[n]++) 
								list++;                               
							}
						}
				}
				else if(newhead->DealTime>0&&newhead->Desknumber!=-1){		//��w�g�Q���t�F�d�x�B�ٻݭn�B�z�ɶ���(DealTime>0,Desknumber!=-1) 
					if(newhead->order==1){
						newhead->DealTime--;		                        
					}					
				}
				else if(newhead->DealTime==0){		//��B�z���� (DealTime==0) 
					int i=newhead->Desknumber;
					Queueptr temp=head;
					while(temp!=NULL){				//�B�z�����d�i�����@�ƶ���V�e�@�B 
						if(temp->Desknumber==i){
							temp->order--;                          
						}
						temp=temp->nextptr;
					}
					newhead->DealTime--;			// �� DealTime==-1�A�ϥL���|�A�]�i�o�ӱ���� 
					full[i]--;						//����H��-1(full[i]--) 
					newhead->Finishtime=Time;
                    
					Enqueue(&Head,&Tail,newhead->Name,newhead->Desknumber,newhead->Finishtime); // ��n��X�����e�s�i�t�@�� Enqueue�� 
					count++;		//��X�@�� (count++) 
					t++;			//�p��o��Time���h�֭ӤH�B�z�� 
				}				
			}
			newhead=newhead->nextptr;
		}										
		for(int j=0;j<desk;j++){		//�q�d�x��0�}�l�M�䦳�S���H���� 
			if(t==0){			//��o��Time�S���H�B�z�����ɭ�(t==0) 
				break;
			}
			Queueptr Newhead=Head;
			while(Newhead!=NULL){				//���H�B�z��(t!=0) 
				if(Newhead->Desknumber!=j){		//��B�z�����d�x���Oj���ɭԡA�A��U�@�ӤH (Desknumber!=j) 
					Newhead=Newhead->nextptr;										
				}
				else{ 							//�����ܴN�L�X�ôM��U�@���d�x 
					printf("%s",Newhead->Name);
					printf(" %d",Newhead->Finishtime);
                    printf(" %d\n",Newhead->Desknumber);                  
					Newhead=Newhead->nextptr;				
					break;
				}
			}								
		}           
		Time++;		 
	}		
}


