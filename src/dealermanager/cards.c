#include <stdbool.h>
#include "cards.h"


bool is_wild(Card card)
{
    if (card.value == WILD_CHANGE || card.value == WILD_PLUS)
        return true;
    
    return false;
}

bool is_action(Card card)
{
    if (card.value == PLUS || card.value == SKIP || card.value == REVERSE)
        return true;
    
    return false;
}
