#ifndef C_STL_HASH_MAP_H
#define C_STL_HASH_MAP_H

#include <stdlib.h>
#include <stdbool.h>

#define decl_hashmap(declname, K, V) \
\
struct declname##_node; \
struct declname##_bucket; \
struct declname##_bucket_node; \
struct declname; \
struct declname##_iterator; \
typedef struct declname##_node declname##_node; \
typedef struct declname##_bucket declname##_bucket; \
typedef struct declname##_bucket_node declname##_bucket_node; \
typedef struct declname declname; \
typedef struct declname##_iterator declname##_iterator; \
\
struct declname##_node \
{ \
    K key; \
    V value; \
}; \
\
struct declname##_bucket_node \
{ \
    declname##_node current; \
    declname##_bucket_node* next; \
}; \
\
struct declname##_bucket \
{ \
    declname##_node* head; \
    size_t length; \
}; \
\
struct declname \
{ \
    declname##_bucket* bucket_array; \
    size_t length; \
    size_t all_count; \
    \
    size_t (*bucket_count)(const declname*); \
    size_t (*size)(const declname*); \
    size_t (*is_empty)(const declname*); \
    \
    size_t (*clear)(declname*); \
    \
    declname##_iterator (*find)(const declname*, K); \
    declname##_iterator (*find_by)(const declname*, bool(*)(const K*)); \
    \
    declname##_iterator (*erase)(declname*, declname##_iterator*); \
    size_t (*remove)(declname*, K); \
}; \


#endif
