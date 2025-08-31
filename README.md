# CGC Lang - C with Garbage Collection

## Overview

CGC Lang is a lightweight programming language implementation featuring a custom mark-and-sweep garbage collector. This project demonstrates core concepts in language runtime design, memory management, and virtual machine implementation.

## Features

- **Type System**: Support for primitive types (integers, floats, strings) and composite types (arrays, 3D vectors)
- **Memory Management**: Automatic garbage collection using a mark-and-sweep algorithm
- **Object Model**: Uniform object representation with polymorphic operations
- **Stack-based VM**: Simple virtual machine with stack frames for execution

## Technical Implementation

### Object System

The language provides a uniform object system with various data types:
- Primitive types: integers, floating-point numbers, strings
- Composite types: arrays, 3D vectors

All objects share a common structure that includes:
- Type information
- Garbage collection metadata
- Type-specific data storage

### Memory Management

The garbage collector uses a three-phase mark-and-sweep approach:
1. **Mark Phase**: Root objects in stack frames are marked
2. **Trace Phase**: References from marked objects are recursively traced
3. **Sweep Phase**: Unmarked objects are deallocated

This implementation demonstrates:
- Handling cyclic references
- Efficient object traversal
- Memory reclamation strategies

### Virtual Machine

The VM implementation includes:
- Stack-based execution model
- Frame-based scoping
- Object tracking and lifecycle management

## Code Organization

- **`cgc_object.h/c`**: Object model definition and operations
- **`stack.h/c`**: Generic stack implementation for the VM
- **`vm.h/c`**: Virtual machine and garbage collection implementation
- **`cgc_new.c`**: Object construction and initialization

## Building and Running
```bash
# Clone the repository
git clone https://github.com/lavis0/cgc_lang.git
cd cgc_lang

# Build the project
mkdir build && cd build
cmake ..
cmake --build
```

## Future Enhancements

- Parser and lexer for a concrete syntax
- JIT compilation for improved performance
- Additional data types and standard library
- Benchmarking and optimization of the garbage collector

## Educational Value

This project demonstrates several important concepts in programming language implementation:

- Memory management strategies in language runtimes
- Object representation and polymorphism
- Efficient data structure implementation
- Resource tracking and lifecycle management

## License

[LICENSE](LICENSE)

*Note: This is a demonstration project and not intended for production use. It was created to explore concepts in programming language implementation and memory management.*