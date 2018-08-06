#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define UNITTEST "numHandCards"
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{
    int k[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall};
    int seed = 1000;
    int numPlayer = 2;
    int coppers[MAX_HAND];
    struct gameState G;
    int player1 = 0;
    int player2 = 1;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    G.handCount[player1] = 3; //player 1 has 3 cards
    memcpy(G.hand[player1], coppers, sizeof(int) * 3);

    int p1numHandCards = numHandCards(&G);

    #if(NOISY_TEST == 1)
    printf("Expected card count: 3, Actual: %d\n",p1numHandCards);
    #endif

    assert(p1numHandCards == 3);

    discardCard(2,player1,&G,0);

    p1numHandCards = numHandCards(&G);

    #if(NOISY_TEST == 1)
    printf("Expected card count: 2, Actual: %d\n",p1numHandCards);
    #endif

    assert(p1numHandCards == 2);

    endTurn(&G);


    G.handCount[player2] = 4; //player 2 has 4 cards
    memcpy(G.hand[player2], coppers, sizeof(int) * 4);

    int p2numHandCards = numHandCards(&G);
   
    #if(NOISY_TEST == 1)
    printf("Expected card count: 4, Actual: %d\n",p2numHandCards);
    #endif

    assert(p2numHandCards == 4);

    gainCard(0,&G,2,player2);

    p2numHandCards = numHandCards(&G);

    #if(NOISY_TEST == 1)
    printf("Expected card count: 5, Actual: %d\n",p2numHandCards);
    #endif

    assert(p2numHandCards == 5);


    printf("Test Completed\n");


}