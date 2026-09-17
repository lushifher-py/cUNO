#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "dynarr.h"
#include "flags.h"

pointer_f load_array(dynarray* arr, size_t length)
{
    Card* temp_ptr = malloc(length * sizeof(Card));
    if (temp_ptr == NULL)
        return ALLOCATION_ERR;

    arr->head = temp_ptr;
    arr->size = 0;
    arr->capacity = length;

    return NO_ERR;
}


pointer_f allocate(dynarray* arr, Card data)
{
    if (arr->size >= arr->capacity)
    {
        size_t new_capacity = (arr->capacity == 0)?1 : 2 * (arr->capacity);
        Card* temp_ptr = realloc(arr->head, new_capacity * sizeof(Card));

        if (temp_ptr == NULL)
            return ALLOCATION_ERR; 

        arr->head = temp_ptr;
        arr->capacity = new_capacity; //TODO : add overflow handling
    }
    arr->head[arr->size] = data;
    arr->size++;

    return NO_ERR;
}

dynarray_result read_data(dynarray* arr, size_t location, Card* out)
{
    if (arr== NULL || out == NULL)
        return DYNARRAY_INVALID;

    if(location >= arr->size)
        return DYNARRAY_BOUNDS;
    
    *out = arr->head[location];
    return DYNARRAY_OK;
}

dynarray_result pop_data(dynarray* arr, size_t location, Card* out)
{
    if(arr == NULL || out == NULL)
        return DYNARRAY_INVALID;

    if(location >= arr->size)
        return DYNARRAY_BOUNDS;

    *out = arr->head[location];
    
    size_t data_chunk_size = arr->size - 1 - location;
    if(data_chunk_size > 0)
        memmove
        (
            &(arr->head[location]),
            &(arr->head[location + 1]),
            sizeof(Card) * data_chunk_size
        );

    arr->size --;
    memset(&arr->head[arr->size], 0, sizeof(Card) );

    return DYNARRAY_OK;
}

dynarray_result unload_data(dynarray* arr)
{
    if (arr == NULL)
        return DYNARRAY_INVALID;
    
    free(arr->head);
    arr->head = NULL;
    
    memset(arr, 0, sizeof(*arr) );
    return DYNARRAY_OK;
}

