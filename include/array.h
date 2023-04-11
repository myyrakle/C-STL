#ifndef C_STL_ARRAY_H
#define C_STL_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

// TypeName: type name 
// T: element type
// Length: length of array
#define decl_array(TypeName, T, Length)                                                                                     \
                                                                                                                            \
    /* prototypes */                                                                                                        \
    struct TypeName;                                                                                                        \
    typedef struct TypeName TypeName;                                                                                       \
    struct TypeName##_iterator;                                                                                             \
    typedef struct TypeName##_iterator TypeName##_iterator;                                                                 \
                                                                                                                            \
    /* iterator of container */                                                                                             \
    struct TypeName##_iterator                                                                                              \
    {                                                                                                                       \
        type *ptr;                                                                                                          \
                                                                                                                            \
        /* iterate */                                                                                                       \
        void (*next)(TypeName##_iterator *);                                                                                \
        void (*prev)(TypeName##_iterator *);                                                                                \
                                                                                                                            \
        /* get value */                                                                                                     \
        type (*get)(const TypeName##_iterator *);                                                                           \
        type *(*get_ptr)(TypeName##_iterator *);                                                                            \
                                                                                                                            \
        /* value comparison */                                                                                              \
        bool (*equals)(const TypeName##_iterator *, const TypeName##_iterator *);                                           \
    };                                                                                                                      \
                                                                                                                            \
    /* method definition */                                                                                                 \
    void TypeName##_iterator_next(TypeName##_iterator *);                                                                   \
    void TypeName##_iterator_prev(TypeName##_iterator *);                                                                   \
    type TypeName##_iterator_get(const TypeName##_iterator *);                                                              \
    type *TypeName##_iterator_get_ptr(TypeName##_iterator *);                                                               \
    bool TypeName##_iterator_equals(const TypeName##_iterator *, const TypeName##_iterator *);                              \
    /* constructor function */                                                                                              \
    TypeName##_iterator new_##TypeName##_iterator(type *);                                                                  \
                                                                                                                            \
    /* container definition */                                                                                              \
    struct TypeName                                                                                                         \
    {                                                                                                                       \
        type data[length];                                                                                                  \
                                                                                                                            \
        /* get size of array */                                                                                             \
        size_t (*size)(const TypeName *);                                                                                   \
                                                                                                                            \
        /* get element of array */                                                                                          \
        type (*get)(const TypeName *, size_t);                                                                              \
        type *(*get_ptr)(TypeName *, size_t);                                                                               \
        const type *(*get_cptr)(const TypeName *, size_t);                                                                  \
                                                                                                                            \
        /* Returns a copy of the array */                                                                                   \
        TypeName (*clone)(const TypeName *);                                                                                \
                                                                                                                            \
        /* iterator */                                                                                                      \
        TypeName##_iterator (*begin)(TypeName *);                                                                           \
        TypeName##_iterator (*end)(TypeName *);                                                                             \
                                                                                                                            \
        /* Returns an iterator of the position found after linear search */                                                 \
        TypeName##_iterator (*find)(const TypeName *, const type);                                                          \
        TypeName##_iterator (*find_by)(const TypeName *, int (*)(const type *));                                            \
                                                                                                                            \
        /* Returns the corresponding index after linear search */                                                           \
        size_t (*indexof)(const TypeName *, const type);                                                                    \
        size_t (*indexof_by)(const TypeName *, int (*)(const type *));                                                      \
                                                                                                                            \
        /* Check for inclusion by linear search */                                                                          \
        bool (*contains)(const TypeName *, const type);                                                                     \
        bool (*contains_by)(const TypeName *, int (*)(const type *));                                                       \
                                                                                                                            \
        /* Returns an iterator of the position found after binary search */                                                 \
        TypeName##_iterator (*bfind)(const TypeName *, const type);                                                         \
        TypeName##_iterator (*bfind_by)(const TypeName *, const type *, int (*)(const type *, const type *));               \
                                                                                                                            \
        /* Returns the corresponding index after binary search */                                                           \
        size_t (*bindexof)(const TypeName *, const type);                                                                   \
        size_t (*bindexof_by)(const TypeName *, const type *, int (*)(const type *, const type *));                         \
                                                                                                                            \
        /* Check for inclusion with binary search */                                                                        \
        bool (*bcontains)(const TypeName *, const type);                                                                    \
        bool (*bcontains_by)(const TypeName *, const type *, int (*)(const type *, const type *));                          \
                                                                                                                            \
        /* Fill an array with its value or a pointer to a value */                                                          \
        void (*fill)(TypeName *, const type);                                                                               \
        void (*fill_ptr)(TypeName *, const type *);                                                                         \
                                                                                                                            \
        /* sort */                                                                                                          \
        void (*sort)(TypeName *);                                                                                           \
        void (*sort_by)(TypeName *, int (*)(const type *, const type *));                                                   \
                                                                                                                            \
        /* Receive a callback function and run a range-based loop. */                                                       \
        void (*for_each)(const TypeName *, void (*)(const type));                                                           \
        void (*for_each_ptr)(TypeName *, void (*)(type *));                                                                 \
        void (*for_each_cptr)(const TypeName *, void (*)(const type *));                                                    \
    };                                                                                                                      \
                                                                                                                            \
    /* method prototype */                                                                                                  \
    size_t TypeName##_size(const TypeName *);                                                                               \
    type TypeName##_get(const TypeName *, size_t);                                                                          \
    type *TypeName##_get_ptr(TypeName *, size_t);                                                                           \
    const type *TypeName##_get_cptr(const TypeName *, size_t);                                                              \
    TypeName TypeName##_clone(const TypeName *);                                                                            \
    TypeName##_iterator TypeName##_begin(TypeName *);                                                                       \
    TypeName##_iterator TypeName##_end(TypeName *);                                                                         \
    TypeName##_iterator TypeName##_find(const TypeName *, const type);                                                      \
    TypeName##_iterator TypeName##_find_by(const TypeName *, int (*)(const type *));                                        \
    size_t TypeName##_indexof(const TypeName *, const type);                                                                \
    size_t TypeName##_indexof_by(const TypeName *, int (*)(const type *));                                                  \
    bool TypeName##_contains(const TypeName *, const type);                                                                 \
    bool TypeName##_contains_by(const TypeName *, int (*)(const type *));                                                   \
    TypeName##_iterator TypeName##_bfind(const TypeName *, const type);                                                     \
    TypeName##_iterator TypeName##_bfind_by(const TypeName *, const type *, int (*)(const type *, const type *));           \
    size_t TypeName##_bindexof(const TypeName *, const type);                                                               \
    size_t TypeName##_bindexof_by(const TypeName *, const type *, int (*)(const type *, const type *));                     \
    bool TypeName##_bcontains(const TypeName *, const type);                                                                \
    bool TypeName##_bcontains_by(const TypeName *, const type *, int (*)(const type *, const type *));                      \
    void TypeName##_fill(TypeName *, const type);                                                                           \
    void TypeName##_fill_ptr(TypeName *, const type *);                                                                     \
    void TypeName##_sort(TypeName *);                                                                                       \
    void TypeName##_sort_by(TypeName *, int (*)(const type *, const type *));                                               \
    void TypeName##_for_each(const TypeName *, void (*)(const type));                                                       \
    void TypeName##_for_each_ptr(TypeName *, void (*)(type *));                                                             \
    void TypeName##_for_each_cptr(const TypeName *, void (*)(const type *));                                                \
    /* non-member functions prototype */                                                                                    \
    TypeName new_##TypeName(void);

// container definition
#define def_array(TypeName, type, length)                                                                                  \
    /*배열 메서드 정의.*/                                                                                            \
    size_t TypeName##_size(const TypeName *self)                                                                            \
    {                                                                                                                       \
        return length;                                                                                                      \
    }                                                                                                                       \
    type TypeName##_get(const TypeName *self, size_t index)                                                                 \
    {                                                                                                                       \
        return self->data[index];                                                                                           \
    }                                                                                                                       \
    type *TypeName##_get_ptr(TypeName *self, size_t index)                                                                  \
    {                                                                                                                       \
        return &(self->data[index]);                                                                                        \
    }                                                                                                                       \
    const type *TypeName##_get_cptr(const TypeName *self, size_t index)                                                     \
    {                                                                                                                       \
        return &(self->data[index]);                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    int TypeName##_comparer(const void *lhs, const void *rhs)                                                               \
    {                                                                                                                       \
        return *(type *)lhs - *(type *)rhs;                                                                                 \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_sort(TypeName *self)                                                                                    \
    {                                                                                                                       \
        qsort(self->data, length, sizeof(type), TypeName##_comparer);                                                       \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_sort_by(TypeName *self, int (*comp)(const type *, const type *))                                        \
    {                                                                                                                       \
        qsort(self->data, length, sizeof(type), (int (*)(const void *, const void *))comp);                                 \
    }                                                                                                                       \
                                                                                                                            \
    TypeName TypeName##_clone(const TypeName *self)                                                                         \
    {                                                                                                                       \
        TypeName temp = new_##TypeName();                                                                                   \
        for (int i = 0; i < length; ++i)                                                                                    \
            temp.data[i] = self->data[i];                                                                                   \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_begin(TypeName *self)                                                                    \
    {                                                                                                                       \
        return new_##TypeName##_iterator(self->data);                                                                       \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_end(TypeName *self)                                                                      \
    {                                                                                                                       \
        return new_##TypeName##_iterator(self->data + length);                                                              \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_fill(TypeName *self, const type value)                                                                  \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            self->data[i] = value;                                                                                          \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_fill_ptr(TypeName *self, const type *value)                                                             \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            self->data[i] = *value;                                                                                         \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_find(const TypeName *self, const type key)                                               \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return new_##TypeName##_iterator((type *)&(self->data[i]));                                                 \
                                                                                                                            \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_find_by(const TypeName *self, int (*comp)(const type *))                                 \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return new_##TypeName##_iterator((type *)&(self->data[i]));                                                 \
                                                                                                                            \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_bfind(const TypeName *self, const type key)                                              \
    {                                                                                                                       \
        type *p = bsearch(&key, self->data, length, sizeof(type), TypeName##_comparer);                                     \
        if (self->data <= p && p <= &(self->data[length - 1]))                                                              \
            return new_##TypeName##_iterator(p);                                                                            \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    int TypeName##_bsearch(const TypeName *self, const type *key, int (*comp)(const type *, const type *))                  \
    {                                                                                                                       \
        int head = 0;                                                                                                       \
        int tail = length - 1;                                                                                              \
        int middle;                                                                                                         \
                                                                                                                            \
        while (1)                                                                                                           \
        {                                                                                                                   \
            int comp_head = comp(key, &self->data[head]);                                                                   \
            int comp_tail = comp(key, &self->data[tail]);                                                                   \
            if (comp_head < 0 || comp_tail > 0)                                                                             \
                return length;                                                                                              \
            if (comp_head == 0)                                                                                             \
                return head;                                                                                                \
            if (comp_tail == 0)                                                                                             \
                return tail;                                                                                                \
                                                                                                                            \
            middle = (tail - head) / 2;                                                                                     \
            int comp_mid = comp(key, &self->data[middle]);                                                                  \
            if (comp_mid == 0)                                                                                              \
                return middle;                                                                                              \
            else if (0 < comp_mid) /*key가 중간치보다 큼*/                                                           \
                --tail, head = middle;                                                                                      \
            else /*key가 중간치보다 작음*/                                                                          \
                ++head, tail = middle;                                                                                      \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_bfind_by(const TypeName *self, const type *key, int (*comp)(const type *, const type *)) \
    {                                                                                                                       \
        int index = TypeName##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < length)                                                                                   \
            return new_##TypeName##_iterator((type *)&self->data[index]);                                                   \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_indexof(const TypeName *self, const type key)                                                         \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return i;                                                                                                   \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_indexof_by(const TypeName *self, int (*comp)(const type *))                                           \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return i;                                                                                                   \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_bindexof(const TypeName *self, const type key)                                                        \
    {                                                                                                                       \
        type *p = bsearch(&key, self->data, length, sizeof(type), TypeName##_comparer);                                     \
        if (self->data <= p && p <= &(self->data[length - 1]))                                                              \
            return p - self->data;                                                                                          \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_bindexof_by(const TypeName *self, const type *key, int (*comp)(const type *, const type *))           \
    {                                                                                                                       \
        int index = TypeName##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < length)                                                                                   \
            return index;                                                                                                   \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_contains(const TypeName *self, const type key)                                                          \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return 1;                                                                                                   \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_contains_by(const TypeName *self, int (*comp)(const type *))                                            \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return 1;                                                                                                   \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_bcontains(const TypeName *self, const type key)                                                         \
    {                                                                                                                       \
        type *p = bsearch(&key, self->data, length, sizeof(type), TypeName##_comparer);                                     \
        if (self->data <= p && p <= &(self->data[length - 1]))                                                              \
            return 1;                                                                                                       \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_bcontains_by(const TypeName *self, const type *key, int (*comp)(const type *, const type *))            \
    {                                                                                                                       \
        int index = TypeName##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < length)                                                                                   \
            return 1;                                                                                                       \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_for_each(const TypeName *self, void (*f)(const type))                                                   \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            f(self->data[i]);                                                                                               \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_for_each_ptr(TypeName *self, void (*f)(type *))                                                         \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            f(&self->data[i]);                                                                                              \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_for_each_cptr(const TypeName *self, void (*f)(const type *))                                            \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            f(&self->data[i]);                                                                                              \
    }                                                                                                                       \
                                                                                                                            \
    TypeName new_##TypeName(void)                                                                                           \
    {                                                                                                                       \
        static TypeName temp =                                                                                              \
            {                                                                                                               \
                .size = TypeName##_size,                                                                                    \
                .get = TypeName##_get,                                                                                      \
                .get_ptr = TypeName##_get_ptr,                                                                              \
                .get_cptr = TypeName##_get_cptr,                                                                            \
                .sort = TypeName##_sort,                                                                                    \
                .sort_by = TypeName##_sort_by,                                                                              \
                .clone = TypeName##_clone,                                                                                  \
                .begin = TypeName##_begin,                                                                                  \
                .end = TypeName##_end,                                                                                      \
                .fill = TypeName##_fill,                                                                                    \
                .fill_ptr = TypeName##_fill_ptr,                                                                            \
                .find = TypeName##_find,                                                                                    \
                .find_by = TypeName##_find_by,                                                                              \
                .bfind = TypeName##_bfind,                                                                                  \
                .bfind_by = TypeName##_bfind_by,                                                                            \
                .indexof = TypeName##_indexof,                                                                              \
                .indexof_by = TypeName##_indexof_by,                                                                        \
                .bindexof = TypeName##_bindexof,                                                                            \
                .bindexof_by = TypeName##_bindexof_by,                                                                      \
                .contains = TypeName##_contains,                                                                            \
                .contains_by = TypeName##_contains_by,                                                                      \
                .bcontains = TypeName##_bcontains,                                                                          \
                .bcontains_by = TypeName##_bcontains_by,                                                                    \
                .for_each = TypeName##_for_each,                                                                            \
                .for_each_ptr = TypeName##_for_each_ptr,                                                                    \
                .for_each_cptr = TypeName##_for_each_cptr};                                                                 \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    /*반복자 메서드 정의*/                                                                                          \
    void TypeName##_iterator_next(TypeName##_iterator *self)                                                                \
    {                                                                                                                       \
        ++(self->ptr);                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_iterator_prev(TypeName##_iterator *self)                                                                \
    {                                                                                                                       \
        --(self->ptr);                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    type TypeName##_iterator_get(const TypeName##_iterator *self)                                                           \
    {                                                                                                                       \
        return *(self->ptr);                                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    type *TypeName##_iterator_get_ptr(TypeName##_iterator *self)                                                            \
    {                                                                                                                       \
        return self->ptr;                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_iterator_equals(const TypeName##_iterator *self, const TypeName##_iterator *other)                      \
    {                                                                                                                       \
        return self->ptr == other->ptr;                                                                                     \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator new_##TypeName##_iterator(type *p)                                                                  \
    {                                                                                                                       \
        TypeName##_iterator it =                                                                                            \
            {                                                                                                               \
                p,                                                                                                          \
                TypeName##_iterator_next,                                                                                   \
                TypeName##_iterator_prev,                                                                                   \
                TypeName##_iterator_get,                                                                                    \
                TypeName##_iterator_get_ptr,                                                                                \
                TypeName##_iterator_equals};                                                                                \
        return it;                                                                                                          \
    }

#endif
