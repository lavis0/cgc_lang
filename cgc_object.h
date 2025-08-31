//
// Created by joshua on 31/08/2025.
//

#ifndef CGC_OBJECT_H
#define CGC_OBJECT_H

#include <stdbool.h>

#include "stack.h"

typedef struct CgcObject cgc_object_t;

typedef struct {
	size_t size;
	cgc_object_t **elements;
} cgc_array_t;

typedef struct {
	cgc_object_t *x;
	cgc_object_t *y;
	cgc_object_t *z;
} cgc_vector_t;

typedef enum CgcObjectKind {
	INTEGER,
	FLOAT,
	STRING,
	VECTOR3,
	ARRAY,
  } cgc_object_kind_t;

typedef union CgcObjectData {
	int v_int;
	float v_float;
	char *v_string;
	cgc_vector_t v_vector3;
	cgc_array_t v_array;
} cgc_object_data_t;

typedef struct CgcObject {
	bool is_marked;

	cgc_object_kind_t kind;
	cgc_object_data_t data;
} cgc_object_t;

void cgc_object_free(cgc_object_t *obj);

bool cgc_array_set(const cgc_object_t *array, size_t index, cgc_object_t *value);
cgc_object_t *cgc_array_get(const cgc_object_t *array, size_t index);

#endif //CGC_OBJECT_H
