
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"
#define NUMTEST 100

void originalAssert(char *errorMessage, int condition, int *bugs){

	if(condition == 0){
		// printf("%s\n", errorMessage);
		*bugs = *bugs + 1 ;
	}
}

int checkDrawCard(int p, struct gameState *post) {
  int r;
    
  r = drawCard (p, post);

  assert (r == 0);
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
	// printf("after PutSeed()\n");


	// for(i = 0; i < NUMTEST; i++){
	// 	originalG = malloc(sizeof(struct gameState));
	// 	testG = malloc(sizeof(struct gameState));
	// 	for (n = 0; n < sizeof(struct gameState); n++) {
 //      		((char*)originalG)[n] = floor(Random() * 256);
 //    	}

 //    	p = 0;
 //    	originalG->deckCount[p] = floor(Random() * 10);
 //    	originalG->discardCount[p] = floor(Random() * 5);
 //    	originalG->handCount[p] = floor(Random() * 5);
 //    	originalG->phase = 0;
 //    	originalG->numActions = 1;
 //    	originalG->hand[p][0] = adventurer;
 //    	originalG->whoseTurn = p;

 //    	// printf("handCard is %d\n", handCard(0, originalG));
 //    	// printf("whoseTurn is %d\n", whoseTurn(originalG));
 //    	r = playCard(0, choice1, choice2, choice3, originalG);
 //    	printf("r is %d\n", r );
 //    	// printf("player is %d\n", originalG->whoseTurn);
	// 	for (l = 0; l <= originalG->handCount[p]; ++l)
	// 	{
	// 		if (originalG->hand[thisPlayer][l] == copper || 
	// 				originalG->hand[thisPlayer][l] == silver || 
	// 					originalG->hand[thisPlayer][l] == gold){

	// 			originalNumberOfTreasure++;
	// 		}

	// 		// printf("original catd is %d\n", originalG->hand[p][l]);
	// 	}

	//  	free(originalG);
	//  	free(testG);
	// }
	// return 0;
	
	for(i = 0; i < NUMTEST; i++){

		//initialize variables
		originalNumberOfTreasure = 0;
		afterNumberOfTreasure = 0;
		// bugs = 0;

		//determine number of players
		numPlayers = rand() % 5;

		originalG = malloc(sizeof(struct gameState));
		testG = malloc(sizeof(struct gameState));


		// printf("after numPlayers\n");
		//initialize game
		rando = rand();
		initializeGame(numPlayers, k, rando , originalG);
		// for (n = 0; n < sizeof(struct gameState); n++) {
  //     		((char*)originalG)[n] = floor(Random() * 256);
  //   	}
    	// initializeGame(numPlayers, k, i+1, originalG);
		// printf("after initialize()\n");
	    // originalG->deckCount[thisPlayer] = rand() % MAX_DECK;
	    // originalG->discardCount[thisPlayer] = rand() % MAX_DECK;
	    // originalG->handCount[thisPlayer] = rand() % MAX_HAND;

	    originalG->whoseTurn = thisPlayer;
	    // printf("whoseTurn is %d\n", originalG->whoseTurn);
	    



	 //    for (j = 0; j < originalG->handCount[thisPlayer]; ++j)
		// {
		// 	originalG->hand[thisPlayer][j] = rand() % treasure_map;
		// 	// printf("original catd is %d\n", originalG->hand[thisPlayer][i]);
		// }

		// for (t = 0; t < originalG->deckCount[thisPlayer]; ++t)
		// {
		// 	originalG->deck[thisPlayer][t] = rand() % treasure_map;
		// 	// printf("original catd is %d\n", originalG->hand[thisPlayer][i]);
		// }
	    
	    //put TestCard into testPlyayer's hand
	    originalG->hand[thisPlayer][0] = adventurer;


	    // copy the game state to a test case
		memcpy(testG, originalG, sizeof(struct gameState));

		// testG->whoseTurn = 0;
		// printf("turn is %d\n", testG->whoseTurn);
		// printf("card at position  is %d\n", testG->hand[thisPlayer][0]);
		playCard(0, choice1, choice2, choice3, testG);




		for (l = 0; l < originalG->handCount[thisPlayer]; ++l)
		{
			if (originalG->hand[thisPlayer][l] == copper || 
					originalG->hand[thisPlayer][l] == silver || 
						originalG->hand[thisPlayer][l] == gold){

				originalNumberOfTreasure++;
			}
			// printf("original catd is %d\n", originalG->hand[thisPlayer][l]);
		}

		for (m = 0; m < testG->handCount[thisPlayer]; ++m)
		{
			if (testG->hand[thisPlayer][m] == copper || 
					testG->hand[thisPlayer][m] == silver || 
						testG->hand[thisPlayer][m] == gold){

				afterNumberOfTreasure++;
			}
		// printf("test catd is %d\n", testG->hand[thisPlayer][m]);

		}	

		// printf("originalNumberOfTreasure is %d\n", originalNumberOfTreasure);
		// printf("afterNumberOfTreasure is %d\n", afterNumberOfTreasure);

		//Check State Change
		originalAssert("Error on numberOfTreasure", originalNumberOfTreasure + 2 == afterNumberOfTreasure, &bugs );
		originalAssert("Error on numActions", originalG->numActions - 1  == testG->numActions, &bugs );
		originalAssert("Error on playedCardCount", originalG->playedCardCount + 1 == testG->playedCardCount, &bugs );

 		free(originalG);
 		free(testG);
	
	}

	if(bugs == 0 )
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	else
		printf("Found %d bugs\n", bugs);
	return 0;

}