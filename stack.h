//
// Created by joshua on 31/08/2025.
//

#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Stack {
	size_t count;
	size_t capacity;
	void **data;
} cgc_stack_t;

cgc_stack_t *stack_new(size_t capacity);

void stack_push(cgc_stack_t *stack, void *obj);
void *stack_pop(cgc_stack_t *stack);

void stack_free(cgc_stack_t *stack);
void stack_remove_nulls(cgc_stack_t *stack);

#endif //STACK_H
