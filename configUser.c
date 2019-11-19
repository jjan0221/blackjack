#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//player settiing
int configUser(void) {
	int n_user;
	do
	{
		printf("input the number of players (MAX:5) : ");
		n_user = getIntegerInput();
	}
	while (n_user>5&&n_user<1); //	do 1<=n_user<=5

	return n_user;
}
