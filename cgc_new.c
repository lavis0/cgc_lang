//
// Created by joshua on 31/08/2025.
//

#include "cgc_new.h"
#include <stdlib.h>
#include <string.h>

#include "cgc_object.h"
#include "vm.h"

cgc_object_t *_new_cgc_object(vm_t *vm) {
	cgc_object_t *obj = calloc(1, sizeof(cgc_object_t));
	if (obj == NULL) {
		return NULL;
	}

	obj->is_marked = false;

	vm_track_object(vm, obj);

	return obj;
}

cgc_object_t *new_cgc_array(vm_t *vm, const size_t size) {
	cgc_object_t *obj = _new_cgc_object(vm);
	if (obj == NULL) {
		return NULL;
	}

	cgc_object_t **elements = calloc(size, sizeof(cgc_object_t *));
	if (elements == NULL) {
		free(obj);
		return NULL;
	}

	obj->kind = ARRAY;
	obj->data.v_array = (cgc_array_t){.size = size, .elements = elements};

	return obj;
}

cgc_object_t *new_cgc_vector3(
	vm_t *vm, cgc_object_t *x, cgc_object_t *y, cgc_object_t *z
) {
	if (x == NULL || y == NULL || z == NULL) {
		return NULL;
	}

	cgc_object_t *obj = _new_cgc_object(vm);
	if (obj == NULL) {
		return NULL;
	}

	obj->kind = VECTOR3;
	obj->data.v_vector3 = (cgc_vector_t){.x = x, .y = y, .z = z};

	return obj;
}

cgc_object_t *new_cgc_integer(vm_t *vm, const int value) {
	cgc_object_t *obj = _new_cgc_object(vm);
	if (obj == NULL) {
		return NULL;
	}

	obj->kind = INTEGER;
	obj->data.v_int = value;

	return obj;
}

cgc_object_t *new_cgc_float(vm_t *vm, const float value) {
	cgc_object_t *obj = _new_cgc_object(vm);
	if (obj == NULL) {
		return NULL;
	}

	obj->kind = FLOAT;
	obj->data.v_float = value;
	return obj;
}

cgc_object_t *new_cgc_string(vm_t *vm, const char *value) {
	cgc_object_t *obj = _new_cgc_object(vm);
	if (obj == NULL) {
		return NULL;
	}

	const int len = strlen(value);
	char *dst = malloc(len + 1);
	if (dst == NULL) {
		free(obj);
		return NULL;
	}

	strcpy(dst, value);

	obj->kind = STRING;
	obj->data.v_string = dst;
	return obj;
}
