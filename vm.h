//
// Created by joshua on 31/08/2025.
//

#ifndef VM_H
#define VM_H

#include "cgc_object.h"
#include "stack.h"

typedef struct VirtualMachine {
	// stack frames: cgc_stack_t frame_t
	cgc_stack_t *frames;

	// These are the rest of the objects: cgc_stack_t cgc_object_t
	cgc_stack_t *objects;
} vm_t;

typedef struct StackFrame {
	cgc_stack_t *references;
} frame_t;

/// Main functions for garbage collection.
void mark(const vm_t *vm);
void trace(const vm_t *vm);
void sweep(vm_t *vm);

void vm_collect_garbage(vm_t *vm);

/// Helper functions for `trace`
void trace_blacken_object(cgc_stack_t *gray_objects, const cgc_object_t *ref);
void trace_mark_object(cgc_stack_t *gray_objects, cgc_object_t *ref);

/// Already implemented
vm_t *vm_new();
void vm_free(vm_t *vm);
void vm_track_object(vm_t *vm, cgc_object_t *obj);

frame_t *vm_new_frame(vm_t *vm);
void vm_frame_push(vm_t *vm, frame_t *frame);
frame_t *vm_frame_pop(vm_t *vm);

void frame_free(frame_t *frame);

// Marks the object as referenced in the current stack frame.
void frame_reference_object(const frame_t *frame, cgc_object_t *obj);

#endif //VM_H
