/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int handCount = 2;
    int handPos = 1; 
    int k[9] = {treasure_map, feast, mine, gardens, adventurer, remodel, village, smithy, great_hall};
    int coppers[MAX_HAND];
    struct gameState G;
    int playedCardCount = 4;
    int deckCount = 15;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

     G.handCount[0] = handCount;    //set number of cards in hand
     memcpy(G.hand[0], coppers, sizeof(int) * handCount); // set so there are cards
     G.hand[0][handPos] = handPos; //set players hand position
     G.playedCardCount = playedCardCount;
     G.deckCount[0] = deckCount;


     //deckcount decrement by 3
     //handcount increase by 3 - 1
     //played card count + 1

     cardEffect(13,0, 0, 0, &G, handPos, 0);

     #if(NOISY_TEST == 1)

     printf("Deckcount Expected: %d, Actual: %d\n",deckCount-3,G.deckCount[0]);
     printf("Handcount Expected: %d, Actual: %d\n",handCount + 3 - 1,G.handCount[0]);
     printf("PlayedCardCount Expected: %d, Actual: %d\n",playedCardCount+1,G.playedCardCount);

     #endif

     assert(G.deckCount[0] == deckCount-3);
     assert(handCount + 3 - 1 == G.handCount[0]);
     assert(playedCardCount+1 == G.playedCardCount);

     printf("Test Completed\n");

}