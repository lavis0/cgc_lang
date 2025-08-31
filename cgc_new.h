//
// Created by joshua on 31/08/2025.
//

#ifndef CGC_NEW_H
#define CGC_NEW_H

#include "cgc_object.h"
#include "vm.h"

cgc_object_t *new_cgc_integer(vm_t *vm, int value);
cgc_object_t *new_cgc_float(vm_t *vm, float value);
cgc_object_t *new_cgc_string(vm_t *vm, const char *value);
cgc_object_t *new_cgc_vector3(
	vm_t *vm, cgc_object_t *x, cgc_object_t *y, cgc_object_t *z
);
cgc_object_t *new_cgc_array(vm_t *vm, size_t size);


#endif //CGC_NEW_H
