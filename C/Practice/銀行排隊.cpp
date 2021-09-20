#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int k=0,desk;

struct banklist{			//排隊的人的名單 
	char Name[20];
	int ArriveTime;
	int DealTime;
	int Desknumber;
	int Finishtime;
	int order;
	struct banklist *nextptr;
}; 

typedef struct banklist *Queueptr;		// 宣告 Queueptr為 struct banklist的指標型態 

Queueptr head=NULL;			//head,tail為佇列的頭跟尾 
Queueptr tail=NULL;

int min(int full[]){		//求出最少人排隊的那一排 
    int min=desk-1;  
    for(int i=desk-1;i>0;i--){
        if(full[i-1]<=full[min]&&i-1>=0){
            min=i-1;           
        }
    }   	
    return min;
}

void enqueue(char *name,int arrivetime,int dealtime,int desknumber){		//把人按照抵達時間存進 enqueue 
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

void Enqueue(Queueptr *head,Queueptr *tail,char *name,int desknumber,int finishtime){	//把要輸出的人放進 Enqueue 
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
	int arrivetime,dealtime,count=0,Time=0,list=0;	//Time==時間(clock) 
	scanf("%d",&desk);
	int Desk[desk];	
	while(scanf("%s",name)!=EOF){		//輸入 姓名、抵達時間、處理時間 ，且櫃台還沒分配(Desknumber==-1) 
		scanf("%d",&arrivetime);
		scanf("%d",&dealtime);	
		enqueue(name,arrivetime,dealtime,-1);
		k++;							// k==輸入的人數        
	}	
	int full[desk];
	for(int i=0;i<desk;i++){		// full為每一排有多少人，從0開始 
		full[i]=0;
	}	
	
	while(count<k){
		Queueptr Head=NULL;		// count 計算輸出的人數 
		Queueptr Tail=NULL;	
		int t=0;				//計算一個Time裡有多少人處理完 
		Queueptr newhead=head;
		while(newhead!=NULL){
			if(newhead->ArriveTime!=0){		//當人還沒抵達的時侯 (ArriveTime!=0的時候) 
				newhead->ArriveTime-=1;              				
			}
			else{
				if(newhead->DealTime>0&&newhead->Desknumber==-1&&list<k){	//當人抵達後，分配櫃台並開始處理  (DealTime>0,Desknumber==-1)
						for(int i=0;i<desk;i++){							
							if(full[i]==0){				//當還沒人排隊的時候，分配櫃台號給他 (i) 
								newhead->DealTime--;
								newhead->Desknumber=i;
								newhead->order=full[i]+1;								
								full[i]++;				//開始排隊 (full[i]++) 
								list++;                               
								break;
							}
							else if(full[i]!=0&&i==desk-1){		//當每個櫃台都有人排隊的時候 
								int n=min(full);				//找出哪個櫃台排隊的人最少 (n) 並分配櫃台給他 							
								newhead->Desknumber=n;
								newhead->order=full[n]+1;								
                                full[n]++;					//繼續排隊(full[n]++) 
								list++;                               
							}
						}
				}
				else if(newhead->DealTime>0&&newhead->Desknumber!=-1){		//當已經被分配了櫃台且還需要處理時間時(DealTime>0,Desknumber!=-1) 
					if(newhead->order==1){
						newhead->DealTime--;		                        
					}					
				}
				else if(newhead->DealTime==0){		//當處理完後 (DealTime==0) 
					int i=newhead->Desknumber;
					Queueptr temp=head;
					while(temp!=NULL){				//處理完的櫃檯的那一排隊伍向前一步 
						if(temp->Desknumber==i){
							temp->order--;                          
						}
						temp=temp->nextptr;
					}
					newhead->DealTime--;			// 讓 DealTime==-1，使他不會再跑進這個條件裡 
					full[i]--;						//隊伍人數-1(full[i]--) 
					newhead->Finishtime=Time;
                    
					Enqueue(&Head,&Tail,newhead->Name,newhead->Desknumber,newhead->Finishtime); // 把要輸出的內容存進另一個 Enqueue裡 
					count++;		//輸出一個 (count++) 
					t++;			//計算這個Time有多少個人處理完 
				}				
			}
			newhead=newhead->nextptr;
		}										
		for(int j=0;j<desk;j++){		//從櫃台號0開始尋找有沒有人完成 
			if(t==0){			//當這個Time沒有人處理完的時候(t==0) 
				break;
			}
			Queueptr Newhead=Head;
			while(Newhead!=NULL){				//當有人處理完(t!=0) 
				if(Newhead->Desknumber!=j){		//當處理完的櫃台不是j的時候，再找下一個人 (Desknumber!=j) 
					Newhead=Newhead->nextptr;										
				}
				else{ 							//有的話就印出並尋找下一個櫃台 
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


