/*
 * cardtest2.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"
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
    int currentPlayer = 0;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    G.handCount[currentPlayer] = handCount;    //set number of cards in hand
    memcpy(G.hand[currentPlayer], coppers, sizeof(int) * handCount); // set so there are cards
    G.handCount[currentPlayer] ++;
    G.hand[currentPlayer][2] = adventurer;
    G.hand[currentPlayer][handPos] = handPos; //set players hand position
    G.playedCardCount = playedCardCount;
    G.discardCount[currentPlayer] = 1;
 


    //Discard cards from your deck until you find 2 treasure cards. Put two treasure cards in hand. Discard other revealed cards.
     
    //Create Deck so that 2 treasure cards on top
    //create deck with copper
    G.deckCount[currentPlayer] = 15;
    G.deck[currentPlayer][0] = copper;
    G.deck[currentPlayer][1] = copper;
    G.deck[currentPlayer][2] = steward;
    G.deck[currentPlayer][3] = remodel;

    cardEffect(7,0, 0, 0, &G, handPos, 0);
    #if(NOISY_TEST == 1)
    printf("expected deck count - 13. Actual %d\n",G.deckCount[currentPlayer]);
    printf("expected hand count - 3. Actual %d\n",G.handCount[currentPlayer]);
    printf("expected played card count - 5. Actual %d\n",G.playedCardCount);
    printf("expected discardCount card count - 2. Actual %d\n",G.discardCount[currentPlayer]);
    #endif
    //Deck down by 2
   // assert(G.deckCount[currentPlayer] == 13);
    //Handcount increase by 1
   //assert(G.handCount[currentPlayer] == 3);
    //Treasure cards in hand
   // assert(G.hand[currentPlayer][2] == copper);
   // assert(G.hand[currentPlayer][3] == copper);
    //Card count played + 1
   // assert(G.playedCardCount == 5);
    //discard up by 1
   // assert(G.discardCount[currentPlayer] == 2);




    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    G.handCount[currentPlayer] = handCount;    //set number of cards in hand
    memcpy(G.hand[currentPlayer], coppers, sizeof(int) * handCount); // set so there are cards
    G.handCount[currentPlayer] ++;
    G.hand[currentPlayer][2] = adventurer;
    G.hand[currentPlayer][handPos] = handPos; //set players hand position
    G.playedCardCount = playedCardCount;
    G.discardCount[currentPlayer] = 1;

    //create deck with silver
    //Create Deck so that 2 treasure cards not on top
    G.deckCount[currentPlayer] = 15;
    G.deck[currentPlayer][0] = remodel;
    G.deck[currentPlayer][1] = remodel;
    G.deck[currentPlayer][2] = silver;
    G.deck[currentPlayer][3] = silver;

    cardEffect(7,0, 0, 0, &G, handPos, 0);
    //Deck down by 4
   // assert(G.deckCount[currentPlayer] == 11);
    //Handcount increase by 1
  //  assert(G.handCount[currentPlayer] == 3);
    //Treasure cards in hand
  //  assert(G.hand[currentPlayer][2] == silver);
  //  assert(G.hand[currentPlayer][3] == silver);
    //Card count played + 1
 //   assert(G.playedCardCount == 5);
    //discard up by 3
 //   assert(G.discardCount[currentPlayer] == 4);



    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    G.handCount[currentPlayer] = handCount;    //set number of cards in hand
    memcpy(G.hand[currentPlayer], coppers, sizeof(int) * handCount); // set so there are cards
    G.handCount[currentPlayer] ++;
    G.hand[currentPlayer][2] = adventurer;
    G.hand[currentPlayer][handPos] = handPos; //set players hand position
    G.playedCardCount = playedCardCount;
    G.discardCount[currentPlayer] = 1;
  

     //create deck with gold
     //Create Deck so that 2 treasure cards are not next to one another.
    G.deckCount[currentPlayer] = 15;
    G.deck[currentPlayer][0] = remodel;
    G.deck[currentPlayer][1] = steward;
    G.deck[currentPlayer][2] = gold;
    G.deck[currentPlayer][3] = cutpurse;
    G.deck[currentPlayer][3] = gold;

    cardEffect(7,0, 0, 0, &G, handPos, 0);
    //Deck down by 5
 //   assert(G.deckCount[currentPlayer] == 9);
    //Handcount increase by 1
//    assert(G.handCount[currentPlayer] == 3);
    //Treasure cards in hand
 //   assert(G.hand[currentPlayer][2] == gold);
 //   assert(G.hand[currentPlayer][3] == gold);
    //Card count played + 1
 //   assert(G.playedCardCount == 5);
    //discard up by 4
 //   assert(G.discardCount[currentPlayer] == 5);

     

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    G.handCount[currentPlayer] = handCount;    //set number of cards in hand
    memcpy(G.hand[currentPlayer], coppers, sizeof(int) * handCount); // set so there are cards
    G.handCount[currentPlayer] ++;
    G.hand[currentPlayer][2] = adventurer;
    G.hand[currentPlayer][handPos] = handPos; //set players hand position
    G.playedCardCount = playedCardCount;
    G.discardCount[currentPlayer] = 10;
    G.discard[currentPlayer][0] =gold;
    G.discard[currentPlayer][1] =gold;
    G.discard[currentPlayer][2] =gold;
    G.discard[currentPlayer][3] =gold;
    G.discard[currentPlayer][4] =gold;
    G.discard[currentPlayer][5] =gold;
    G.discard[currentPlayer][6] =gold;
    G.discard[currentPlayer][7] =gold;
    G.discard[currentPlayer][8] =gold;
    G.discard[currentPlayer][9] =gold;
   

    //Create empty deck
    G.deckCount[currentPlayer] = 0;
    cardEffect(7,0, 0, 0, &G, handPos, 0);
    //Deck down by 2 (from 10 as shuffle discard)
 //   assert(G.deckCount[currentPlayer] == 8);
    //Handcount increase by 1
 //   assert(G.handCount[currentPlayer] == 3);
    //Treasure cards in hand
  //  assert(G.hand[currentPlayer][2] == gold);
 //   assert(G.hand[currentPlayer][3] == gold);
    //Card count played + 1
  //  assert(G.playedCardCount == 5);


    //Test cases to add. if shuffle in middle. dont shuffle cards revealed. as cards do not go into discard until after finishing revealing
    //Test cases to add. if run out of cards after shuffling, and still only have 1 treasure, only get 1 treasure.
    printf("Test Completed\n");

}
	
