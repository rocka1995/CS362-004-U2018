#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define UNITTEST "getCost"
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{
    printf ("TESTING getCost():\n");
    int cardNumber, result;

    cardNumber = 0;//Curse
    result = getCost(cardNumber);
    assert(result == 0);

    cardNumber = 1;//  estate,
    result = getCost(cardNumber);
    assert(result == 2);

    cardNumber = 2; //duchy,
    result = getCost(cardNumber);
    assert(result == 5);
    
    cardNumber = 3;//province,
    result = getCost(cardNumber);
    assert(result == 8);

    cardNumber = 4;// copper,
    result = getCost(cardNumber);
    assert(result == 0);

    cardNumber = 5;// silver,
    result = getCost(cardNumber);
    assert(result == 3);

    cardNumber = 6;// gold,
    result = getCost(cardNumber);
    assert(result == 6);

    cardNumber = 7;// adventurer,
    result = getCost(cardNumber);
    assert(result == 6);

    cardNumber = 8;// council_room,
    result = getCost(cardNumber);
    assert(result == 5);

    cardNumber = 9;// feast, 
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 10;// gardens,
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 11;// mine,
    result = getCost(cardNumber);
    assert(result == 5);

    cardNumber = 12;// remodel,
    result = getCost(cardNumber);
    assert(result == 4); 

    cardNumber = 13;// smithy,
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 14;// village,
    result = getCost(cardNumber);
    assert(result == 3);  

    cardNumber = 15;// baron,
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 16;// great_hall,
    result = getCost(cardNumber);
    assert(result == 3);

    cardNumber = 17;// minion,
    result = getCost(cardNumber);
    assert(result == 5); 

    cardNumber = 18;// steward,
    result = getCost(cardNumber);
    assert(result == 3); 

    cardNumber = 19;// tribute,
    result = getCost(cardNumber);
    assert(result == 5); 

    cardNumber = 20;// ambassador,
    result = getCost(cardNumber);
    assert(result == 3); 

    cardNumber = 21;// cutpurse,
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 22;// embargo,
    result = getCost(cardNumber);
    assert(result == 2); 

    cardNumber = 23;// outpost,
    result = getCost(cardNumber);
    assert(result == 5);

    cardNumber = 24;// salvager,
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 25;// sea_hag,
    result = getCost(cardNumber);
    assert(result == 4);

    cardNumber = 26;// treasure_map
    result = getCost(cardNumber);
    assert(result == 4);
	
    printf("Test Completed.\n");
}