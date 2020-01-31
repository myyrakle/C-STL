#ifndef C_STL_ARRAY_H
#define C_STL_ARRAY_H

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
typdef struct declname##_bucket_node declname##_bucket_node; \
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
    declname##_bucket* bucket_list; \
    size_t bucket_length; \
}; \


#endif
