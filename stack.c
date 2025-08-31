//
// Created by joshua on 31/08/2025.
//

#include "stack.h"

#include <stdlib.h>

void stack_push(cgc_stack_t *stack, void *obj) {
	if (stack->count == stack->capacity) {
		stack->capacity *= 2;
		stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
		if (stack->data == NULL) {
			exit(1);
		}
	}

	stack->data[stack->count] = obj;
	stack->count++;
}

void *stack_pop(cgc_stack_t *stack) {
	if (stack->count == 0) {
		return NULL;
	}

	stack->count--;
	return stack->data[stack->count];
}

void stack_free(cgc_stack_t *stack) {
	if (stack == NULL) {
		return;
	}

	if (stack->data != NULL) {
		free(stack->data);
	}

	free(stack);
}

void stack_remove_nulls(cgc_stack_t *stack) {
	size_t new_count = 0;

	// Iterate through the stack and compact non-NULL pointers.
	for (size_t i = 0; i < stack->count; ++i) {
		if (stack->data[i] != NULL) {
			stack->data[new_count++] = stack->data[i];
		}
	}

	// Update the count to reflect the new number of elements.
	stack->count = new_count;

	// Optionally, you might want to zero out the remaining slots.
	for (size_t i = new_count; i < stack->capacity; ++i) {
		stack->data[i] = NULL;
	}
}

cgc_stack_t *stack_new(const size_t capacity) {
	cgc_stack_t *stack = malloc(sizeof(cgc_stack_t));
	if (stack == NULL) {
		return NULL;
	}

	stack->count = 0;
	stack->capacity = capacity;
	stack->data = malloc(stack->capacity * sizeof(void *));
	if (stack->data == NULL) {
		free(stack);
		return NULL;
	}

	return stack;
}

