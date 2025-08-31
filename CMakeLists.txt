cmake_minimum_required(VERSION 3.31)
project(cgc_lang C)

set(CMAKE_C_STANDARD 17)

add_library(cgc_lang STATIC
        stack.c
        stack.h
        cgc_object.h
        cgc_object.c
        cgc_new.c
        cgc_new.h
        vm.c
        vm.h)
