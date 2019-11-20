#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "printCard.c"
#include "configUser.c"

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

//card processing functions ---------------

//calculate the actual card number in the blackjack game
void getCardNum(int cardnum) {
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
//playing game functions -----------------------------


//betting
int betDollar(void) {
	int i;
	
	srand((unsigned)time(NULL));
	
	printf("-------BETTING STEP-------\n");
	printf("  -> your betting (total:$%d) : ");
	scanf("%d", &dollar[0]);
	
	//Players bet money on less than five dollars. 
	for(i=1;i<n_user;i++)
	{
		dollar[i]=rand()%5;
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
	
	printf("\n------------------ GAME start --------------------------\n");
	
	//set the number of players
	n_user = configUser();


	//Game initialization --------
	//1. players' dollar
	betDollar();
	
	
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
