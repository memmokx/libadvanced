#ifndef AD_COLLECTIONS_H
#define AD_COLLECTIONS_H

#include <stdlib.h>
#include "defines.h"

typedef struct {
  usize len;
  usize cap;
  char ptr[];
} vector_header;

#define _ad_vector_header(v) ((vector_header*)(v) - 1)
#define _ad_vector_null_trap(v) (__builtin_trap(), *(typeof(v))0)

void* ad_vector_new(usize elem_size, usize capacity);
bool ad_vector_reserve(void** header, usize elem_size, usize additional);

#define vector(T) T*
#define vector_new(T, capacity) ad_vector_new(sizeof(T), capacity)

#define vector_len(v) ((v) ? _ad_vector_header(v)->len : 0)
#define vector_cap(v) ((v) ? _ad_vector_header(v)->cap : 0)
#define vector_clear(v) ((v) ? _ad_vector_header(v)->len = 0 : 0)
#define vector_is_empty(v) (vector_len(v) == 0)

#define vector_last(v) \
  (vector_len(v) > 0 ? v[vector_len(v) - 1] : _ad_vector_null_trap(v))
#define vector_last_ref(v) (vector_len(v) > 0 ? &v[vector_len(v) - 1] : nullptr)
#define vector_at_ref(v, i) ((i) < vector_len(v) ? &v[i] : nullptr)

#define vector_reserve(v, n) (ad_vector_reserve((void**)&v), sizeof(*v), n)
#define vector_push(v, value)                             \
  (ad_vector_reserve((void**)&v, sizeof(*v), 1)           \
       ? (v[_ad_vector_header(v)->len++] = (value), true) \
       : false)
#define vector_pop(v) \
  (vector_len(v) > 0 ? v[--_ad_vector_header(v)->len] : _ad_vector_null_trap(v))
#define vector_destroy(v) ((v) ? (free(_ad_vector_header(v)), v = nullptr) : (void)0)

#endif
