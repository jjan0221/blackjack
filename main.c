#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

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
void getCardNum(int CardTray[cardnum]) {
	if (cardnum%13==0)
		CardTray[cardnum] = 1;
	else if (cardnum%13==10)
		CardTray[cardnum] = 10;
	else if (cardnum%13==11)
		CardTray[cardnum] = 10;
	else if (cardnum%13==12)
		CardTray[cardnum] = 10;
	else 
		CardTray[cardnum] = cardnum%13;
}

//print the card information (e.g. DiaA)
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

//card array controllers -------------------------------

//mix the card sets and put in the array
void mixCardTray(int Card[]) {
	int a, b, i, x; 
	
	srand(time(NULL));
	
	printf("card mixed \n");
	
	for(i=0;i<100;i++)
	{
		a = rand % 52;
		b = rand % 52;
		x = Card[a];
		Card[a] = Card[b];
	}
}

//get one card from the tray
int pullCard(void) {
	
	int i;
	i = cardIndex;
	++cardIndex;

	return i;
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
	int n_user;
	do
	{
		printf("input the number of players (MAX:5) : ");
		n_user = getIntegerInput();
	}
	while (n_user>5&&n_user<1);

	return n_user;
}


//betting
int betDollar(void) {
	int betting_money;
	
	printf("-------BETTING STEP-------\n");
	printf("  -> your betting (total:$%d) : ");
	
	betting_money = getIntegerInput();
	
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
	int i;
	// print server's card
	printf("server : \t");
	printf("X \t");
	printCard(cardhold[n_user][1])	
	
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
		printCard(cardhold[i][1])
	}
}

int getAction(void) {
	
	int x;
	
	printf("GO?(0) STOP?(other) ");
	scanf("%d", &x);
	if(x==0)
		//continue
	else
		//stop
	
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
inget calcStepResult() {
	
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
	
	printf("\n------------------ GAME start --------------------------\n");
	
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
		for (i=0;i<n_user;i++) //each player
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
