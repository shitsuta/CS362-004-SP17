

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"
#define NUMTEST 10000

void originalAssert(char *errorMessage, int condition, int *bugs){

	if(condition == 0){
		// printf("%s\n", errorMessage);
		*bugs = *bugs + 1 ;
	}
}

int main() {
	int i, n, r, p,j,t, l,m , deckCount, discardCount, handCount;

	int k[10] = {adventurer, feast, village, gardens, mine, remodel,
			baron, great_hall, smithy, council_room};
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int thisPlayer = 0;
	int numPlayers = 0;

	int rando; 

	struct gameState *testG;
	struct gameState *originalG;


	int originalNumberOfTreasure = 0;
	int afterNumberOfTreasure = 0;

	int bugs = 0;

	

	//Print Testing Statement
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	printf("----------------- RANDOM TESTS ----------------\n");
	printf("TEST: choice1=0 choice2=0 choice3=0\n");
	SelectStream(2);
	// printf("after SelectStream()\n");
	PutSeed(3);
	srand(time(NULL));   

	for (i = 0; i < NUMTEST; ++i)
	{

		rando = rand();
		
		//determine number of players
		numPlayers = rand() % 5;

		originalG = malloc(sizeof(struct gameState));
		testG = malloc(sizeof(struct gameState));

		initializeGame(numPlayers, k, rando, originalG);

		originalG->deckCount[thisPlayer] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		originalG->discardCount[thisPlayer] = rand() % MAX_DECK;
		originalG->handCount[thisPlayer] = rand() % (MAX_HAND - 10);
		originalG->hand[thisPlayer][0] = village;
		originalG->numActions = rand() % 9;

		//generate case where deckcount = 0 
		if(rando % 5 == 0)
			originalG->deckCount[thisPlayer] = 0;

		memcpy(testG, originalG, sizeof(struct gameState));

		r = cardEffect(smithy, 0, 0, 0, testG, 0, 0);

		//Check State Change
		originalAssert("Error on handCount", originalG->handCount[thisPlayer] + 3 - 1 == testG->handCount[thisPlayer], &bugs);
		originalAssert("Error on numActions", originalG->numActions - 1  == testG->numActions, &bugs);
		originalAssert("Error on playedCardCount",originalG->playedCardCount + 1 == testG->playedCardCount, &bugs);

 		free(originalG);
 		free(testG);

	}

	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	else
		printf("Found %d bugs\n", bugs);
	return 0;
}