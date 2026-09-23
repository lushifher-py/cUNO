#include <stdlib.h>
#include <time.h>
#include "cards.h"
#include "dynarr.h"
#include "flags.h"

pointer_f memexchange(Card* loc1, Card* loc2)
{
    if(loc1 == NULL || loc2 == NULL)
        return NULL_POINTER_ERR;
    
    Card temp_card = *loc1;
    *loc1 = *loc2;
    *loc2 = temp_card;
    
    return NO_ERR;
}

//fisher-yates shuffle algorithm
//XXX : call srand in main()

dynarray_result shuffle(dynarray arr)
{
    if (arr.size == 0)
        return DYNARRAY_NULL;

    if (arr.size == 1)
        return DYNARRAY_OK;
    
    size_t rand_loc;

    for (size_t i = arr.size -1; i>0 ; i--)
    {
        rand_loc = rand() % (i+1);
        memexchange
        (
            &arr.head[i],
            &arr.head[rand_loc]
        );
    }

    return DYNARRAY_OK;
}
