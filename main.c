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


//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	if (cardnum%13==0)
	else if (cardnum%13==10)
	else if (cardnum%13==11)
	else if (cardnum%13==12)
	else 
	
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
		if(cardnum/13==0)
	{
		printf("Spade ");
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
		printf("Heart ");
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
	else if(cardnum/13==2)
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
			printf("%d ",(cardnum%13));
	}
	else if(cardnum/13==3)
	{
		printf("Dia");
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
	return cardnum;
}

//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray() {
	int i,j, temp; 
	
	srand(time(NULL));
	
	for(i=0;i<52;i++)
	{
		j=rand()%52;
		temp = CardTray[i];
		CardTray[i] = CardTray[j];
		CardTray[j] = temp;
	}

}

//get one card from the tray
int pullCard(void) {
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
	int n_user;
	
	printf("\n------------------ GAME start --------------------------\n");
	printf("input the number of players (MAX:5) : ");
	scanf("%d",&n_user);

	return n_user;
}


//betting
int betDollar(void) {
	int betting_money;
	
	printf("-------BETTING STEP-------\n");
	printf("  -> your betting (total:$) : ");
	
	scanf("%d", &betting_money);
	
	return betting_money;
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	
}

int getAction(void) {
	
	int x;
	
	printf("GO?(0) STOP?(other) ");
	scanf("%d", &x);
	if(x=0)
		continue;
	else
		break;
	
	return x;
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
}

int checkResult() {
	
}

int checkWinner() {
	
}



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int n_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	n_user = configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
	
		
		//each player's turn
		for () //each player
		{
			while () //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
				//GO? STOP? ::: getAction()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
