//adventurer card
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


#define TESTCARD "Adventurer"

int checkAdventurerCard(int drawntreasure, int p, struct gameState *post)
{
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int r;
    r = adventurerCard(drawntreasure, post, p);
    //verify the deck contains a
    if(drawntreasure == 0)
    {
       assert(post->handCount[p] > pre.handCount[p]);
    }
    else if(drawntreasure == 1)
    {
       assert(post->handCount[p] == pre.handCount[p]);
    }
    else if(drawntreasure > 2)
    {
       assert(post->handCount[p] < pre.handCount[p]);
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
void createSudoRandomDiscard(struct gameState *G, int discardCount, int p)
{
    int i;
    G->discard[p][0] = copper;
    G->discard[p][1] = silver;
    for(i=2; i<discardCount; i++)
    {
       int card = rand() % 27; //0-26
       G->discard[p][i] = card;
    }
    
}

int main()
{
    srand(time(NULL)); 

    int drawntreasure, p, r, deckCount, discardCount, handCount;
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};
   
    printf ("Testing Adventurer.\n");

    printf ("RANDOM TESTS.\n");
    SelectStream(2);
    PutSeed(3);

    //2 players
    for(p=0;p<2;p++)
    {
        //go through empty deck and having more than 1 
        for(deckCount = 0; deckCount < 5; deckCount ++)
        {
            for(handCount=1; handCount<5; handCount ++)
            {
                for(discardCount = 2; discardCount <5; discardCount ++)
                {
                    for(drawntreasure = 0; drawntreasure <3; drawntreasure++)
                    {
                        memset(&G, 23, sizeof(struct gameState));
                        r = initializeGame(2, k, 1, &G);
                        G.deckCount[p] = deckCount;
                        memset(G.deck[p], 0, sizeof(int) * deckCount);
                        createRandomDeck(&G, deckCount,p);
                        G.discardCount[p]=discardCount;
                        memset(G.discard[p], 0, sizeof(int) * discardCount);
                        createSudoRandomDiscard(&G, discardCount,p);
                        G.handCount[p] = handCount;
                        memset(G.hand[p], 0, sizeof(int) * handCount);
                        createRandomHand(&G, handCount, p);
                        checkAdventurerCard(drawntreasure, p, &G);
                    }
                
                }
            }
        }
    }
    return 0;
    //deckCount of currentPlayer
  //int for current player
    //only happen while drawn treasure is less than 2
    //handcount of currentplayer going down 2

}
