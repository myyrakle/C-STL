#pragma once

#include<stdlib.h>
#include<stdbool.h>

#define decl_stack(declname,type) \
\
struct declname; \
typedef struct declname declname; \
\
struct declname##_node; \
typedef struct declname##_node declname##_node; \
\
struct declname##_node{ \
	type data; \
	declname##_node *bptr; \
}; \
\
struct declname \
{ \
	declname##_node *head, *tail; \
	size_t dcnt; \
	\
	void  (*push)(declname*,type); \
	void  (*pop)(declname*);  \
	type  (*top)(const declname*);  \
	size_t (*size)(const declname*); \
	bool  (*empty)(const declname*); \
}; \
\
void declname##_push(declname*,type); \
void declname##_pop(declname*); \
type declname##_top(const declname*); \
size_t  declname##_size(const declname*); \
bool declname##_empty(const declname*); \
\
void declname##_push(declname* self,type d){ \
	declname##_node *ptr = (declname##_node*)malloc(sizeof(declname##_node)); \
	ptr->bptr=self->tail; \
	ptr->data=d; \
	self->tail=ptr; \
	++self->dcnt; \
} \
\
void declname##_pop(declname* self){ \
	declname##_node* ptr=self->tail->bptr; \
	free(self->tail); \
	self->tail=ptr; \
	--self->dcnt; \
} \
\
type declname##_top(const declname* self){ \
	return self->tail->data; \
} \
\
size_t declname##_size(const declname* self){ \
	return self->dcnt; \
} \
\
bool declname##_empty(const declname* self){ \
	return self->dcnt?false:true; \
} \
\
declname make_##declname(void){ \
	declname temp = { \
		.push= declname##_push, \
		.pop= declname##_pop, \
		.top= declname##_top, \
		.empty= declname##_empty, \
		.size= declname##_size, \
		.head=NULL, \
		.tail=NULL, \
	}; \
	temp.head=(declname##_node*)malloc(sizeof(declname##_node)); \
	temp.tail=temp.head; \
	return temp; \
}
