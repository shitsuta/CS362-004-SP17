/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTFUNCTION "supplyCount(int card, struct gameState *state)"

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

    int originalProvince = -1;

    int i = 0;

    int bugs = 0;

    printf("----------------- Testing Card: %s ----------------\n", TESTFUNCTION);


	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	//assign supply for each cards at random
	G.supplyCount[province] = 5;
	G.supplyCount[council_room] = 2;
	G.supplyCount[village] = 7;
	G.supplyCount[adventurer] = 12;	

	originalAssert("supplyCount() doesn't match.\n", supplyCount(province, &G) == 5, &bugs);
	originalAssert("supplyCount() doesn't match.\n", supplyCount(council_room, &G) == 2, &bugs);
	originalAssert("supplyCount() doesn't match.\n", supplyCount(village, &G) == 7, &bugs);
	originalAssert("supplyCount() doesn't match.\n", supplyCount(adventurer, &G) == 12, &bugs);


	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);
	else
		printf("Found %d bugs\n", bugs);
	
	return 0;
}