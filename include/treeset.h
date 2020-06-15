#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//디폴트 트리는 레드블랙 트리
#define decl_treeset(declname, type) decl_rbtreeset(declname, type)

enum _RB_Color
{
    _RB_RED,
    _RB_BLACK
};

//레드블랙 트리입니다.
#define decl_rbtreeset(declname, type)                                 \
                                                                       \
    bool declname##_default_comparer(const type *lhs, const type *rhs) \
    {                                                                  \
        return *lhs < *rhs;                                            \
    }                                                                  \
                                                                       \
    decl_rbtreeset_with(declname, type, declname##_default_comparer)

//구현
#define decl_rbtreeset_with(declname, type, comparer)                                                                                 \
                                                                                                                                      \
    struct declname;                                                                                                                  \
    struct declname##_node;                                                                                                           \
    struct declname##_iterator;                                                                                                       \
                                                                                                                                      \
    struct declname##_node                                                                                                            \
    {                                                                                                                                 \
        type data;                                                                                                                    \
        declname##_node *left_child;                                                                                                  \
        declname##_node *right_child;                                                                                                 \
        _RB_Color color;                                                                                                              \
    };                                                                                                                                \
                                                                                                                                      \
    struct declname##_iterator                                                                                                        \
    {                                                                                                                                 \
        declname##_node *ptr;                                                                                                         \
                                                                                                                                      \
        void (*next)(declname##_iterator *);                                                                                          \
        void (*prev)(declname##_iterator *);                                                                                          \
        void (*equals)(const declname##_iterator *, const declname##_iterator *);                                                     \
    };                                                                                                                                \
                                                                                                                                      \
    void declname##_next(declname##_iterator *);                                                                                      \
    void declname##_prev(declname##_iterator *);                                                                                      \
    void declname##_equals(const declname##_iterator *, const declname##_iterator *);                                                 \
                                                                                                                                      \
    struct declname                                                                                                                   \
    {                                                                                                                                 \
        declname##_node *root;                                                                                                        \
        size_t length;                                                                                                                \
                                                                                                                                      \
        size_t (*size)(const declname *);   /*컨테이너의 요소 수를 반환합니다.*/                                        \
        bool (*is_empty)(const declname *); /*컨테이너가 비어있는지를 확인합니다.*/                                   \
        bool (*is_not_empty)(const declname *);                                                                                       \
                                                                                                                                      \
        void (*clear)(declname *); /*요소를 전부 해제합니다.*/                                                              \
                                                                                                                                      \
        void (*insert)(declname *, type); /*값을 새로 삽입합니다.*/                                                          \
        void (*insert_ptr)(declname *, const type *);                                                                                 \
                                                                                                                                      \
        void (*erase)(declname *, type);                                           /*값에 해당하는 요소를 삭제합니다.*/ \
        void (*erase_iter)(declname *, declname##_iterator);                       /*반복자를 받아 삭제합니다.*/           \
        void (*erase_range)(declname *, declname##_iterator, declname##_iterator); /*반복자 범위를 삭제합니다.*/           \
                                                                                                                                      \
        /*특정 값의 포함 여부를 확인합니다.*/                                                                           \
        bool (*contains)(const declname *, type);                                                                                     \
        bool (*contains_ptr)(const declname *, const type *);                                                                         \
                                                                                                                                      \
        /*특정 값을 탐색해 반복자를 반환합니다. */                                                                    \
        declname##_iterator (*find)(const declname *, type);                                                                          \
        declname##_iterator (*find_ptr)(const declname *, const type *);                                                              \
                                                                                                                                      \
        declname##_iterator (*begin)(const declname *);                                                                               \
        declname##_iterator (*end)(const declname *);                                                                                 \
                                                                                                                                      \
        void (*for_each)(const declname *, void (*)(type));                                                                           \
        void (*for_each_ptr)(declname *, void (*)(type *));                                                                           \
        void (*for_each_cptr)(const declname *, void (*)(const type *));                                                              \
    };                                                                                                                                \
                                                                                                                                      \
    size_t declname##_size(const declname *);                                                                                         \
    bool declname##_is_empty(const declname *);                                                                                       \
    bool declname##_is_not_empty(const declname *);                                                                                   \
    void declname##_clear(declname *);                                                                                                \
    void declname##_insert(declname *, type);                                                                                         \
    void declname##_insert_ptr(declname *, const type *);                                                                             \
    void declname##_erase(declname *, type);                                                                                          \
    void declname##_erase_iter(declname *, declname##_iterator);                                                                      \
    void declname##_erase_range(declname *, declname##_iterator, declname##_iterator);                                                \
    bool declname##_contains(const declname *, type);                                                                                 \
    bool declname##_contains_ptr(const declname *, const type *);                                                                     \
    declname##_iterator declname##_find(const declname *, type);                                                                      \
    declname##_iterator declname##_find_ptr(const declname *, const type *);                                                          \
    declname##_iterator declname##_begin(const declname *);                                                                           \
    declname##_iterator declname##_end(const declname *);                                                                             \
    void declname##_for_each(const declname *, void (*)(type));                                                                       \
    void declname##_for_each_ptr(declname *, void (*)(type *));                                                                       \
    void declname##_for_each_cptr(const declname *, void (*)(const type *));                                                          \
                                                                                                                                      \
    inline declname make_##declname();                                                                                                \
                                                                                                                                      \
    inline declname make_##declname()                                                                                                 \
    {                                                                                                                                 \
        declname temp =                                                                                                               \
            {                                                                                                                         \
                .root = NULL,                                                                                                         \
                .size = declname##_size,                                                                                              \
                .is_empty = declname##_is_empty,                                                                                      \
                .is_not_empty = declname##_is_not_empty,                                                                              \
                .clear = declname##_clear,                                                                                            \
                .insert = declname##_insert,                                                                                          \
                .insert_ptr = declname##_insert_ptr,                                                                                  \
                .erase = declname##_erase,                                                                                            \
                .erase_iter = declname##_erase_iter,                                                                                  \
                .erase_range = declname##_erase_range,                                                                                \
                .contains = declname##_contains,                                                                                      \
                .contains_ptr = declname##_contains_ptr,                                                                              \
                .find = declname##_iterator declname##_find,                                                                          \
                .find_ptr = declname##_iterator declname##_find_ptr,                                                                  \
                .begin = declname##_iterator declname##_begin,                                                                        \
                .end = declname##_iterator declname##_end,                                                                            \
                .for_each = declname##_for_each,                                                                                      \
                .for_each_ptr = declname##_for_each_ptr,                                                                              \
                .for_each_cptr = declname##_for_each_cptr};                                                                           \
        return temp;                                                                                                                  \
    }                                                                                                                                 \
    \