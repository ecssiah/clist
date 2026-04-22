#include <stdio.h>
#include <stdlib.h>

typedef struct ListHeader ListHeader;
struct ListHeader
{
    size_t count;
    size_t capacity;
};

#define list_init(list, initial_capacity)                                                 \
do {                                                                                      \
    ListHeader *header = malloc(sizeof(*list) * (initial_capacity) + sizeof(ListHeader)); \
    header->count = 0;                                                                    \
    header->capacity = (initial_capacity);                                                \
    list = (void *)(header + 1);                                                          \
} while (0)                                                                               \

#define list_clear(list)                           \
do {                                               \
    ListHeader *header = (ListHeader *)(list) - 1; \
    header->count = 0;                             \
} while (0)                                        \

#define list_add(list, item)                                                                         \
do {                                                                                                 \
    ListHeader *header = (ListHeader *)(list) - 1;                                                   \
                                                                                                     \
    if (header->count >= header->capacity)                                                           \
    {                                                                                                \
        size_t new_capacity = header->capacity * 2.0f;                                               \
        ListHeader *new_header = realloc(header, sizeof(*list) * new_capacity + sizeof(ListHeader)); \
                                                                                                     \
        if (new_header)                                                                              \
        {                                                                                            \
            header = new_header;                                                                     \
            header->capacity = new_capacity;                                                         \
                                                                                                     \
            list = (void *)(header + 1);                                                             \
        }                                                                                            \
    }                                                                                                \
                                                                                                     \
    (list)[header->count++] = (item);                                                                \
} while (0)                                                                                          \

#define list_len(list)        ((ListHeader *)(list) - 1)->count
#define list_capacity(list)   ((ListHeader *)(list) - 1)->capacity

#define list_for(item, list) for (item = list; item < list + list_len(list); ++item)
