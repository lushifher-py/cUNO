#pragma once

#include "dynarr.h"
#include "cards.h"
#include "flags.h"

pointer_f memexchange(Card *loc1, Card *loc2);
dynarray_result shuffle(dynarray arr);