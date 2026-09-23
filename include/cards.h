#pragma once
#include <stdlib.h> //for size_t
#include <stdbool.h>

//src alt -> src\dealermanager\cards.c

typedef enum{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    NO_C
} Color;

typedef enum{
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
    PLUS,
    SKIP,
    REVERSE,
    WILD_PLUS,
    WILD_CHANGE
} Face_value;

typedef struct 
{
    Color color;
    Face_value value;
} Card;

bool is_wild(Card card);
bool is_action(Card card);