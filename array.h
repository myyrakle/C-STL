#pragma once

#include <stdlib.h>

//매크로로 확장되는, 배열 유사템플릿입니다.
//정적배열의 래퍼 유사클래스를 생성합니다.
#define decl_array(declname,type,length) \
\
/*배열 유사클래스 전방선언이오*/ \
struct declname; \
typedef struct declname declname; \
\
/*전용 반복자 유사클래스 전방선언이오*/ \
struct declname##_iterator; \
typedef struct declname##_iterator declname##_iterator; \
\
/*반복자 유사클래스.*/ \
struct declname##_iterator \
{ \
    type* ptr; \
\
    /*반복을 하거나 역반복을 수행하오*/ \
    void (*next)(declname##_iterator*); \
    void (*prev)(declname##_iterator*); \
\
    /*반복자에 담긴 값이나 그 포인터를 가져옵니다.*/ \
    type (*get)(const declname##_iterator*); \
    type* (*get_ptr)(declname##_iterator*); \
\
    /*두 반복자를 비교합니다. 같으면 1, 다르면 0*/ \
    int (*equals)(const declname##_iterator*, const declname##_iterator*); \
}; \
/*유사 메서드 선언*/ \
void declname##_iterator_next(declname##_iterator*); \
void declname##_iterator_prev(declname##_iterator*); \
type declname##_iterator_get(const declname##_iterator*); \
type* declname##_iterator_get_ptr(declname##_iterator*); \
int declname##_iterator_equals(const declname##_iterator*, const declname##_iterator*); \
/*비멤버 make 함수 선언*/ \
declname##_iterator make_##declname##_iterator(type*); \
\
\
/*실체화되는 배열 유사클래스*/ \
struct declname \
{ \
    type data[length]; \
    \
    /*길이를 가져오오*/ \
    size_t (*get_length)(const declname*); \
    \
    /*정렬용이오*/ \
    void (*sort)(declname*); \
    void (*sort_by)(declname*, int(*)(const type*, const type*)); \
    \
    declname (*clone)(const declname*); \
    \
    /*반복자를 반환하오*/ \
    declname##_iterator (*begin)(declname*); \
    declname##_iterator (*end)(declname*); \
    \
    /*해당 값이나 값의 포인터로, 배열을 채우는 것이오*/ \
    void (*fill)(declname*, const type); \
    void (*fill_ptr)(declname*, const type*); \
    \
    /*선형탐색 후 찾은 위치의 반복자를 반환하오*/ \
    declname##_iterator (*find)(const declname*, const type); \
    declname##_iterator (*find_by)(const declname*, int(*)(const type*)); \
    \
    /*이진탐색 후 찾은 위치의 반복자를 반환하오*/ \
    declname##_iterator (*bfind)(const declname*, const type); \
    declname##_iterator (*bfind_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*선형탐색 후 해당하는 인덱스를 반환하오*/ \
    size_t (*indexof)(const declname*, const type); \
    size_t (*indexof_by)(const declname*, int(*)(const type*)); \
    \
    /*이진탐색 후 해당하는 인덱스를 반환하오*/ \
    size_t (*bindexof)(const declname*, const type); \
    size_t (*bindexof_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*선형탐색으로 포함 여부를 확인하오*/ \
    int (*contains)(const declname*, const type); \
    int (*contains_by)(const declname*, int(*)(const type*)); \
    \
    /*이진탐색으로 포함 여부를 확인하오*/ \
    int (*bcontains)(const declname*, const type); \
    int (*bcontains_by)(const declname*, const type*, int(*)(const type*, const type*)); \
    \
    /*콜백함수를 받아서 범위기반 루프를 도는 것이오*/ \
    void (*for_each)(const declname*, void(*)(const type)); \
    void (*for_each_ptr)(declname*, void(*)(type*)); \
}; \
/*메서드 선언이오*/ \
size_t declname##_get_length(const declname*); \
void declname##_sort(declname*); \
void declname##_sort_by(declname*, int(*)(const type*, const type*)); \
declname declname##_clone(const declname*); \
declname##_iterator declname##_begin(declname*); \
declname##_iterator declname##_end(declname*); \
void declname##_fill(declname*, const type); \
void declname##_fill_ptr(declname*, const type*); \
declname##_iterator declname##_find(const declname*, const type); \
declname##_iterator declname##_find_by(const declname*, int(*)(const type*)); \
declname##_iterator declname##_bfind(const declname*, const type); \
declname##_iterator declname##_bfind_by(const declname*, const type*, int(*)(const type*, const type*)); \
size_t declname##_indexof(const declname*, const type); \
size_t declname##_indexof_by(const declname*, int(*)(const type*)); \
size_t declname##_bindexof(const declname*, const type); \
size_t declname##_bindexof_by(const declname*, const type*, int(*)(const type*, const type*)); \
int declname##_contains(const declname*, const type); \
int declname##_contains_by(const declname*, int(*)(const type*)); \
int declname##_bcontains(const declname*, const type); \
int declname##_bcontains_by(const declname*, const type*, int(*)(const type*, const type*)); \
void declname##_for_each(const declname*, void(*)(const type)); \
void declname##_for_each_ptr(declname*, void(*)(type*)); \
/*비멤버 함수요*/ \
declname make_##declname (void); \
\
\
/*이것이 바로... [정의]란 것이다...*/ \
size_t declname##_get_length(const declname* self) \
{ \
    return length; \
} \
\
int declname##_comparer(const void* lhs, const void* rhs) \
{ \
    return *(type*)lhs - *(type*)rhs; \
} \
\
void declname##_sort(declname* self) \
{ \
    qsort(self->data, length, sizeof(type), declname##_comparer); \
} \
\
void declname##_sort_by(declname* self, int(*comp)(const type*, const type*)) \
{ \
    \
} \
\
declname declname##_clone(const declname* self) \
{ \
    declname temp = make_##declname(); \
    for(int i=0;i<length;++i) \
        temp.data[i] = self->data[i]; \
    return temp; \
} \
\
declname##_iterator declname##_begin(declname* self) \
{ \
    declname##_iterator it = \
    make_##declname##_iterator(self->data); \
    return it; \
} \
\
declname##_iterator declname##_end(declname* self) \
{ \
    declname##_iterator it = \
    make_##declname##_iterator(self->data+length); \
    return it; \
} \
\
void declname##_fill(declname* self, const type value) \
{ \
    for(int i = 0; i<length; ++i) \
        self->data[i] = value; \
} \
\
void declname##_fill_ptr(declname* self, const type* value) \
{ \
    for(int i = 0; i<length; ++i) \
        self->data[i] = *value; \
} \
\
declname##_iterator declname##_find(const declname* self, const type key) \
{ \
    for(int i = 0; i<length; ++i)\
        if(self->data[i] == key) \
            return make_##declname##_iterator((type*)&(self->data[i])); \
    \
    return self->end((declname*)&self); \
} \
\
declname##_iterator declname##_find_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<length; ++i)\
        if(comp(&self->data[i])) \
            return make_##declname##_iterator((type*)&(self->data[i])); \
\
    return self->end((declname*)&self); \
} \
\
declname##_iterator declname##_bfind(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[length-1])) \
        return make_##declname##_iterator(p); \
    return self->end((declname*)&self); \
} \
\
int declname##_bsearch(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int head = 0; \
    int tail = length-1; \
    int middle; \
    \
    while(1) \
    { \
        int comp_head = comp(key, &self->data[head]); \
        int comp_tail = comp(key, &self->data[tail]); \
        if(comp_head<0 || comp_tail>0) \
            return length; \
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
    if(0<=index && index<length) \
        return make_##declname##_iterator((type*)&self->data[index]); \
    return self->end((declname*)&self); \
} \
\
size_t declname##_indexof(const declname* self, const type key) \
{ \
    for(int i = 0; i<length; ++i) \
        if(self->data[i] == key) \
            return i; \
    return length; \
} \
\
size_t declname##_indexof_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<length; ++i) \
        if(comp(&self->data[i])) \
            return i; \
    return length; \
} \
\
size_t declname##_bindexof(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[length-1])) \
        return p - self->data; \
    return length; \
} \
\
size_t declname##_bindexof_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<length) \
        return index; \
    return length; \
} \
\
int declname##_contains(const declname* self, const type key) \
{ \
    for(int i = 0; i<length; ++i) \
        if(self->data[i] == key) \
        return 1; \
    return 0; \
} \
\
int declname##_contains_by(const declname* self, int(*comp)(const type*)) \
{ \
    for(int i = 0; i<length; ++i) \
        if(comp(&self->data[i])) \
            return 1; \
    return 0; \
} \
\
int declname##_bcontains(const declname* self, const type key) \
{ \
    type* p = bsearch(&key, self->data, length, sizeof(type), declname##_comparer); \
    if(self->data<=p && p<= &(self->data[length-1])) \
        return 1; \
    return 0; \
} \
\
int declname##_bcontains_by(const declname* self, const type* key, int(*comp)(const type*, const type*)) \
{ \
    int index = declname##_bsearch(self, key, comp); \
    if(0<=index && index<length) \
        return 1; \
    return 0; \
} \
\
void declname##_for_each(const declname* self, void(*f)(const type)) \
{ \
    for(int i =0; i<length; ++i) \
        f(self->data[i]); \
} \
\
void declname##_for_each_ptr(declname* self, void(*f)(type*)) \
{ \
    for(int i =0; i<length; ++i) \
        f(&self->data[i]); \
} \
\
declname make_##declname (void) \
{ \
    declname temp = \
    { \
        .get_length= declname##_get_length, \
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
        .for_each_ptr= declname##_for_each_ptr \
    }; \
    return temp; \
} \
\
\
/*이제부터 반복자 메서드 정의요*/ \
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
int declname##_iterator_equals(const declname##_iterator* self, const declname##_iterator* other) \
{ \
    return self->ptr == other->ptr; \
} \
\
declname##_iterator make_##declname##_iterator(type* p) \
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
} \
