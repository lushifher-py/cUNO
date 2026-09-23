#include "cards.h"
#include "dynarr.h"
#include "shuffler.h"
#include "flags.h"

#define MASTER_DECK_SIZE 108
#define PLAYER_DECK_SIZE 7
#define GARBAGE_PILE_SIZE 30 

normal_f deal_cards(dynarray* MasterDeck, dynarray* PlayerDeck, dynarray* CompDeck, dynarray* GarbagePile )//TODO : error handling
{
    Card temp_buffer;
    normal_f flag_buffer;
    dynarray_result flag_dynarray;

    //ini dynarray
    flag_buffer = load_array(MasterDeck, MASTER_DECK_SIZE);

    if(flag_buffer == ALLOCATION_ERR)
        return FAIL;

    //load cards into master deck
    for (int i = 0; i <= YELLOW; i++)
    {
        Card zero_card = (Card){ i, ZERO };
        flag_buffer = allocate(MasterDeck, zero_card);
        if(flag_buffer == ALLOCATION_ERR)
            return FAIL;

        for(int j = ONE; j <= REVERSE; j++)
        {
            Card temp_card1 = (Card) { i, j };
            Card temp_card2 = (Card) { i, j };

            flag_buffer = allocate(MasterDeck, temp_card1);
            if(flag_buffer == ALLOCATION_ERR)
                return FAIL;
            flag_buffer = allocate(MasterDeck, temp_card2);
            if(flag_buffer == ALLOCATION_ERR)
                return FAIL;
        }
    }

    for (int i= 0; i < 4; i++)
    {
        Card temp_card = (Card){ NO_C, WILD_PLUS };
        flag_buffer = allocate(MasterDeck, temp_card);
        if(flag_buffer == ALLOCATION_ERR)
            return FAIL;
    }

    for (int i =0; i< 4; i++)
    {
        Card temp_card = (Card){ NO_C, WILD_CHANGE };
        flag_buffer = allocate(MasterDeck, temp_card);
        if(flag_buffer == ALLOCATION_ERR)
            return FAIL;
    }

    //shuffle the master deck
    flag_dynarray = shuffle(*MasterDeck);

    if(flag_dynarray == DYNARRAY_NULL)
        return FAIL;

    //allocate player deck
    flag_buffer = load_array(PlayerDeck, PLAYER_DECK_SIZE);
    if(flag_buffer == ALLOCATION_ERR)
        return FAIL;
    
    for (size_t i = 0; i < PLAYER_DECK_SIZE; i++)
    {
        flag_dynarray = pop_data(
                        MasterDeck,
                        MasterDeck->size -1,
                        &temp_buffer
                        );
        if (flag_dynarray != DYNARRAY_OK)
            return FAIL;
        flag_buffer = allocate(PlayerDeck, temp_buffer);
        if(flag_buffer == ALLOCATION_ERR)
            return FAIL;
    }

    //alocate computer deck
    flag_buffer = load_array(CompDeck, PLAYER_DECK_SIZE);
    if(flag_buffer == ALLOCATION_ERR)
        return FAIL;

    for (size_t i = 0; i < PLAYER_DECK_SIZE; i++)
    {
        flag_dynarray = pop_data(
                        MasterDeck,
                        MasterDeck->size -1,
                        &temp_buffer
                        );
        if (flag_dynarray != DYNARRAY_OK)
            return FAIL;
        
        flag_buffer = allocate(CompDeck, temp_buffer);
        if(flag_buffer == ALLOCATION_ERR)
            return FAIL;
    }

    //garbage pile
    flag_buffer = load_array(GarbagePile, GARBAGE_PILE_SIZE);
    if (flag_dynarray != DYNARRAY_OK)
        return FAIL;

    flag_dynarray = pop_data(
        MasterDeck,
        MasterDeck->size -1,
        &temp_buffer
    );
    if (flag_dynarray != DYNARRAY_OK)
        return FAIL;

    flag_buffer = allocate(GarbagePile, temp_buffer);
    if(flag_buffer == ALLOCATION_ERR)
        return FAIL;

    return SUCCESS;
}
