#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"

#define UNITTEST "whoseTurn"
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main()
{
    int seed = 1000;
    int numPlayer = 4;
    int k[7] = {treasure_map, council_room, gardens, remodel, village, baron, great_hall};
    struct gameState G;

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    int playerTurn = whoseTurn(&G);

    #if(NOISY_TEST ==1)
    printf("Expected player: %d, Actual Player: %d\n",0,playerTurn);
    #endif
    assert(0 == playerTurn);

    endTurn(&G);

    playerTurn = whoseTurn(&G);

    #if(NOISY_TEST ==1)
    printf("Expected player: %d, Actual Player: %d\n",1,playerTurn);
    #endif
    assert(1 == playerTurn);

    endTurn(&G);

    playerTurn = whoseTurn(&G);

    #if(NOISY_TEST ==1)
    printf("Expected player: %d, Actual Player: %d\n",2,playerTurn);
    #endif
    assert(2 == playerTurn);

    endTurn(&G);

    playerTurn = whoseTurn(&G);

    #if(NOISY_TEST ==1)
    printf("Expected player: %d, Actual Player: %d\n",3,playerTurn);
    #endif
    assert(3 == playerTurn);

    endTurn(&G);
    
    playerTurn = whoseTurn(&G);

    #if(NOISY_TEST ==1)
    printf("Expected player: %d, Actual Player: %d\n",0,playerTurn);
    #endif
    assert(0 == playerTurn);

    printf("Test Completed.\n");
}