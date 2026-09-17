#pragma once 

#include <stdlib.h>
#include "cards.h"

typedef struct 
{
    Card* head;
    size_t size;
    size_t capacity;    
} dynarray;

typedef enum
{
    DYNARRAY_OK,
    DYNARRAY_INVALID,
    DYNARRAY_BOUNDS
} dynarray_result;

pointer_f load_array(dynarray* arr, size_t length);
pointer_f allocate(dynarray* arr, Card data);

dynarray_result read_data(dynarray* arr, size_t location, Card* out);
dynarray_result pop_data(dynarray* arr, size_t location, Card* out);

dynarray_result unload_data(dynarray* arr);