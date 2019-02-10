#pragma once

#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define decl_stack(declname,type) \
\
struct declname; \
typedef struct declname declname; \
\
struct declname##_node; \
typedef struct declname##_node declname##_node; \
\
struct declname##_node \
{ \
	type data; \
	declname##_node *bptr; \
}; \
\
struct declname \
{ \
    declname##_node * const tail; \
	const size_t length; \
	\
	void  (*push)(declname*,type); \
	void (*push_ptr)(declname*, const type*); \
	void  (*pop)(declname*);  \
	type  (*top)(const declname*);  \
	type*  (*top_ptr)(declname*);  \
	const type* (*top_cptr)(const declname*);  \
	size_t (*size)(const declname*); \
	bool (*is_empty)(const declname*); \
	bool (*is_not_empty)(const declname*); \
	void (*clear)(declname*); \
}; \
\
void declname##_push(declname*,type); \
void declname##_push_ptr(declname*, const type*); \
void declname##_pop(declname*); \
type declname##_top(const declname*); \
type* declname##_top_ptr(declname*); \
const type* declname##_top_cptr(const declname*); \
size_t  declname##_size(const declname*); \
bool declname##_is_empty(const declname*); \
bool declname##_is_not_empty(const declname*); \
void declname##_clear(declname*); \
\
void declname##_push(declname* self,type d) \
{ \
	declname##_node *ptr = (declname##_node*)malloc(sizeof(declname##_node)); \
	ptr->bptr=self->tail; \
	ptr->data=d; \
	(*(declname##_node **)&self->tail) = ptr; \
	++ *(size_t*)&self->length; \
} \
void declname##_push_ptr(declname* self, const type* p) \
{ \
	declname##_node *ptr = (declname##_node*)malloc(sizeof(declname##_node)); \
	ptr->bptr=self->tail; \
	ptr->data=*p; \
	(*(declname##_node **)&self->tail) = ptr; \
	++ *(size_t*)&self->length; \
} \
\
void declname##_pop(declname* self) \
{ \
	assert(self->length!=0); \
	declname##_node* ptr=self->tail->bptr; \
	free(self->tail); \
	(*(declname##_node **)&self->tail) = ptr; \
	-- *(size_t*)&self->length; \
} \
\
type declname##_top(const declname* self) \
{ \
	assert(self->length!=0); \
	return self->tail->data; \
} \
\
type* declname##_top_ptr(declname* self) \
{ \
	assert(self->length!=0); \
	return &self->tail->data; \
} \
\
const type* declname##_top_cptr(const declname* self) \
{ \
	assert(self->length!=0); \
	return &self->tail->data; \
} \
\
size_t declname##_size(const declname* self) \
{ \
	return self->length; \
} \
\
bool declname##_is_empty(const declname* self) \
{ \
	return self->length == 0; \
} \
\
bool declname##_is_not_empty(const declname* self) \
{ \
	return self->length !=0; \
} \
\
void declname##_clear(declname* self) \
{ \
	while(declname##_is_not_empty(self)) \
		declname##_pop(self); \
} \
\
declname make_##declname(void); \
\
declname make_##declname(void) \
{ \
	declname temp = \
	{ \
		.push= declname##_push, \
		.push_ptr = declname##_push_ptr, \
		.pop= declname##_pop, \
		.top= declname##_top, \
		.top_ptr= declname##_top_ptr, \
		.top_cptr= declname##_top_cptr, \
		.is_empty= declname##_is_empty, \
		.is_not_empty= declname##_is_not_empty, \
		.size= declname##_size, \
		.clear= declname##_clear, \
		.tail=NULL, \
		.length=0 \
	}; \
	return temp; \
}