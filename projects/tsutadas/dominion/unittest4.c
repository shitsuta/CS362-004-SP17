/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTFUNCTION "numHandCards(struct gameState *state)"

void originalAssert(char *errorMessage, int condition, int *bugs){

	if(condition == 0){
		printf("%s\n", errorMessage);
		*bugs = *bugs + 1;
	}
}


int main(){

	int k[10] = {adventurer, council_room, feast, gardens, mine,
               		remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int seed = 1000;
    int numPlayers = 2;

    int found = -1;

    int i = 0;

    int bugs = 0;

    printf("----------------- Testing Card: %s ----------------\n", TESTFUNCTION);


	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	//set the current player's hand to 4
	G.handCount[0] = 4;


	originalAssert("handCount has bugs.\n", numHandCards(&G) == 4, &bugs);

	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);
	else
		printf("Found %d bugs\n", bugs);
	
	return 0;
}