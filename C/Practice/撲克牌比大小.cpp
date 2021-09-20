#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4 
#define FACES 13
#define CARDS 10
int array[10]={0};

void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[]);
int main (void)
{
	unsigned int deck[4][13]={0};
	srand(time(NULL));
	shuffle(deck);
	const char *suit[4]=
		{"Hearts","Diamonds","Clubs","Spades"};
	const char *face[13]=
		{"Ace","Deuce","Three","Four",
		"Five","Six","Seven","Eight",
		"Nine","Ten","Jack","Queen","King"};
	deal(deck,face,suit);
	
}
void shuffle(unsigned int wDeck[][FACES])
{
	for(size_t card=1;card<=CARDS;++card){
		size_t row;
		size_t column;
		do{
			row=rand()%SUITS;
			column=rand()%FACES;
		}while(wDeck[row][column]!=0);
		wDeck[row][column]=card;
		array[card-1]=wDeck[row][column];
	}
}
void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[])
{
	int checksuit[4]={0};
	int checkface[13]={0};
	int count=0;
	int i,Pair=0,TwoPair=0,ThreeKind=0,FourKind=0,Flush=0,Straight=0,first,last;
	int player1,player2;
	for(size_t card=1;card<=5;++card){
		for(size_t row=0;row<SUITS;++row){
			for(size_t column=0;column<FACES;++column){
				if(wDeck[row][column]==card){
					printf("%5s of %-8s\n",wFace[column],wSuit[row]);
					++checksuit[row];//行 
					++checkface[column];//列 
				}
			}
		}
	}
	for(i=0;i<4;++i){
		if(checksuit[i]==5){
		Flush=1; 
	}
	for(i=0;i<13;i++)
	{
		if(checkface[i]!=0)
		{
			last=i;
			if(checkface[i]==4){
				FourKind=1;
			}
			if(checkface[i]==3){
				ThreeKind=1;
			}
			if(checkface[i]==2){
				Pair++;
			}
			if(Pair==2){
				TwoPair=1;
			}
			if(checkface[i]==1){
				count++;
			}
		}
	}
	if(count==5)
	{
		first=(last-count+1);
		for(i=first;i<=last;i++){
			if(checkface[i]==1){
				count--;
			}
			if(count==0){
				Straight=1;
			}
		}
	}
	if(Straight==1&&Flush==1){
		printf("同花順");
		player1=1;
	}
	else if(Flush==1){
		printf("同花");
		player1=2;
	}
	else if(Straight==1){
		printf("順子");
		player1=3;
	}
	else if(FourKind==1){
		printf("鐵支");
		player1=4;
	}
	else if(ThreeKind==1&&Pair==1){
		printf("三條+對子");
		player1=5;
	}
	else if(ThreeKind==1){
		printf("三條");
		player1=6;
	}
	else if(TwoPair==1){
		printf("雙對子");
		player1=7;
	}
	else if(Pair==1){
		printf("對子");
		player1=8;
	}
	else{
		printf("沒牌型");
		player1=9;
	}
}

for(size_t card=6;card<=10;++card){
		for(size_t row=0;row<SUITS;++row){
			for(size_t column=0;column<FACES;++column){
				if(wDeck[row][column]==card){
					printf("%5s of %-8s\n",wFace[column],wSuit[row]);
					++checksuit[row];//行 
					++checkface[column];//列 
				}
			}
		}
	}
	for(i=0;i<4;++i){
		if(checksuit[i]==5){
		Flush=1; 
	}
	for(i=0;i<13;i++)
	{
		if(checkface[i]!=0)
		{
			last=i;
			if(checkface[i]==4){
				FourKind=1;
			}
			if(checkface[i]==3){
				ThreeKind=1;
			}
			if(checkface[i]==2){
				Pair++;
			}
			if(Pair==2){
				TwoPair=1;
			}
			if(checkface[i]==1){
				count++;
			}
		}
	}
	if(count==5)
	{
		first=(last-count+1);
		for(i=first;i<=last;i++){
			if(checkface[i]==1){
				count--;
			}
			if(count==0){
				Straight=1;
			}
		}
	}
	if(Straight==1&&Flush==1){
		printf("同花順");
		player2=1;
	}
	else if(Flush==1){
		printf("同花");
		player2=2;
	}
	else if(Straight==1){
		printf("順子");
		player2=3;
	}
	else if(FourKind==1){
		printf("鐵支");
		player2=4;
	}
	else if(ThreeKind==1&&Pair==1){
		printf("三條+對子");
		player2=5;
	}
	else if(ThreeKind==1){
		printf("三條");
		player2=6;
	}
	else if(TwoPair==1){
		printf("雙對子");
		player2=7;
	}
	else if(Pair==1){
		printf("對子");
		player2=8;
	}
	else{
		printf("沒牌型");
		player2=9;
	}
}
if(player1==player2&&player1!=1)
{
	
	
}







}


