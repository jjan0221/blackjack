#include <stdio.h>
#include <stdlib.h>
#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printCard(int cardnum) {
	if(cardnum/13==0)
	{
		printf("Spade ");	//0<=cardnum<13 ¡æspade A~K 
		if (cardnum%13==0)
			printf("A ");
		else if	(cardnum%13==10)
			printf("J ");
		else if (cardnum%13==11)
			printf("Q ");
		else if (cardnum%13==12)
			printf("K ");
		else 
			printf("%d ",(cardnum%13));
	}
	else if(cardnum/13==1)
	{
		printf("Heart ");	//13<=cardnum<26 ¡æHeart A~K 
		if (cardnum%13==0)
			printf("A ");
		else if	(cardnum%13==10)
			printf("J ");
		else if (cardnum%13==11)
			printf("Q ");
		else if (cardnum%13==12)
			printf("K ");
		else 
			printf("%d ",(cardnum%13+1));
	}
	else if(cardnum/13==2)	//26<=cardnum<39 ¡æClover A~K 
	{
		printf("Clover ");
		if (cardnum%13==0)
			printf("A ");
		else if	(cardnum%13==10)
			printf("J ");
		else if (cardnum%13==11)
			printf("Q ");
		else if (cardnum%13==12)
			printf("K ");
		else 
			printf("%d ",(cardnum%13+1));
	}
	else if(cardnum/13==3)	//39<=cardnum<52 ¡æDia A~K 
	{
		printf("Dia ");
		if (cardnum%13==0)
			printf("A ");
		else if	(cardnum%13==10)
			printf("J ");
		else if (cardnum%13==11)
			printf("Q ");
		else if (cardnum%13==12)
			printf("K ");
		else 
			printf("%d ",(cardnum%13+1));
	}
}

//Function to execute mixCardTray
void swap(int *px, int *py)
{
	int tmp;
	
	tmp = *px;
	*px = *py;
	*py = tmp;
}

//mix the card sets and put in the array
void mixCardTray(void) {
	int temp;
	int i, j, a;
	srand(time(NULL));
	
	a = rand()%52;
	
	printf("card mixed \n");
	
	for(i=0;i<52;i++)
	{
		CardTray[i]=i;
	}
	
	for(j=0;j<52;j++)
	{
		swap(CardTray[j], CardTray[i]);
	}
}


//get one card from the tray
int pullCard(void) {
	
	int i;
	i = cardIndex;
	cardIndex++;
	CardTray[i];
	
	return CardTray[i];
}

//offering initial 2 cards
void offerCards(void) {
	int i;
	int n_user;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
}

//print initial card status
void printCardInitialStatus(void) {
	int i;
	// print server's card
	printf("server : \t");
	printf("X \t");
	printCard(cardhold[n_user][1]);
	
	// print my card
	printf("you : \t");
	printCard(cardhold[0][0]);
	printf("\t");
	printCard(cardhold[0][1]);

	// print players card
	for(i=1;i<n_user;i++);
	{
		printf("player %d : ", i);
		printCard(cardhold[i][0]);
		printf("\t");
		printCard(cardhold[i][1]);
	}
}

void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
		
	printf("\t ::: ");
}

void main(void);
