/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define TESTFUNCTION "isGameOver(struct gameState *state)"

void originalAssert(char *errorMessage, int condition, int * bugs){

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

	//store and make supply of province = 0 
	originalProvince = G.supplyCount[province];
	G.supplyCount[province] = 0;


	originalAssert("The game should be done because province is empty!\n", isGameOver(&G) == 1, &bugs);

	//restore supply of province
	G.supplyCount[province] = originalProvince;

	G.supplyCount[council_room] = 0;
	G.supplyCount[village] = 0;
	G.supplyCount[adventurer] = 0;	

	originalAssert("The game should be done!\n", isGameOver(&G) == 1, &bugs);


	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);
	else
		printf("Found %d bugs\n", bugs);

	
	return 0;
}