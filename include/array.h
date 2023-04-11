#ifndef C_STL_ARRAY_H
#define C_STL_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef int (*QsortCompare)(const void*, const void*);

// TypeName: type name 
// T: element type
// Length: Length of array
#define decl_array(TypeName, T, Length)                                                                                     \
                                                                                                                            \
    /* prototypes */                                                                                                        \
    struct TypeName;                                                                                                        \
    typedef struct TypeName TypeName;                                                                                       \
    struct TypeName##_iterator;                                                                                             \
    typedef struct TypeName##_iterator TypeName##_iterator;                                                                 \
                                                                                                                            \
    typedef int (*TypeName##_Compare)(const T *, const T *);                                                                \
    typedef int (*TypeName##_Find)(const T *);                                                                              \
                                                                                                                            \
    /* iterator of container */                                                                                             \
    struct TypeName##_iterator                                                                                              \
    {                                                                                                                       \
        T *ptr;                                                                                                             \
                                                                                                                            \
        /* iterate */                                                                                                       \
        void (*next)(TypeName##_iterator *);                                                                                \
        void (*prev)(TypeName##_iterator *);                                                                                \
                                                                                                                            \
        /* get value */                                                                                                     \
        T (*get)(const TypeName##_iterator *);                                                                              \
        T *(*get_ptr)(TypeName##_iterator *);                                                                               \
                                                                                                                            \
        /* value comparison */                                                                                              \
        bool (*equals)(const TypeName##_iterator *, const TypeName##_iterator *);                                           \
    };                                                                                                                      \
                                                                                                                            \
    /* method definition */                                                                                                 \
    void TypeName##_iterator_next(TypeName##_iterator *);                                                                   \
    void TypeName##_iterator_prev(TypeName##_iterator *);                                                                   \
    T TypeName##_iterator_get(const TypeName##_iterator *);                                                                 \
    T* TypeName##_iterator_get_ptr(TypeName##_iterator *);                                                                  \
    bool TypeName##_iterator_equals(const TypeName##_iterator *, const TypeName##_iterator *);                              \
    /* constructor function */                                                                                              \
    TypeName##_iterator new_##TypeName##_iterator(T *);                                                                     \
                                                                                                                            \
    /* container definition */                                                                                              \
    struct TypeName                                                                                                         \
    {                                                                                                                       \
        T data[Length];                                                                                                     \
                                                                                                                            \
        /* get size of array */                                                                                             \
        size_t (*size)(const TypeName *);                                                                                   \
                                                                                                                            \
        /* get element of array */                                                                                          \
        T (*get)(const TypeName *, size_t);                                                                                 \
        T *(*get_ptr)(TypeName *, size_t);                                                                                  \
        const T *(*get_cptr)(const TypeName *, size_t);                                                                     \
                                                                                                                            \
        /* Returns a copy of the array */                                                                                   \
        TypeName (*clone)(const TypeName *);                                                                                \
                                                                                                                            \
        /* iterator */                                                                                                      \
        TypeName##_iterator (*begin)(TypeName *);                                                                           \
        TypeName##_iterator (*end)(TypeName *);                                                                             \
                                                                                                                            \
        /* Returns an iterator of the position found after linear search */                                                 \
        TypeName##_iterator (*find)(const TypeName *, const T);                                                             \
        TypeName##_iterator (*find_by)(const TypeName *, int (*)(const T *));                                               \
                                                                                                                            \
        /* Returns the corresponding index after linear search */                                                           \
        size_t (*indexof)(const TypeName *, const T);                                                                       \
        size_t (*indexof_by)(const TypeName *, TypeName##_Find);                                                            \
                                                                                                                            \
        /* Check for inclusion by linear search */                                                                          \
        bool (*contains)(const TypeName *, const T);                                                                        \
        bool (*contains_by)(const TypeName *, TypeName##_Find);                                                             \
                                                                                                                            \
        /* Returns an iterator of the position found after binary search */                                                 \
        TypeName##_iterator (*bfind)(const TypeName *, const T);                                                            \
        TypeName##_iterator (*bfind_by)(const TypeName *, const T *, TypeName##_Compare);                                   \
                                                                                                                            \
        /* Returns the corresponding index after binary search */                                                           \
        size_t (*bindexof)(const TypeName *, const T);                                                                      \
        size_t (*bindexof_by)(const TypeName *, const T *, TypeName##_Compare);                                             \
                                                                                                                            \
        /* Check for inclusion with binary search */                                                                        \
        bool (*bcontains)(const TypeName *, const T);                                                                       \
        bool (*bcontains_by)(const TypeName *, const T *, TypeName##_Compare);                                              \
                                                                                                                            \
        /* Fill an array with its value or a pointer to a value */                                                          \
        void (*fill)(TypeName *, const T);                                                                                  \
        void (*fill_ptr)(TypeName *, const T *);                                                                            \
                                                                                                                            \
        /* sort */                                                                                                          \
        void (*sort)(TypeName *);                                                                                           \
        void (*sort_by)(TypeName *, TypeName##_Compare);                                                                    \
                                                                                                                            \
        /* Receive a callback function and run a range-based loop. */                                                       \
        void (*for_each)(const TypeName *, void (*)(const T));                                                              \
        void (*for_each_ptr)(TypeName *, void (*)(T *));                                                                    \
        void (*for_each_cptr)(const TypeName *, void (*)(const T *));                                                       \
    };                                                                                                                      \
                                                                                                                            \
    /* method prototype */                                                                                                  \
    size_t TypeName##_size(const TypeName *);                                                                               \
    T TypeName##_get(const TypeName *, size_t);                                                                             \
    T *TypeName##_get_ptr(TypeName *, size_t);                                                                              \
    const T *TypeName##_get_cptr(const TypeName *, size_t);                                                                 \
    TypeName TypeName##_clone(const TypeName *);                                                                            \
    TypeName##_iterator TypeName##_begin(TypeName *);                                                                       \
    TypeName##_iterator TypeName##_end(TypeName *);                                                                         \
    TypeName##_iterator TypeName##_find(const TypeName *, const T);                                                         \
    TypeName##_iterator TypeName##_find_by(const TypeName *, TypeName##_Find);                                              \
    size_t TypeName##_indexof(const TypeName *, const T);                                                                   \
    size_t TypeName##_indexof_by(const TypeName *, TypeName##_Find);                                                        \
    bool TypeName##_contains(const TypeName *, const T);                                                                    \
    bool TypeName##_contains_by(const TypeName *, TypeName##_Find);                                                         \
    TypeName##_iterator TypeName##_bfind(const TypeName *, const T);                                                        \
    TypeName##_iterator TypeName##_bfind_by(const TypeName *, const T *, TypeName##_Compare);                               \
    size_t TypeName##_bindexof(const TypeName *, const T);                                                                  \
    size_t TypeName##_bindexof_by(const TypeName *, const T *, TypeName##_Compare);                                         \
    bool TypeName##_bcontains(const TypeName *, const T);                                                                   \
    bool TypeName##_bcontains_by(const TypeName *, const T *, TypeName##_Compare);                                          \
    void TypeName##_fill(TypeName *, const T);                                                                              \
    void TypeName##_fill_ptr(TypeName *, const T *);                                                                        \
    void TypeName##_sort(TypeName *);                                                                                       \
    void TypeName##_sort_by(TypeName *, TypeName##_Compare);                                                                \
    void TypeName##_for_each(const TypeName *, void (*)(const T));                                                          \
    void TypeName##_for_each_ptr(TypeName *, void (*)(T *));                                                                \
    void TypeName##_for_each_cptr(const TypeName *, void (*)(const T *));                                                   \
    /* non-member functions prototype */                                                                                    \
    TypeName new_##TypeName(void);

// container definition
#define def_array(TypeName, T, Length)                                                                                      \
                                                                                                                            \
    size_t TypeName##_size(const TypeName *self)                                                                            \
    {                                                                                                                       \
        return Length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    T TypeName##_get(const TypeName *self, size_t index)                                                                    \
    {                                                                                                                       \
        return self->data[index];                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    T *TypeName##_get_ptr(TypeName *self, size_t index)                                                                     \
    {                                                                                                                       \
        return &(self->data[index]);                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    const T *TypeName##_get_cptr(const TypeName *self, size_t index)                                                        \
    {                                                                                                                       \
        return &(self->data[index]);                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    int TypeName##_comparer(const void *lhs, const void *rhs)                                                               \
    {                                                                                                                       \
        return *(T *)lhs - *(T *)rhs;                                                                                       \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_sort(TypeName *self)                                                                                    \
    {                                                                                                                       \
        qsort(self->data, Length, sizeof(T), (QsortCompare)TypeName##_comparer);                                            \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_sort_by(TypeName *self, TypeName##_Compare comp)                                                        \
    {                                                                                                                       \
        qsort(self->data, Length, sizeof(T), ((QsortCompare)comp));                                                         \
    }                                                                                                                       \
                                                                                                                            \
    TypeName TypeName##_clone(const TypeName *self)                                                                         \
    {                                                                                                                       \
        TypeName temp = new_##TypeName();                                                                                   \
        for (int i = 0; i < Length; ++i)                                                                                    \
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
        return new_##TypeName##_iterator(self->data + Length);                                                              \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_fill(TypeName *self, const T value)                                                                     \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            self->data[i] = value;                                                                                          \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_fill_ptr(TypeName *self, const T *value)                                                                \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            self->data[i] = *value;                                                                                         \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_find(const TypeName *self, const T key)                                                  \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return new_##TypeName##_iterator((T *)&(self->data[i]));                                                    \
                                                                                                                            \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_find_by(const TypeName *self, TypeName##_Find comp)                                      \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return new_##TypeName##_iterator((T *)&(self->data[i]));                                                    \
                                                                                                                            \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_bfind(const TypeName *self, const T key)                                                 \
    {                                                                                                                       \
        T *p = (T*)bsearch(&key, self->data, Length, sizeof(T), TypeName##_comparer);                                       \
        if (self->data <= p && p <= &(self->data[Length - 1]))                                                              \
            return new_##TypeName##_iterator(p);                                                                            \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    int TypeName##_bsearch(const TypeName *self, const T *key, TypeName##_Compare comp)                                     \
    {                                                                                                                       \
        int head = 0;                                                                                                       \
        int tail = Length - 1;                                                                                              \
        int middle;                                                                                                         \
                                                                                                                            \
        while (1)                                                                                                           \
        {                                                                                                                   \
            int comp_head = comp(key, &self->data[head]);                                                                   \
            int comp_tail = comp(key, &self->data[tail]);                                                                   \
            if (comp_head < 0 || comp_tail > 0)                                                                             \
                return Length;                                                                                              \
            if (comp_head == 0)                                                                                             \
                return head;                                                                                                \
            if (comp_tail == 0)                                                                                             \
                return tail;                                                                                                \
                                                                                                                            \
            middle = (tail - head) / 2;                                                                                     \
            int comp_mid = comp(key, &self->data[middle]);                                                                  \
            if (comp_mid == 0)                                                                                              \
                return middle;                                                                                              \
            else if (0 < comp_mid)                                                                                          \
                --tail, head = middle;                                                                                      \
            else                                                                                                            \
                ++head, tail = middle;                                                                                      \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator TypeName##_bfind_by(const TypeName *self, const T *key, TypeName##_Compare comp)                    \
    {                                                                                                                       \
        int index = TypeName##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < Length)                                                                                   \
            return new_##TypeName##_iterator((T *)&self->data[index]);                                                      \
        return self->end((TypeName *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_indexof(const TypeName *self, const T key)                                                            \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return i;                                                                                                   \
        return Length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_indexof_by(const TypeName *self, TypeName##_Find comp)                                                \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return i;                                                                                                   \
        return Length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_bindexof(const TypeName *self, const T key)                                                           \
    {                                                                                                                       \
        T *p = (T*)bsearch(&key, self->data, Length, sizeof(T), TypeName##_comparer);                                       \
        if (self->data <= p && p <= &(self->data[Length - 1]))                                                              \
            return p - self->data;                                                                                          \
        return Length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    size_t TypeName##_bindexof_by(const TypeName *self, const T *key, TypeName##_Compare comp)                              \
    {                                                                                                                       \
        int index = TypeName##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < Length)                                                                                   \
            return index;                                                                                                   \
        return Length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_contains(const TypeName *self, const T key)                                                             \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return 1;                                                                                                   \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_contains_by(const TypeName *self, TypeName##_Find comp)                                                 \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return 1;                                                                                                   \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_bcontains(const TypeName *self, const T key)                                                            \
    {                                                                                                                       \
        T *p = (T*)bsearch(&key, self->data, Length, sizeof(T), TypeName##_comparer);                                       \
        if (self->data <= p && p <= &(self->data[Length - 1]))                                                              \
            return 1;                                                                                                       \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_bcontains_by(const TypeName *self, const T *key, TypeName##_Compare comp)                               \
    {                                                                                                                       \
        int index = TypeName##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < Length)                                                                                   \
            return 1;                                                                                                       \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_for_each(const TypeName *self, void (*f)(const T))                                                      \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            f(self->data[i]);                                                                                               \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_for_each_ptr(TypeName *self, void (*f)(T *))                                                            \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
            f(&self->data[i]);                                                                                              \
    }                                                                                                                       \
                                                                                                                            \
    void TypeName##_for_each_cptr(const TypeName *self, void (*f)(const T *))                                               \
    {                                                                                                                       \
        for (int i = 0; i < Length; ++i)                                                                                    \
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
                .clone = TypeName##_clone,                                                                                  \
                .begin = TypeName##_begin,                                                                                  \
                .end = TypeName##_end,                                                                                      \
                .find = TypeName##_find,                                                                                    \
                .find_by = TypeName##_find_by,                                                                              \
                .indexof = TypeName##_indexof,                                                                              \
                .indexof_by = TypeName##_indexof_by,                                                                        \
                .contains = TypeName##_contains,                                                                            \
                .contains_by = TypeName##_contains_by,                                                                      \
                .bfind = TypeName##_bfind,                                                                                  \
                .bfind_by = TypeName##_bfind_by,                                                                            \
                .bindexof = TypeName##_bindexof,                                                                            \
                .bindexof_by = TypeName##_bindexof_by,                                                                      \
                .bcontains = TypeName##_bcontains,                                                                          \
                .bcontains_by = TypeName##_bcontains_by,                                                                    \
                .fill = TypeName##_fill,                                                                                    \
                .fill_ptr = TypeName##_fill_ptr,                                                                            \
                .sort = TypeName##_sort,                                                                                    \
                .sort_by = TypeName##_sort_by,                                                                              \
                .for_each = TypeName##_for_each,                                                                            \
                .for_each_ptr = TypeName##_for_each_ptr,                                                                    \
                .for_each_cptr = TypeName##_for_each_cptr};                                                                 \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
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
    T TypeName##_iterator_get(const TypeName##_iterator *self)                                                              \
    {                                                                                                                       \
        return *(self->ptr);                                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    T *TypeName##_iterator_get_ptr(TypeName##_iterator *self)                                                               \
    {                                                                                                                       \
        return self->ptr;                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    bool TypeName##_iterator_equals(const TypeName##_iterator *self, const TypeName##_iterator *other)                      \
    {                                                                                                                       \
        return self->ptr == other->ptr;                                                                                     \
    }                                                                                                                       \
                                                                                                                            \
    TypeName##_iterator new_##TypeName##_iterator(T *p)                                                                     \
    {                                                                                                                       \
        TypeName##_iterator it = {                                                                                          \
                .ptr = p,                                                                                                    \
                .next = TypeName##_iterator_next,                                                                            \
                .prev = TypeName##_iterator_prev,                                                                            \
                .get = TypeName##_iterator_get,                                                                              \
                .get_ptr = TypeName##_iterator_get_ptr,                                                                      \
                .equals = TypeName##_iterator_equals                                                                         \
        };                                                                                                                  \
                                                                                                                            \
        return it;                                                                                                          \
    }

#endif