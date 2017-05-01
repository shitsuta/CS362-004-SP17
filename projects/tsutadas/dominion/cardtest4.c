/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

void originalAssert(char *errorMessage, int condition, int *bugs){

	if(condition == 0){
		printf("%s\n", errorMessage);
		*bugs = *bugs + 1 ;
	}
}

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int bugs = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;

	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};


	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("TEST: choice1=0 choice2=0 choice3=0\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[thisPlayer][0] = village;

	// for(i = 0; i < testG.handCount[0]; i++){
	// 	printf("at position i: %d\n",testG.hand[thisPlayer][i]);
	// }

	// switch(testG.hand[thisPlayer][0])
	// {
	// 	case smithy: printf("%s\n", "smithy");
	// }
	
	playCard(0, choice1, choice2, choice3, &testG);


	// printf("testG handcound is %d\n", testG.handCount[thisPlayer]);
	// printf("G handcound is %d\n", G.handCount[thisPlayer]);


	//Check State Change
	originalAssert("Error on handCount", G.handCount[thisPlayer] == testG.handCount[thisPlayer], &bugs);
	originalAssert("Error on numActions",G.numActions - 1 + 2 == testG.numActions, &bugs);
	originalAssert("Error on playedCardCount",G.playedCardCount + 1 == testG.playedCardCount, &bugs);

	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	else
		printf("Found %d bugs\n", bugs);


	return 0;
}

