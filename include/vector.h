#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define VECTOR_ALLOC_DEFAULT 4

//매크로로 확장되는, 동적 가변배열 유사템플릿입니다.
//정적배열의 래퍼 유사클래스를 생성합니다.
#define decl_vector(declname,type) \
\
/*배열 유사클래스 전방선언*/ \
struct declname; \
typedef struct declname declname; \
\
/*전용 반복자 유사클래스 전방선언*/ \
struct declname##_iterator; \
typedef struct declname##_iterator declname##_iterator; \
\
/*반복자 유사클래스.*/ \
struct declname##_iterator \
{ \
    type* ptr; \
\
    /*반복을 하거나 역반복을 수행*/ \
    void (*next)(declname##_iterator*); \
    void (*prev)(declname##_iterator*); \
\
    /*반복자에 담긴 값이나 그 포인터를 가져옴.*/ \
    type (*get)(const declname##_iterator*); \
    type* (*get_ptr)(declname##_iterator*); \
\
    /*두 반복자를 비교. 같으면 true*/ \
    bool (*equals)(const declname##_iterator*, const declname##_iterator*); \
}; \
/*유사 메서드 선언*/ \
void declname##_iterator_next(declname##_iterator*); \
void declname##_iterator_prev(declname##_iterator*); \
type declname##_iterator_get(const declname##_iterator*); \
type* declname##_iterator_get_ptr(declname##_iterator*); \
bool declname##_iterator_equals(const declname##_iterator*, const declname##_iterator*); \
/*비멤버 make 함수 선언*/ \
declname##_iterator new_##declname##_iterator(type*); \
\
\
/*실체화되는 배열 유사클래스*/ \
struct declname \
{ \
    type * const data; \
    const size_t length; \
    const size_t capacity; \
    \
    void (*clear)(declname*); \
    void (*realloc)(declname*, size_t); \
    void (*reserve)(declname*, size_t); \
    \
    void (*push_back)(declname*, type); \
    void (*push_back_ptr)(declname*, const type*); \
    void (*pop_back)(declname*); \
    \
    bool (*is_empty)(const declname*); \
    bool (*is_not_empty)(const declname*); \
    \
    /*길이를 가져옴*/ \
    size_t (*size)(const declname*); \
    \
    /*요소 액세스*/ \
    type (*get)(const declname*, size_t); \
    type* (*get_ptr)(declname*, size_t); \
    const type* (*get_cptr)(const declname*, size_t); \
    \
    declname (*clone)(const declname*); \
    \
    /*반복자를 반환*/ \
    declname##_iterator (*begin)(declname*); \
    declname##_iterator (*end)(declname*); \
    \
    /*선형탐색 후 찾은 위치의 반복자를 반환*/ \
    declname##_iterator (*find)(const declname*, const type); \
    declname##_iterator (*find_by)(const declname*, int(*)(const type*)); \
    \
    /*선형탐색 후 해당하는 인덱스를 반환*/ \
    size_t (*indexof)(const declname*, const type); \
    size_t (*indexof_by)(const declname*, int(*)(const type*)); \
    \
    /*선형탐색으로 포함 여부를 확인*/ \
    bool (*contains)(const declname*, const type); \
    bool (*contains_by)(const declname*, int(*)(const type*)); \
    \
    /*이진탐색 후 찾은 위치의 반복자를 반환*/ \
    declname##_iterator (*bfind)(const declname*, const type); \
    declname##_iterator (*bfind_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*이진탐색 후 해당하는 인덱스를 반환*/ \
    size_t (*bindexof)(const declname*, const type); \
    size_t (*bindexof_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*이진탐색으로 포함 여부를 확인*/ \
    bool (*bcontains)(const declname*, const type); \
    bool (*bcontains_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*해당 값이나 값의 포인터로, 배열을 채움*/ \
    void (*fill)(declname*, const type); \
    void (*fill_ptr)(declname*, const type*); \
    \
    /*정렬용*/ \
    void (*sort)(declname*); \
    void (*sort_by)(declname*, int(*)(const type*, const type*)); \
    \
    /*콜백함수를 받아서 범위기반 루프를 돎*/ \
    void (*for_each)(const declname*, void(*)(const type)); \
    void (*for_each_ptr)(declname*, void(*)(type*)); \
    void (*for_each_cptr)(const declname*, void(*)(const type*)); \
}; \
/*유사 메서드 선언*/ \
void declname##_clear(declname*); \
void declname##_realloc(declname*, size_t); \
void declname##_reserve(declname*, size_t); \
void declname##_push_back(declname*, type); \
void declname##_push_back_ptr(declname*, const type*); \
void declname##_pop_back(declname*); \
bool declname##_is_empty(const declname*); \
bool declname##_is_not_empty(const declname*); \
size_t declname##_size(const declname*); \
type declname##_get(const declname*, size_t); \
type* declname##_get_ptr(declname*, size_t); \
const type* declname##_get_cptr(const declname*, size_t); \
declname declname##_clone(const declname*); \
declname##_iterator declname##_begin(declname*); \
declname##_iterator declname##_end(declname*); \
declname##_iterator declname##_find(const declname*, const type); \
declname##_iterator declname##_find_by(const declname*, int(*)(const type*)); \
size_t declname##_indexof(const declname*, const type); \
size_t declname##_indexof_by(const declname*, int(*)(const type*)); \
bool declname##_contains(const declname*, const type); \
bool declname##_contains_by(const declname*, int(*)(const type*)); \
declname##_iterator declname##_bfind(const declname*, const type); \
declname##_iterator declname##_bfind_by(const declname*, const type*, int(*)(const type*, const type*)); \
size_t declname##_bindexof(const declname*, const type); \
size_t declname##_bindexof_by(const declname*, const type*, int(*)(const type*, const type*)); \
bool declname##_bcontains(const declname*, const type); \
bool declname##_bcontains_by(const declname*, const type*, int(*)(const type*, const type*)); \
void declname##_fill(declname*, const type); \
void declname##_fill_ptr(declname*, const type*); \
void declname##_sort(declname*); \
void declname##_sort_by(declname*, int(*)(const type*, const type*)); \
void declname##_for_each(const declname*, void(*)(const type)); \
void declname##_for_each_ptr(declname*, void(*)(type*)); \
void declname##_for_each_cptr(const declname*, void(*)(const type*)); \
\
/*비멤버 함수*/ \
declname new_##declname (); \
declname new_##declname##_with (size_t); \
void declname##_alloc(declname*); \
void declname##_alloc_reduction(declname*); \
\
\
/*배열 메서드 정의.*/ \
void declname##_clear(declname* self) \
{ \
    free((type*)self->data); \
    *(const type**)(&self->data) = NULL; \
    *(size_t*)(&self->length) = 0; \
} \
\
void declname##_realloc(declname* self, size_t len) \
{ \
    realloc((type*)self->data, sizeof(type)*len); \
    *(size_t*)(&self->length) = len; \
} \
\
void declname##_reserve(declname* self, size_t size) \
{ \
   if(self->capacity < size) \
        if(self->data == NULL) /*비어있으면 할당*/ \
            *(type**)(&self->data) = malloc(sizeof(type)*size); \
        else /*있으면 재할당*/ \
            realloc((type*)self->data, sizeof(type)*size); \
} \
\
/*메서드 아님*/\
void declname##_alloc(declname* self) \
{ \
    if(self->data == NULL) /*비어있으면 기본사이즈로 할당*/ \
    { \
        *(type**)(&self->data) = malloc(sizeof(type)*VECTOR_ALLOC_DEFAULT); \
        *(size_t*)&self->capacity = VECTOR_ALLOC_DEFAULT; \
    } \
    else \
    { \
        realloc((type*)self->data, sizeof(type)*self->capacity*2); \
        *(size_t*)&self->capacity *= 2; \
    }\
} \
void declname##_alloc_reduction(declname* self) \
{ \
    realloc((type*)self->data, self->capacity/2); \
    *(size_t*)&self->capacity /= 2; \
} \
\
void declname##_push_back(declname* self, type value) \
{ \
    if(self->length == self->capacity) \
        declname##_alloc(self); \
    self->data[self->length] = value; \
    ++ *(size_t*)(&self->length); \
   \
} \
\
void declname##_push_back_ptr(declname* self, const type* value) \
{ \
   if(self->length == self->capacity) \
        declname##_alloc(self); \
    self->data[self->length] = *value; \
    ++ *(size_t*)(&self->length); \
} \
\
void declname##_pop_back(declname* self) \
{ \
   if(self->length*2 == self->capacity) \
        declname##_alloc_reduction(self); \
    -- *(size_t*)(&self->length); \
} \
\
bool declname##_is_empty(const declname* self) \
{ \
    return self->data == NULL; \
} \
\
bool declname##_is_not_empty(const declname* self) \
{ \
   return self->data != NULL; \
} \
\
size_t declname##_size(const declname* self) \
{ \
    return self->length; \
} \
\
type declname##_get(const declname* self, size_t index) \
{ \
    assert(self->length > index); \
    return self->data[index]; \
} \
\
type* declname##_get_ptr(declname* self, size_t index) \
{ \
    assert(self->length > index); \
   return (type*)&(self->data[index]); \
} \
\
const type* declname##_get_cptr(const declname* self, size_t index) \
{ \
    assert(self->length > index); \
   return &(self->data[index]); \
} \
\
int declname##_comparer(const void* lhs, const void* rhs) \
{ \
    return *(type*)lhs - *(type*)rhs; \
} \
\
void declname##_sort(declname* self) \
{ \
    qsort(self->data, self->length, sizeof(type), (int (*)(const void *, const void *))declname##_comparer); \
} \
\
void declname##_sort_by(declname* self, int(*comp)(const type*, const type*)) \
{ \
     qsort(self->data, self->length, sizeof(type), (int (*)(const void *, const void *))comp); \
} \
\
declname declname##_clone(const declname* self) \
{ \
    declname temp = new_##declname##_with(self->length); \
    for(int i=0;i<self->length;++i) \
        temp.data[i] = self->data[i]; \
    return temp; \
} \
\
declname##_iterator declname##_begin(declname* self) \
{ \
    declname##_iterator it = \
    new_##declname##_iterator(self->data); \
    return it; \
} \
\
declname##_iterator declname##_end(declname* self) \
{ \
    declname##_iterator it = \
    new_##declname##_iterator(self->data+self->length); \
    return it; \
} \
\
void declname##_fill(declname* self, const type value) \
{ \
    for(int i = 0; i<self->length; ++i) \
        self->data[i] = value; \
} \
\
void declname##_fill_ptr(declname* self, const type* value) \
{ \
    for(int i = 0; i<self->length; ++i) \
        self->data[i] = *value; \
} \
\
declname##_iterator declname##_find(const declname* self, const type key) \
{ \
    for(int i = 0; i<self->length; ++i)\
        if(self->data[i] == key) \
            return new_##declname##_iterator((type*)&(self->data[i])); \
    \
    return self->end((declname*)&self); \
} \
\
declname##_iterator declname##_find_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<self->length; ++i)\
        if(comp(&self->data[i])) \
            return new_##declname##_iterator((type*)&(self->data[i])); \
\
    return self->end((declname*)&self); \
} \
\
declname##_iterator declname##_bfind(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, self->length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[self->length-1])) \
        return new_##declname##_iterator(p); \
    return self->end((declname*)&self); \
} \
\
int declname##_bsearch(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int head = 0; \
    int tail = self->length-1; \
    int middle; \
    \
    while(1) \
    { \
        int comp_head = comp(key, &self->data[head]); \
        int comp_tail = comp(key, &self->data[tail]); \
        if(comp_head<0 || comp_tail>0) \
            return self->length; \
        if(comp_head==0) \
            return head; \
        if(comp_tail==0) \
            return tail; \
        \
        middle = (tail - head)/2; \
        int comp_mid = comp(key, &self->data[middle]); \
        if(comp_mid == 0) \
            return middle; \
        else if(0<comp_mid) /*key가 중간치보다 큼*/ \
            --tail, head = middle; \
        else /*key가 중간치보다 작음*/ \
            ++head, tail = middle; \
    } \
} \
\
declname##_iterator declname##_bfind_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<self->length) \
        return new_##declname##_iterator((type*)&self->data[index]); \
    return self->end((declname*)&self); \
} \
\
size_t declname##_indexof(const declname* self, const type key) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(self->data[i] == key) \
            return i; \
    return self->length; \
} \
\
size_t declname##_indexof_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(comp(&self->data[i])) \
            return i; \
    return self->length; \
} \
\
size_t declname##_bindexof(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, self->length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[self->length-1])) \
        return p - self->data; \
    return self->length; \
} \
\
size_t declname##_bindexof_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<self->length) \
        return index; \
    return self->length; \
} \
\
bool declname##_contains(const declname* self, const type key) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(self->data[i] == key) \
        return true; \
    return false; \
} \
\
bool declname##_contains_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<self->length; ++i) \
        if(comp(&self->data[i])) \
            return true; \
    return false; \
} \
\
bool declname##_bcontains(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, self->length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[self->length-1])) \
        return true; \
    return false; \
} \
\
bool declname##_bcontains_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<self->length) \
        return true; \
    return false; \
} \
\
void declname##_for_each(const declname* self, void(*f)(const type)) \
{ \
    for(int i =0; i<self->length; ++i) \
        f(self->data[i]); \
} \
\
void declname##_for_each_ptr(declname* self, void(*f)(type*)) \
{ \
    for(int i =0; i<self->length; ++i) \
        f(&self->data[i]); \
} \
\
void declname##_for_each_cptr(const declname* self, void(*f)(const type*)) \
{ \
    for(int i =0; i<self->length; ++i) \
        f(&self->data[i]); \
} \
\
declname new_##declname () \
{ \
    declname temp = \
    { \
        .data = NULL, \
        .length = 0, \
        .capacity = 0, \
        .push_back = declname##_push_back, \
        .push_back_ptr = declname##_push_back_ptr, \
        .pop_back = declname##_pop_back, \
        .clear = declname##_clear, \
        .realloc = declname##_realloc, \
        .is_empty = declname##_is_empty, \
        .is_not_empty = declname##_is_not_empty, \
        .size= declname##_size, \
        .get = declname##_get, \
        .get_ptr = declname##_get_ptr, \
        .get_cptr = declname##_get_cptr, \
        .sort= declname##_sort, \
        .sort_by= declname##_sort_by, \
        .clone= declname##_clone, \
        .begin= declname##_begin, \
        .end= declname##_end, \
        .fill= declname##_fill, \
        .fill_ptr= declname##_fill_ptr, \
        .find= declname##_find, \
        .find_by= declname##_find_by, \
        .bfind= declname##_bfind, \
        .bfind_by= declname##_bfind_by, \
        .indexof= declname##_indexof, \
        .indexof_by= declname##_indexof_by, \
        .bindexof= declname##_bindexof, \
        .bindexof_by= declname##_bindexof_by, \
        .contains= declname##_contains, \
        .contains_by= declname##_contains_by, \
        .bcontains= declname##_bcontains, \
        .bcontains_by= declname##_bcontains_by, \
        .for_each= declname##_for_each, \
        .for_each_ptr= declname##_for_each_ptr, \
        .for_each_cptr= declname##_for_each_cptr \
    }; \
    return temp; \
} \
\
declname new_##declname##_with (size_t len) \
{ \
    declname temp = new_##declname(); \
    return temp; \
} \
\
\
/*반복자 메서드 정의*/ \
void declname##_iterator_next(declname##_iterator* self) \
{ \
    ++(self->ptr); \
} \
\
void declname##_iterator_prev(declname##_iterator* self) \
{ \
    --(self->ptr); \
} \
\
type declname##_iterator_get(const declname##_iterator* self) \
{ \
    return *(self->ptr); \
} \
\
type* declname##_iterator_get_ptr(declname##_iterator* self) \
{ \
    return self->ptr; \
} \
\
bool declname##_iterator_equals(const declname##_iterator* self, const declname##_iterator* other) \
{ \
    return self->ptr == other->ptr; \
} \
\
declname##_iterator new_##declname##_iterator(type* p) \
{ \
    declname##_iterator it = \
    { \
        p, \
        declname##_iterator_next, \
        declname##_iterator_prev, \
        declname##_iterator_get, \
        declname##_iterator_get_ptr, \
        declname##_iterator_equals \
    }; \
    return it; \
} 