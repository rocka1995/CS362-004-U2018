 //Feast Card (made a bug in assignment 2)
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

#define TESTCARD "Feast"

int checkFeastCard(int choice1,int coins, struct gameState *post, int p)
{
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int r, handIndex;
    bool cardFound = false;
    int playerCoins = coins + 5;
    int cost = getCost(choice1);//must be able to buy
    int supply = supplyCount(choice1, post);//must have in supply

    if(cost <= playerCoins)//too expensive, player will be reprompted
    {
        if(supply > 0)//that card is in the supply, player can buy it.
        {
            //printf("choice %d\n",choice1);
            r = feastCard(choice1, post, p); // we would infinite loop if we didn't check first
            //printf("initial coins (+5 already) %d, cost %d, coins variable %d, ending coins %d\n",playerCoins,cost,coins, post->coins);
            //assert(post->coins == (playerCoins)-cost);//correct cost applied
            for(handIndex = 0; handIndex < post->handCount[p]; handIndex++) 
            {
                int card = post->hand[p][handIndex];
               // printf("card: %d\n",card);

                if(card == choice1);
                {
                    cardFound = true;
                    handIndex = post->handCount[p]; // break the loop
                }
            }
            assert(cardFound == true);
        }
    }
    //card gained (choice1 card
    //coins on player down by cost

   // printf("%d\n",r);
    //should always return 0 on feast card
  //  assert (r == 0);

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

void updateHandCoins(struct gameState *G, int handCount, int p, int coins)
{
    int i = handCount - coins;
    if(coins > 3)
    {
        
        G->hand[p][i+1] = silver;
        if(coins == 5)
        {
            G->hand[p][i+2] = gold;
        }
        else
        {
            G->hand[p][i+2] = silver;
        }
    }
    else
    {
        
        if(coins == 3)
        {
            G->hand[p][i+1] = gold;
        }
        else if(coins == 2)
        {
            G->hand[p][i+1] = silver;
        }
        else
        {
            G->hand[p][i+1] = copper;
        }
    }
}

int main()
{
    srand(time(NULL)); 

    int choice1, p, coins, deckCount, handCount;
    struct gameState G;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};
   
    printf ("Testing Feast.\n");

    printf ("RANDOM TESTS.\n");
    SelectStream(2);
    PutSeed(3);

    for(p=0;p<2;p++)
    {
        //go through empty deck and having more than 1 
        for(deckCount = 1; deckCount < 5; deckCount++)
        {
            //all cards
            for(choice1 = 0; choice1< 26; choice1++)
            {
                for(handCount=1; handCount<5; handCount++)
                {
                
                    for(coins = 0; coins < 5; coins++)
                    {
                        memset(&G, 23, sizeof(struct gameState));
                        initializeGame(2, k, 1, &G);
                        G.deckCount[p] = deckCount;
                        memset(G.deck[p], 0, sizeof(int) * deckCount);
                        createRandomDeck(&G, deckCount,p);
                        G.discardCount[p]=0;
                        memset(G.discard[p], 0, sizeof(int) * 0);
                        handCount = handCount + coins;
                        G.handCount[p] = handCount;
                        memset(G.hand[p], 0, sizeof(int) * handCount);
                        createRandomHand(&G, handCount-coins, p);
                        if(coins > 0)
                        {
                            updateHandCoins(&G,handCount,p, coins);
                        }
                        //int handIndex;
                        // for(handIndex = 0; handIndex < G.handCount[p]; handIndex++) 
                        // {
                        //     int card = G.hand[p][handIndex];
                        //     printf("card: %d\n",card);
                        // }
                        checkFeastCard(choice1, coins, &G, p);
                    }
                }
            }
        }
    }
    return 0;

}
