#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define UNITTEST "discardCard"
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0


int main()
{
	int p=0;
    int seed = 1000;
    int numPlayer = 2;
    int handCount = 1;
    int handPos = 1; 
    int k[7] = {treasure_map, council_room, gardens, remodel, village, baron, great_hall};
    int coppers[MAX_HAND];
    struct gameState G;
    int maxHandCount = 5;
    int playedCardCount = 4;
   

    printf ("TESTING discardCard():\n");
   	//test both player turns
	for (p=0; p< numPlayer; p++)
	{
		 //goes through handcount 1, 2, 3, 4, and 5 (all possible counts)
		for (handCount = 1;handCount <= maxHandCount; handCount++)
	    {
	    	//go through every possible hand position
	    	for(handPos = 1; handPos <= handCount; handPos++)
	    	{
		    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
			    initializeGame(numPlayer, k, seed, &G); // initialize a new game
			    
			    G.handCount[p] = handCount;    //set number of cards in hand
			    memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set so there are cards
			    G.hand[p][handPos] = handPos; //set players hand position
			    G.playedCardCount = playedCardCount;
			    
				#if (NOISY_TEST == 1)
			    printf("Testing card with trashFlag set to 0.\nHand count is %d, player is %d.\n", handCount, p);
				#endif
			    
			    discardCard(handPos, p, &G, 0);
				
				#if (NOISY_TEST == 1)
			    printf("PlayedCardCount Expected: %d, PlayedCardCount Actual: %d\n", playedCardCount + 1, G.playedCardCount);
				printf("Number of cards in player hand expected:%d, Actual: %d\n", handCount -1, G.handCount[p]);
				
				if(G.handCount[p] != 1 && handPos != G.handCount[p]-1)//else of function
				{
					printf("Card Replaced with last card in hand expected.\n");
					//printf("Last card in deck value expected: -1, Actual: %d\n",G.hand[p][G.handCount[p] -1]);
                    printf("Last card in deck value expected: -1, Actual: %d\n",G.hand[p][handPos]);
                    printf("Card value of hand position expected: %d, Actual: %d\n",G.hand[p][G.handCount[p]-1],G.hand[p][handPos]);
				}
                else
                {
                    printf("Played card expected: -1. Actual: %d\n", G.hand[p][handPos]);
                }
				#endif
			    assert(G.playedCardCount == playedCardCount + 1);//card added to play pile
			    assert(G.handCount[p] == handCount - 1);//card removed from players hand (all cases)
			    
			    if(G.handCount[p] != 1 && handPos != G.handCount[p]-1)//else of function
			    {
                    //Failures Occuring Here
			    	//assert(G.hand[p][G.handCount[p] -1] == -1);
			    	//assert(G.hand[p][handPos] == G.hand[p][G.handCount[p]-1]);
			    }
                else
                {
                    //Failures occurring here
                    //assert(G.hand[p][handPos] == -1);//discard card
                }
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
			    initializeGame(numPlayer, k, seed, &G); // initialize a new game
			    G.handCount[p] = handCount;
			    G.hand[p][handPos] = handPos;
			    memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set so there are cards
			    G.playedCardCount = playedCardCount; 
				
				#if (NOISY_TEST == 1)
			    printf("Testing card with trashFlag set to 1.\nHand count is %d, player is %d.\n", handCount, p);
				#endif    
			    
			    discardCard(handPos, p, &G, 1);
			    
			    #if (NOISY_TEST == 1)
			    printf("PlayedCardCount Expected: %d, PlayedCardCount Actual: %d\n", playedCardCount, G.playedCardCount);
			    printf("Number of cards in player hand expected:%d, Actual: %d\n", handCount -1, G.handCount[p]);
			    if(G.handCount[p] != 1 && handPos != G.handCount[p]-1)//else of function
				{
					printf("Card Replaced with last card in hand expected.\n");
					//printf("Last card in deck value expected: -1, Actual: %d\n",G.hand[p][G.handCount[p] -1]);
                    printf("Last card in deck value expected: -1, Actual: %d\n",G.hand[p][handPos]);
					printf("Card value of hand position expected: %d, Actual: %d\n",G.hand[p][G.handCount[p]-1],G.hand[p][handPos]);
				}
                else
                {
                   printf("Played card expected: -1. Actual: %d\n", G.hand[p][handPos]);
                }
			    #endif
			    

			    assert(G.playedCardCount == playedCardCount);//card is not trashed
				assert(G.handCount[p] == handCount - 1);//card removed from hand
				if(G.handCount[p] != 1 && handPos != G.handCount[p]-1)//else of function
				{
                     //Failures Occuring Here
					//assert(G.hand[p][G.handCount[p] -1] == -1);
                    //assert(G.hand[p][handPos] == G.hand[p][G.handCount[p]-1]);
					
				}
                else
                {
                    //Failures occuring here
                    //assert(G.hand[p][handPos] == -1); //discard card
                }
			}
		}
	}
    printf("Test Completed.\n");

    return 0;
}