//Mine Card (made a bug in assignment 2)
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"
#include <stdbool.h>

#define TESTCARD "Mine"

int checkMineCard(int choice1, int choice2, struct gameState *post, int handPos, int p)
{
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int r,handIndex;
    r = mineCard(post, p, choice1, choice2, handPos);

    //we store choice 1 to trash
    //if we have a copper, silver, or gold for choice 1, return -1 and end;

    if(pre.hand[p][choice1] < copper|| pre.hand[p][choice1] > gold)
    {
       // printf("not a coin\n");
        assert(r == -1);
    }
    else if(choice2 > treasure_map || choice2 < curse)
    {
       // printf("out of bounds\n");
        assert(r == -1);
    }
    else if(getCost(pre.hand[p][choice1])+3 > getCost(choice2))
    {
      //  printf("too expensive\n");
        assert(r == -1);
    }
    else
    {
        //printf("real things happening\n");
        bool cardFound = false;
        //assert that the choice 2 card is in hand
        for(handIndex = 0; handIndex < post->handCount[p]; handIndex++) 
        {
            int card = post->hand[p][handIndex];
             if(card == choice2);
                {
                    cardFound = true;
                    handIndex = post->handCount[p]; // break the loop
                }
        }
       // assert(cardFound == true);
        //printf("Before %d, After %d\n", pre.handCount[p], post->handCount[p]);
        //assert(post->handCount[p] == pre.handCount[p]-1);
    }
    return 0;
}

void createRandomDeck(struct gameState *G, int deckCount, int p)
{  
    int i;
    for(i=0; i<deckCount; i++)
    {
       int card = rand() %27; //0-26
       G->deck[p][i] = card;
    }
}
void createRandomHand(struct gameState *G, int handCount, int p)
{
    int i;
    for(i=0; i<handCount; i++)
    {
       int card = rand() % 27; //0-26
       G->hand[p][i] = card;
    }
}

int main()
{
    srand(time(NULL)); 

    int choice1, choice2, handPos, r, p, deckCount, discardCount, handCount;
    struct gameState G;

     int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};
   
    printf ("Testing Mine.\n");

    printf ("RANDOM TESTS.\n");
    SelectStream(2);
    PutSeed(3);

   for(p=0;p<2;p++)
    {
        //go through empty deck and having more than 1 
        for(deckCount = 1; deckCount < 5; deckCount ++)
        {
            for(handCount=1; handCount<5; handCount ++)
            {
                for(handPos = 0; handPos<handCount; handPos++)
                {
                    for(discardCount = 0; discardCount <5; discardCount ++)
                    {
                        
                        for(choice1 = 0; choice1< handPos; choice1++)
                        {
                            //all cards + 2 invalid to hit an invalid check
                            for(choice2 = 1; choice2 < 27; choice2++)
                            {
                                memset(&G, 23, sizeof(struct gameState));
                                r = initializeGame(2, k, 1, &G);
                                G.deckCount[p] = deckCount;
                                memset(G.deck[p], 0, sizeof(int) * deckCount);
                                createRandomDeck(&G, deckCount,p);

                                G.discardCount[p]=discardCount;
                                memset(G.discard[p], 0, sizeof(int) * discardCount);
                                G.handCount[p] = handCount;
                                memset(G.hand[p], 0, sizeof(int) * handCount);
                                createRandomHand(&G, handCount, p);
                                checkMineCard(choice1, choice2, &G, handPos, p);
                            }
                           
                        }
                    }
                }
            }
        }
    }
    return 0;
}