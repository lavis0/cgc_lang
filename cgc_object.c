//
// Created by joshua on 31/08/2025.
//

#include "cgc_object.h"

#include <stdlib.h>
#include <string.h>

#include "cgc_new.h"

void cgc_object_free(cgc_object_t *obj) {
  switch (obj->kind) {
    case INTEGER:
    case FLOAT:
      break;
    case STRING:
      free(obj->data.v_string);
      break;
    case VECTOR3: {
      break;
    }
    case ARRAY: {
      const cgc_array_t *array = &obj->data.v_array;
      free(array->elements);

      break;
    }
  }

  free(obj);
}

bool cgc_array_set(const cgc_object_t *array, const size_t index, cgc_object_t *value) {
  if (array == NULL || value == NULL) {
    return false;
  }

  if (array->kind != ARRAY) {
    return false;
  }

  if (index >= array->data.v_array.size) {
    return false;
  }

  array->data.v_array.elements[index] = value;
  return true;
}

cgc_object_t *cgc_array_get(const cgc_object_t *array, const size_t index) {
  if (array == NULL) {
    return NULL;
  }

  if (array->kind != ARRAY) {
    return NULL;
  }

  if (index >= array->data.v_array.size) {
    return NULL;
  }

  // Get the value directly now (already checked size constraint)
  return array->data.v_array.elements[index];
}

cgc_object_t *cgc_add(vm_t *vm, cgc_object_t *a, cgc_object_t *b) {
  if (a == NULL || b == NULL) {
    return NULL;
  }

  switch (a->kind) {
  case INTEGER:
    switch (b->kind) {
    case INTEGER:
      return new_cgc_integer(vm, a->data.v_int + b->data.v_int);
    case FLOAT:
      return new_cgc_float(vm, (float)a->data.v_int + b->data.v_float);
    default:
      return NULL;
    }
  case FLOAT:
    switch (b->kind) {
    case FLOAT:
      return new_cgc_float(vm, a->data.v_float + b->data.v_float);
    default:
      return cgc_add(vm, b, a);
    }
  case STRING:
    switch (b->kind) {
    case STRING: {
      const int a_len = strlen(a->data.v_string);
      const int b_len = strlen(b->data.v_string);
      const int len = a_len + b_len + 1;
      char *dst = malloc(len * sizeof(char));
      dst[0] = '\0';

      strcat(dst, a->data.v_string);
      strcat(dst, b->data.v_string);

      cgc_object_t *obj = new_cgc_string(vm, dst);
      free(dst);

      return obj;
    }
    default:
      return NULL;
    }
  case VECTOR3:
    switch (b->kind) {
    case VECTOR3:
      return new_cgc_vector3(
          vm,
          cgc_add(vm, a->data.v_vector3.x, b->data.v_vector3.x),
          cgc_add(vm, a->data.v_vector3.y, b->data.v_vector3.y),
          cgc_add(vm, a->data.v_vector3.z, b->data.v_vector3.z)
      );
    default:
      return NULL;
    }
  case ARRAY:
    switch (b->kind) {
    case ARRAY: {
      const size_t a_len = a->data.v_array.size;
      const size_t b_len = b->data.v_array.size;
      const size_t length = a_len + b_len;

      cgc_object_t *array = new_cgc_array(vm, length);

      for (int i = 0; i < a_len; i++) {
        cgc_array_set(array, i, cgc_array_get(a, i));
      }

      for (int i = 0; i < b_len; i++) {
        cgc_array_set(array, i + a_len, cgc_array_get(b, i));
      }

      return array;
    }
    default:
      return NULL;
    }
  default:
    return NULL;
  }
}
