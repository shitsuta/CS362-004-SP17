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

#define TESTCARD "adventurer"

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

	int originalNumberOfTreasure = 0;
	int afterNumberOfTreasure = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("TEST: choice1=0 choice2=0 choice3=0\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[thisPlayer][testG.handCount[thisPlayer]] = adventurer;
	testG.handCount[thisPlayer]++;

	// for(i = 0; i < testG.handCount[0]; i++){
	// 	printf("at position i: %d\n",testG.hand[thisPlayer][i]);
	// }

	// switch(testG.hand[thisPlayer][0])
	// {
	// 	case smithy: printf("%s\n", "smithy");
	// }
	
	playCard(testG.handCount[thisPlayer] -  1, choice1, choice2, choice3, &testG);


	for (int i = 0; i < G.handCount[thisPlayer]; ++i)
	{
		if (G.hand[thisPlayer][i] == copper || 
				G.hand[thisPlayer][i] == silver || 
					G.hand[thisPlayer][i] == gold){

			originalNumberOfTreasure++;
		}
		// printf("original catd is %d\n", G.hand[thisPlayer][i]);
	}

	for (int i = 0; i < testG.handCount[thisPlayer]; ++i)
	{
		if (testG.hand[thisPlayer][i] == copper || 
				testG.hand[thisPlayer][i] == silver || 
					testG.hand[thisPlayer][i] == gold){

			afterNumberOfTreasure++;
		}
		// printf("test catd is %d\n", testG.hand[thisPlayer][i]);

	}	

	// printf("G.handCount is %d\n", G.handCount[thisPlayer]);
	// printf("testG.handCount is %d\n", testG.handCount[thisPlayer]);

	// printf("original number of treasure is %d\n", originalNumberOfTreasure);
	// printf("afterNumberOfTreasure is %d\n", afterNumberOfTreasure);

	// printf("G.playedCardCount is %d\n", G.playedCardCount);
	// printf("testG.playedCardCount is %d\n", testG.playedCardCount);

	//Check State Change
	originalAssert("Error on numberOfTreasure", originalNumberOfTreasure + 2 == afterNumberOfTreasure, &bugs );
	originalAssert("Error on numActions", G.numActions - 1  == testG.numActions, &bugs );
	originalAssert("Error on playedCardCount",G.playedCardCount + 1 == testG.playedCardCount, &bugs );

 
	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	else
		printf("Found %d bugs\n", bugs);
	return 0;
}

