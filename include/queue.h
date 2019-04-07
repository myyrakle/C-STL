#pragma once

#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define decl_queue(declname,type) \
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
	declname##_node* next; \
}; \
\
struct declname \
{ \
	declname##_node *head; \
	declname##_node *tail; \
	size_t length; \
	\
	void (*push)(declname*,type); \
	void (*pop)(declname*); \
	size_t (*size)(const declname*); \
	bool (*is_empty)(const declname*); \
	bool (*is_not_empty)(const declname*); \
	type (*front)(const declname*); \
	type* (*front_ptr)(declname*); \
	const type* (*front_cptr)(const declname*); \
	void (*clear)(declname*); \
}; \
\
void declname##_push(declname*,type); \
void declname##_pop(declname*); \
size_t declname##_size(const declname*); \
bool declname##_is_empty(const declname*); \
bool declname##_is_not_empty(const declname*); \
type declname##_front(const declname*); \
type* declname##_front_ptr(declname*); \
const type* declname##_front_cptr(const declname*); \
void declname##_clear(declname*); \
\
declname new_##declname(void); \
\
void declname##_push(declname *self, type value) \
{ \
	declname##_node *node = (declname##_node*)malloc(sizeof(declname##_node)); \
	node->data = value; \
	node->next = NULL; \
	\
	if(self->tail !=NULL) \
		self->tail->next = node; \
	self->tail = node; \
	++self->length; \
	\
	if(self->length == 1) \
		self->head = self->tail; \
} \
\
void declname##_pop(declname* self)\
{ \
	assert(self->length!=0); \
	\
	declname##_node* temp = self->head; \
	self->head = self->head->next; \
	free(temp); \
	--self->length; \
} \
\
size_t declname##_size(const declname* self)\
{\
	return self->length; \
}\
\
bool declname##_is_empty(const declname* self)\
{ \
	return self->length==0; \
} \
\
bool declname##_is_not_empty(const declname* self)\
{ \
	return self->length!=0; \
} \
\
type declname##_front(const declname* self) \
{ \
	assert(self->length!=0); \
	return self->head->data; \
} \
\
type* declname##_front_ptr(declname* self) \
{\
	assert(self->length!=0); \
	return & self->head->data; \
}\
\
const type* declname##_front_cptr(const declname* self) \
{\
	assert(self->length!=0); \
	return & self->head->data; \
}\
\
void declname##_clear(declname* self) \
{ \
	while(0<self->length) \
		self->pop(self); \
	self->head = NULL; \
	self->tail = NULL; \
} \
\
declname new_##declname(void){ \
	static declname temp = \
	{ \
		.length=0, \
		.push=declname##_push, \
		.pop=declname##_pop, \
		.size=declname##_size, \
		.front=declname##_front, \
		.front_ptr = declname##_front_ptr, \
		.front_cptr =declname##_front_cptr, \
		.clear=declname##_clear, \
		.is_empty=declname##_is_empty, \
		.is_not_empty = declname##_is_not_empty, \
		.head=NULL, \
		.tail=NULL, \
	}; \
	return temp; \
}