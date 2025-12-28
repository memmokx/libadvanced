#ifndef LIBAD_DEFINES_H
#define LIBAD_DEFINES_H

#include <stddef.h>
#include <stdint.h>

typedef intptr_t iptr;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef size_t usize;
typedef uintptr_t uptr;

typedef float f32;
typedef double f64;

#ifdef LIBAD_ALLOW_LIBC
# define INTERNAL_LIBAD_USE_LIBC
#endif

#endif
