#pragma once

#include<stdlib.h>
#include<stdbool.h>

#define decl_queue(declname,type) \
\
struct declname; \
typedef struct declname declname; \
\
struct declname##_node; \
typedef struct declname##_node declname##_node; \
\
struct declname##_node{ \
	type data; \
	declname##_node* next; \
}; \
\
struct declname{ \
	declname##_node *head, *tail; \
	size_t dcnt; \
	\
	void (*push)(declname*,type); \
	void (*pop)(declname*); \
	size_t (*size)(declname*); \
	bool (*empty)(declname*); \
	type (*front)(declname*); \
	void (*clear)(declname*); \
}; \
\
void declname##_push(declname*,type); \
void declname##_pop(declname*); \
size_t declname##_size(declname*); \
bool declname##_empty(declname*); \
type declname##_front(declname*); \
void declname##_clear(declname*); \
\
void declname##_push(declname *self, type d){ \
	declname##_node *ptr = (declname##_node*)malloc(sizeof(declname##_node)); \
	ptr->data = d; \
	ptr->next = NULL; \
	self->tail->next = ptr; \
	self->tail = ptr; \
	++self->dcnt; \
} \
\
void declname##_pop(declname* self){ \
	declname##_node* ptr=self->head->next; \
	self->head->next = ptr->next; \
	free(ptr); \
	--self->dcnt; \
} \
\
size_t declname##_size(declname* self){\
	return self->dcnt; \
}\
\
bool declname##_empty(declname* self){ \
	return (self->dcnt!=0)?false:true; \
} \
\
type declname##_front(declname* self){ \
	return self->head->next->data; \
} \
\
void declname##_clear(declname* self){ \
	while(self->empty(self)==false){ \
		self->pop(self); \
	} \
} \
\
declname make_##declname(void); \
\
declname make_##declname(void){ \
	declname tmp = { \
		.dcnt=0, \
		.push=declname##_push, \
		.pop=declname##_pop, \
		.size=declname##_size, \
		.front=declname##_front, \
		.clear=declname##_clear, \
		.empty=declname##_empty, \
		.head=NULL, \
		.tail=NULL, \
	}; \
	tmp.head = (declname##_node*)malloc(sizeof(declname##_node)); \
	tmp.tail = tmp.head; \
	return tmp; \
}

