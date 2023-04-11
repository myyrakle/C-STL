#ifndef C_STL_HASH_MAP_H
#define C_STL_HASH_MAP_H

#include <stdlib.h>
#include <stdbool.h>

#define HASHMAP_ALLOC_DEFAULT 32

// declname: type name
// K: key type
// V: value type
// hash_function: hash function for key type. size_t(K key, size_t bucket_length)
#define decl_hashmap(declname, K, V, hash_function)                            \
                                                                               \
    struct declname##_node;                                                    \
    struct declname##_bucket;                                                  \
    struct declname##_bucket_node;                                             \
    struct declname;                                                           \
    struct declname##_iterator;                                                \
    typedef struct declname##_node declname##_node;                            \
    typedef struct declname##_bucket declname##_bucket;                        \
    typedef struct declname##_bucket_node declname##_bucket_node;              \
    typedef struct declname declname;                                          \
    typedef struct declname##_iterator declname##_iterator;                    \
                                                                               \
    /* Key-Value node type */                                                  \
    struct declname##_node                                                     \
    {                                                                          \
        K key;                                                                 \
        V value;                                                               \
    };                                                                         \
                                                                                \
    /* linked list node of each bucket */                                      \
    struct declname##_bucket_node                                              \
    {                                                                          \
        declname##_node current;                                               \
        declname##_bucket_node *next;                                          \
    };                                                                         \
                                                                                \
    /* Bucket type identified by hashcode */                                    \
    struct declname##_bucket                                                   \
    {                                                                          \
        declname##_bucket_node *head;                                                 \
        size_t length;                                                         \
    };                                                                         \
                                                                               \
    struct declname##_iterator                                                 \
    {                                                                          \
    };                                                                         \
                                                                               \
    struct declname                                                            \
    {                                                                          \
        declname##_bucket *bucket_array;                                       \
        size_t bucket_length;                                                  \
        size_t total_count;                                                    \
        float load_factor;                                                     \
                                                                               \
        size_t (*bucket_count)(const declname *);                              \
        size_t (*size)(const declname *);                                      \
        bool (*is_empty)(const declname *);                                    \
        bool (*is_not_empty)(const declname *);                                \
                                                                               \
        size_t (*clear)(declname *);                                           \
        void (*rehash)(declname *, size_t);                                    \
                                                                               \
        declname##_iterator (*find)(const declname *, K);                      \
        declname##_iterator (*find_by)(const declname *, bool (*)(const K *)); \
                                                                               \
        declname##_iterator (*erase)(declname *, declname##_iterator *);       \
        size_t (*remove)(declname *, K);                                       \
    };

// 구현부
#define def_hashmap(declname, K, V, hash_function)                                                               \
/* internal function */                                                                                          \
void declname##_rehash(declname *self, size_t count)                                                             \
{                                                                                                                \
    if (self->bucket_array == NULL) /*비어있으면 기본사이즈로 할당*/                                             \
    {                                                                                                            \
        self->bucket_array = (declname##_bucket*)malloc(sizeof(declname##_bucket) * count);                      \
        self->bucket_length = count;                                                                             \
    }                                                                                                            \
    else                                                                                                         \
    {                                                                                                            \
        self->bucket_array = (declname##_bucket*)realloc(self->bucket_array, sizeof(declname##_bucket) * count); \
        /* TODO: 버킷 재분배 */ self->bucket_length = count;                                                     \
    }                                                                                                            \
}                                                                                                                \
                                                                                                                 \
/* internal function */                                                                                          \
void declname##_alloc_reduction(declname *self)                                                                  \
{                                                                                                                \
    realloc((declname##_bucket*)self->bucket_array, self->bucket_length / 2);                                    \
    *(size_t *)&self->bucket_length /= 2;                                                                        \
}                                                                                                                \
                                                                                                                 \
bool declname##_is_empty(const declname *self)                                                                   \
{                                                                                                                \
    bool is_empty = self->total_count == 0;                                                                      \
    return is_empty;                                                                                             \
}                                                                                                                \
                                                                                                                 \
bool declname##_is_not_empty(const declname *self)                                                               \
{                                                                                                                \
    return self->total_count != 0;                                                                               \
}                                                                                                                \
                                                                                                                 \
size_t declname##_size(const declname *self)                                                                     \
{                                                                                                                \
    return self->total_count;                                                                                    \
}                                                                                                                \
                                                                                                                 \
size_t declname##_bucket_count(const declname *self)                                                             \
{                                                                                                                \
    return self->bucket_length;                                                                                  \
}                                                                                                                \
                                                                                                                 \
size_t declname##_clear(declname *self)                                                                          \
{                                                                                                                \
    return self->bucket_length;                                                                                  \
}                                                                                                                \
                                                                                                                 \
declname##_iterator declname##_erase(declname *, declname##_iterator *)                                          \
{                                                                                                                \
    declname##_iterator it;                                                                                      \
    return it;                                                                                                   \
}                                                                                                                \
                                                                                                                 \
declname new_##declname(void)                                                                                    \
{                                                                                                                \
    static declname temp =                                                                                       \
        {                                                                                                        \
            .bucket_array = NULL,                                                                                \
            .bucket_length = 64,                                                                                 \
            .total_count = 0,                                                                                    \
            .load_factor = 0.75,                                                                                 \
            .bucket_count = declname##_bucket_count,                                                             \
            .size = declname##_size,                                                                             \
            .is_empty = declname##_is_empty,                                                                     \
            .is_not_empty = declname##_is_not_empty,                                                             \
            .clear = declname##_clear,                                                                           \
            .rehash = declname##_rehash,                                                                         \
            .erase = declname##_erase,                                                                           \
        };                                                                                                       \
                                                                                                                 \
    return temp;                                                                                                 \
}                                                                                                           

#endif
