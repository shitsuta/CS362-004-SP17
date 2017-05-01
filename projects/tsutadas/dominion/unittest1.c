/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTFUNCTION "getCost(int cardNumber)"

void originalAssert(char *errorMessage, int condition, int *bugs){

	if(condition == 0){
		printf("%s\n", errorMessage);
		*bugs = *bugs + 1 ;
	}
}


int main(){

	int k[10] = {adventurer, council_room, feast, gardens, mine,
               		remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int seed = 1000;
    int numPlayers = 2;

    int listOfCost[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};

    int testCost = -1;
    int i = 0;
    int bugs = 0;

    printf("----------------- Testing Card: %s ----------------\n", TESTFUNCTION);

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	for(i = 0; i < 27; i++){
		testCost = getCost(i);

		originalAssert("Cost doesn't much.\n", testCost == listOfCost[i], &bugs);
	}


	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);
	else
		printf("Found %d bugs\n", bugs);


	return 0;
}